#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "speaknum_int.h"

static int speak(char *str, char *file)
{
#if SPEAK_PRINT == true
    printf(" %s", str);
#endif

#if SPEAK_PLAY_FROM_FILE == true

    // Currently linux 'system' command is used to play the wav file
    // In other environment, this might need to be done by the C program itself,
    // i.e. read the WAV file and output it to the speaker 
    char cmd[CMDSZ];
    cmd[CMDSZ-1] = '\0';
    snprintf(cmd, CMDSZ-1, "%s %s/%s", PCM_PLAY_CMD, PCM_FILE_DIR, file);
    //printf("CMD=%s\n", cmd);  // DBG
    system(cmd);
#endif

    return 0;
}

static int speak_digit(int n)
{
    if (n > 9)    // Error input
    {
        printf("ERROR: %s: bad input: %d\n", __FUNCTION__, n);
        return -1;
    }
    speak(digits.str[n], digits.file[n]);

    return 0;
}

static int speak_10to19(int n) 
{
    if (n > 19)    // Error input
    {
        printf("ERROR: %s: bad input: %d\n", __FUNCTION__, n);
        return -1;
    }
    speak(num_10to19.str[n-10], num_10to19.file[n-10]);
    return 0;
};

static int speak_20to90(int n) 
{
    if (n > 9)    // Error input
    {
        printf("ERROR: %s: bad input: %d\n", __FUNCTION__, n);
        return -1;
    }
    speak(tens.str[n], tens.file[n]);
    return 0;
};

static int speak_hundreds(int n) 
{
    speak_number(n);
    speak(HUNDRED, HUNDRED_WAV);

    return 0;
};

static int speak_thousands(int n) 
{
    speak_number(n);
    speak(THOUSAND, THOUSAND_WAV);
    
    return 0;
};

int speak_rupees() 
{
    speak(RUPEES, RUPEES_WAV);

    return 0;
};

int speak_paise() 
{
    speak(PAISE, PAISE_WAV);

    return 0;
};

int speak_digits(int n)
{
    int totaldigits = floor(log10((double)n)) + 1; // number of digits in this number
    int digits = totaldigits;   // save
    int msd;    // most significant digit in a decimal number
    int power;  // 10 raised to the power of number of digits in a number

    /*
        To extract the digits from the number starting from the highest position.
        e.g. n = 345
        digits = 3
        power = 100

        msd = 345/100 = 3
        output the number 3
        remove the msd by
        n = n - (msd*power) i.e. n = 345 - (3 * 100) = 45
        recalculate no of digits = 2
        Continue to loop until all 3 digits are output  
    */
    for (int i=0; i<totaldigits; i++)
    {
      //printf("X=%d, digits=%d\n", x, digits);
      power = (int)pow(10.0, digits-1); 
      msd = n/power;
      //printf("power = %d,msd = %d\n", power, (int)msd);
      speak_digit(msd);

      n = n - (msd*power);
      digits = digits-1;
    }
    return 0;
}

int speak_number(int n)
{
    printf("\n%s(%d):", __FUNCTION__, n);

    if (n == 0) {
        speak_digit(0);
        return 0;
    }

    if (n > MAX_READ_NUM) // Beyond this number, let's read digit by digit
    {
        speak_digits(n);
        return 0;
    }

    int th = n / 1000;  // Thousands
    if (th > 0)
        speak_thousands(th);
    
    n = n - (th*1000); // Remove thousands and beyond

    int hu = n / 100;  // Hundreds
    if (hu > 0)
        speak_hundreds(hu);

    n = n - (hu*100);  // Remove hundreds

    int te = n / 10; // Tens

    if (te > 1)     // 20, 30,...90 etc
    {
        speak_20to90(te);
        // Speak the unit place
        n = n - (te * 10);  // Remove tens     
        if (n > 0)
            speak_digit(n);

    } else if (te == 1)   // 10 to 19 
    {
        speak_10to19(n);
    } else // 0 to 9 digits
    {
        // Speak the unit place
        n = n - (te * 10);  // Remove tens     
        if (n > 0)
            speak_digit(n);
    
    }
    return 0;
}



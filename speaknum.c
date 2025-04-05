#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "speaknum.h"


static int speak(char *s)
{
    printf(" %s", s);
    return 0;
}

static int speak_digit(int n)
{
    if (n>9)    // Error input
    {
        printf("ERROR: %s: bad input: %d\n", __FUNCTION__, n);
        return -1;
    }
    speak(digits.num[n]);

    return 0;
}



static int speak_10to19(int n) 
{
    if (n>19)    // Error input
    {
        printf("ERROR: %s: bad input: %d\n", __FUNCTION__, n);
        return -1;
    }
    speak(num_10to19.num[n-10]);
    return 0;
};

static int speak_20to90(int n) 
{
    if (n>9)    // Error input
    {
        printf("ERROR: %s: bad input: %d\n", __FUNCTION__, n);
        return -1;
    }
    speak(tens.num[n]);
    return 0;
};

static int speak_hundreds(int n) 
{
    speak_number(n);
    speak(HUNDRED);

    return 0;
};

static int speak_thousands(int n) 
{
    speak_number(n);
    speak(THOUSAND);
    
    return 0;
};

#if 0
// In case of text print newline. In case of speech, maybe a beep?
static int speak_done()
{
    printf("\n");  

    return 0;
}
#endif

int speak_rupees() 
{
    speak(RUPEES);
//    speak_done();
    return 0;
};

int speak_paisa() 
{
    speak(PAISA);
//    speak_done();
    return 0;
};

int speak_digits(int n)
{
    int totaldigits = floor(log10((double)n)) + 1;
    int digits = totaldigits;
    int lsb;
    int power;

    for (int i=0; i<totaldigits; i++)
    {
      //printf("X=%d, digits=%d\n", x, digits);
      power = (int)pow(10.0, digits-1);
      lsb = n/power;
      //printf("power = %d,lsb = %d\n", power, (int)lsb);
      speak_digit(lsb);

      n = n - (lsb*power);
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

// Test driver
int main()
{
    printf("\n");
    speak_number(0); speak_rupees();
    speak_number(8); speak_rupees();
    speak_number(9); speak_rupees();
    speak_number(10); speak_rupees();
    speak_number(19); speak_rupees();
    speak_number(20); speak_rupees();
    speak_number(21); speak_rupees();
    speak_number(29); speak_rupees();
    speak_number(80); speak_rupees();
    speak_number(81); speak_rupees();
    speak_number(89); speak_rupees();
    speak_number(90); speak_rupees();
    speak_number(99); speak_rupees();
    speak_number(100); speak_rupees();
    speak_number(101); speak_rupees();
    speak_number(109); speak_rupees();
    speak_number(125); speak_rupees();
    speak_number(199); speak_rupees();
    speak_number(200); speak_rupees();
    speak_number(250); speak_rupees();
    speak_number(990); speak_rupees();
    speak_number(999); speak_rupees();
    speak_number(1000); speak_rupees();
    speak_number(1199); speak_rupees();
    speak_number(1200); speak_rupees();
    speak_number(1250); speak_rupees();
    speak_number(1990); speak_rupees();
    speak_number(1999); speak_rupees();
    speak_number(5289); speak_rupees();
    speak_number(9000); speak_rupees();
    speak_number(9199); speak_rupees();
    speak_number(9999); speak_rupees();
    speak_number(10000); speak_rupees();
    speak_number(99999); speak_rupees();
    speak_number(98765432); speak_rupees();

    printf("\n");
    speak_digits(25);
    speak_paisa();

    speak_number(50);
    speak_paisa();

    printf("\n");

    return 0;
}

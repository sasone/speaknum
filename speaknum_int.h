#ifndef _SPEAKNUM_INT_H_
#define _SPEAKNUM_INT_H_


// SPEAK_PRINT optin enables to print out the digits on stdout
#define SPEAK_PRINT true

// SPEAK_PLAY_FROM_FILE optin enables to play the WAV file thru audio output
#define SPEAK_PLAY_FROM_FILE true

#define PCM_FILE_DIR "./pcm"
#define CMDSZ 100   // WAV file path size, e.g. ./pcm/thousands.wav
#define PCM_PLAY_CMD "/usr/bin/aplay -q"

// SPEAK_PLAY_FROM_PCM_DATA option stores the WAV file as PCM samples 
//     and directly plays to the audio device
// TODO: Implement external tool to dump WAV file as PCM data into structures
#define SPEAK_PLAY_FROM_PCM_DATA false


int speak_rupees();
int speak_paise();
int speak_digits(int n);
int speak_number(int n);

const int MAX_READ_NUM = 99999; // Numbers beyond this will be read out digit by digit

struct digits_st {
    char *str[10];
    char *file[10];
};
struct digits_st digits = { 
#if SPEAK_PRINT == true
    .str = {"zero", "one", "two", "three","four", "five", "six", 
    "seven", "eight", "nine"},
#endif

#if SPEAK_PLAY_FROM_FILE == true
    .file ={"no0.wav", "no1.wav", "no2.wav", "no3.wav", "no4.wav", "no5.wav", "no6.wav",
    "no7.wav", "no8.wav", "no9.wav"}
#endif
};

struct tens_st {
    char *str[10];
    char *file[10];
};
struct tens_st tens = {
#if SPEAK_PRINT == true 
    .str = {"zero", "ten", "twenty", "thirty", "forty", 
    "fifty", "sixty", "seventy", "eighty", "ninty"},
#endif
#if SPEAK_PLAY_FROM_FILE == true
    .file = {"no0.wav", "no10.wav", "no20.wav", "no30.wav", "no40.wav",
    "no50.wav", "no60.wav", "no70.wav", "no80.wav", "no90.wav"}
#endif
};

struct num_10to19_st {
    char *str[10];
    char *file[10];
};
struct num_10to19_st num_10to19 = { 
#if SPEAK_PRINT == true 
    .str = {"ten", "eleven", "twelve", "thirteen","forteen", 
    "fifteen", "sixsteen", "seventeen", "eighteen", "ninteen"},
    #endif
#if SPEAK_PLAY_FROM_FILE == true
    .file = {"no10.wav", "no11.wav", "no12.wav", "no13.wav", "no14.wav",
    "no15.wav", "no16.wav", "no17.wav", "no18.wav", "no19.wav"} 
#endif
};


char *HUNDRED = "hundred";
char *HUNDRED_WAV = "hundred.wav";

char *THOUSAND = "thousand";
char *THOUSAND_WAV = "thousand.wav";

char *RUPEES = "rupees";
char *RUPEES_WAV = "rupees.wav";

char *PAISE = "paise";
char *PAISE_WAV = "paise.wav";


#if 0
static int speak_digit(int n);
static int speak_10to19(int n);
static int speak_20to90(int n);
static int speak_hundreds(int n);
static int speak_thousands(int n);
static int speak_number(int n);
#endif

#endif // _SPEAKNUM_INT_H_ 
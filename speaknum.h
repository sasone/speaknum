#ifndef _READNUM_H_
#define _READNUM_H_

int speak_rupees();
int speak_paisa();
int speak_digits(int n);
int speak_number(int n);

const int MAX_READ_NUM = 99999; // Numbers beyond this will be read out digit by digit

struct digits_st {
    char *num[10];
};
struct digits_st digits = { {"zero", "one", "two", "three","four", "five", "six", "seven", "eight", "nine"}};

struct tens_st {
    char *num[10];
};
struct tens_st tens = { {"zero", "ten", "twenty", "thirty", "forty", 
    "fifty", "sixty", "seventy", "eighty", "ninty"}};

struct num_10to19_st {
    char *num[10];
};
struct num_10to19_st num_10to19 = { {"ten", "eleven", "twelve", "thirteen","forteen", 
    "fifteen", "sixsteen", "seventeen", "eighteen", "ninteen"}};

char *HUNDRED = "hundred";
char *THOUSAND = "thousand";
char *RUPEES = "rupees";
char *PAISA = "paisa";


#if 0
static int speak_digit(int n);
static int speak_10to19(int n);
static int speak_20to90(int n);
static int speak_hundreds(int n);
static int speak_thousands(int n);
static int speak_number(int n);
#endif

#endif // _READNUM_H_ 
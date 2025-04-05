#include <stdio.h>

#include "speaknum.h"

// Test driver
int main()
{
    printf("\n");

    speak_number(0); speak_rupees();
#if 0
    speak_number(8); speak_rupees();
    speak_number(9); speak_rupees();
    speak_number(10); speak_rupees();
#endif

    speak_number(19); speak_rupees();
    speak_number(20); speak_rupees();
    speak_number(21); speak_rupees();
    speak_number(29); speak_rupees();
    speak_number(80); speak_rupees();
#if 0
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
#endif
    speak_number(9000); speak_rupees();
    speak_number(9199); speak_rupees();
    speak_number(9999); speak_rupees();
    speak_number(10000); speak_rupees();
    speak_number(99999); speak_rupees();
    speak_number(98765432); speak_rupees();
    speak_number(76543210); speak_rupees();

    printf("\n");


    speak_number(25);
    speak_paise();

    speak_number(50);
    speak_paise();


    printf("\n");

    return 0;
}
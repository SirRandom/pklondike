#include "cards.h"

HANDLE conout = NULL;
HANDLE conin  = NULL;

cmdstack undostack;

DWORD ng;
DWORD run;
card* nullcard;
card** deck;
stack *d, *w, *f0, *f1, *f2, *f3, *s0, *s1, *s2, *s3, *s4, *s5, *s6, *a;
stack** tableau;
unsigned char* userinput;
unsigned inputlen;
DWORD useless;

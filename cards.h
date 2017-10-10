#ifndef __CARDS__
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "cards_def.h"

typedef CONSOLE_SCREEN_BUFFER_INFO CSBI;

typedef struct _card
{
	unsigned char suit  : 2;
	unsigned char value : 4;
	unsigned char vis   : 1;
} card;

typedef struct _stack
{
	card** data;
	unsigned len;
} stack;

typedef struct _cmdstack
{
	int* cmds;
	unsigned long long len;
} cmdstack;

extern HANDLE conout;
extern HANDLE conin;

extern cmdstack undostack;

extern DWORD run;
extern card* nullcard;
extern card** deck;
extern stack *d, *w, *f0, *f1, *f2, *f3, *s0, *s1, *s2, *s3, *s4, *s5, *s6, *a;
extern stack** tableau;
extern unsigned char* userinput;
extern unsigned inputlen;
extern DWORD useless;

void   render(void);
void   queryuser(void);
void   executecmd(void);

void   pushcmd(int);
int    popcmd(void);

void   init(void);
void   cleanup(void);

card*  makecard(unsigned, unsigned);
void   cprint(card*);
void   destroycard(card*);

stack* makestack(void);
void   spush(stack*, card*);
card*  spop(stack*);
card*  speek(stack*);
card*  sget(stack*, unsigned);
void   destroystack(stack*);

#define __CARDS__
#endif

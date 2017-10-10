#include "cards.h"

void initff(void);
void initdeck(void);
void swapcardptr(card**, card**);
void initstacks(void);
void destroystacks(void);
void destroydeck(void);
void setupboard(void);
void clearscreen(void);
void fitscreen(void);
void setfont(void);
void setcursor(void);

void init(void)
{
	conout = GetStdHandle(STD_OUTPUT_HANDLE);
	conin  = GetStdHandle(STD_INPUT_HANDLE);
	
	srand(time(NULL));
	
	initff();
	
	setfont();
	setcursor();
	fitscreen();
	clearscreen();
	
	initdeck();
	initstacks();
	setupboard();
	SetConsoleTitle("Klondike");
}

void initff(void)
{
	nullcard = makecard(0, 0);
	userinput = malloc(22 * sizeof(unsigned char));
	undostack.cmds = malloc(undostack.len = 0);
}

void setcursor(void)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(conout, &cci);
}

void setfont(void)
{
	CONSOLE_FONT_INFOEX cfi;
	wcscpy(cfi.FaceName, L"");
	cfi.nFont = 0;
	cfi.dwFontSize.X = FONT_SIZE;
	cfi.dwFontSize.Y = FONT_SIZE;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	cfi.cbSize = sizeof(cfi);
	SetCurrentConsoleFontEx(conout, FALSE, &cfi);
}

void fitscreen(void)
{
	SMALL_RECT sr;
	sr.Left   = 0;
	sr.Top    = 0;
	sr.Right  = SCREEN_X - 1;
	sr.Bottom = SCREEN_Y - 1;
	SetConsoleWindowInfo(conout, TRUE, &sr);
	SetConsoleScreenBufferSize(conout, (COORD) {SCREEN_X, SCREEN_Y});
	SetConsoleWindowInfo(conout, TRUE, &sr);
	SetConsoleScreenBufferSize(conout, (COORD) {SCREEN_X, SCREEN_Y});
	SetConsoleWindowInfo(conout, TRUE, &sr);
	SetConsoleScreenBufferSize(conout, (COORD) {SCREEN_X, SCREEN_Y});
}

void clearscreen(void)
{
	CSBI csbi;
	GetConsoleScreenBufferInfo(conout, &csbi);
	FillConsoleOutputCharacter(conout, ' ', csbi.dwSize.X * csbi.dwSize.Y, (COORD) {0, 0}, &useless);
	
	for(unsigned i = 0; i < 22; i++)
	{
		FillConsoleOutputAttribute(conout, 0xA0, 20, (COORD) {0, i}, &useless);
		FillConsoleOutputAttribute(conout, 0x50, 3, (COORD) {20, i}, &useless);
	}
}

void setupboard(void)
{
	unsigned q = 0;
	
	// tableau
	spush(s0, deck[q++]);
	spush(s1, deck[q++]);
	spush(s2, deck[q++]);
	spush(s3, deck[q++]);
	spush(s4, deck[q++]);
	spush(s5, deck[q++]);
	spush(s6, deck[q++]);
	 spush(s1, deck[q++]);
	 spush(s2, deck[q++]);
	 spush(s3, deck[q++]);
	 spush(s4, deck[q++]);
	 spush(s5, deck[q++]);
	 spush(s6, deck[q++]);
	  spush(s2, deck[q++]);
	  spush(s3, deck[q++]);
	  spush(s4, deck[q++]);
	  spush(s5, deck[q++]);
	  spush(s6, deck[q++]);
	   spush(s3, deck[q++]);
	   spush(s4, deck[q++]);
	   spush(s5, deck[q++]);
	   spush(s6, deck[q++]);
	    spush(s4, deck[q++]);
	    spush(s5, deck[q++]);
	    spush(s6, deck[q++]);
	     spush(s5, deck[q++]);
	     spush(s6, deck[q++]);
	      spush(s6, deck[q++]);
	
	// draw pile
	for(; q < 52; q++)
		spush(d, deck[q]);
	
	speek(s0) -> vis = 1;
	speek(s1) -> vis = 1;
	speek(s2) -> vis = 1;
	speek(s3) -> vis = 1;
	speek(s4) -> vis = 1;
	speek(s5) -> vis = 1;
	speek(s6) -> vis = 1;
}

void cleanup(void)
{
	destroystacks();
	destroydeck();
	
	destroycard(nullcard);
	free(userinput);
}

void initstacks(void)
{
	d  = makestack();
	w  = makestack();
	f0 = makestack();
	f1 = makestack();
	f2 = makestack();
	f3 = makestack();
	s0 = makestack();
	s1 = makestack();
	s2 = makestack();
	s3 = makestack();
	s4 = makestack();
	s5 = makestack();
	s6 = makestack();
	a  = makestack();
	
	tableau = malloc(7 * sizeof(stack*));
	tableau[0] = s0;
	tableau[1] = s1;
	tableau[2] = s2;
	tableau[3] = s3;
	tableau[4] = s4;
	tableau[5] = s5;
	tableau[6] = s6;
}

void destroystacks(void)
{
	free(tableau);
	destroystack(d);
	destroystack(w);
	destroystack(f0);
	destroystack(f1);
	destroystack(f2);
	destroystack(f3);
	destroystack(s0);
	destroystack(s1);
	destroystack(s2);
	destroystack(s3);
	destroystack(s4);
	destroystack(s5);
	destroystack(s6);
	destroystack(a);
}

void initdeck(void)
{
	deck = malloc(52 * sizeof(card*));
	
	unsigned di = 0;
	for(unsigned s = HEARTS; s <= SPADES; s++)
		for(unsigned v = ACE; v <= KING; v++)
			deck[di++] = makecard(s, v);
	
	for(unsigned i = 0; i < SHUFFLELEN; i++)
		swapcardptr(&deck[rand() % 52], &deck[rand() % 52]);
}

void destroydeck(void)
{
	for(unsigned i = 0; i < 52; i++)
		destroycard(deck[i]);
	free(deck);
}

void swapcardptr(card** a, card** b)
{
	card* t = *a;
	*a = *b;
	*b = t;
}

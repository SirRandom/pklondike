#include "cards.h"

#define CUR(x,y) SetConsoleCursorPosition(conout, (COORD){(x),(y)})
#define STREQ(a, b) (strcmp((a), (b)) == 0)

void clearscreen(void);

void render(void)
{
	//clear the screen
	clearscreen();
	
	// if active stack empty, reveal top card of each stack if such a card exists
	if(a -> len == 0)
	{
		if(s0 -> len > 0)
			speek(s0) -> vis = 1;
		if(s1 -> len > 0)
			speek(s1) -> vis = 1;
		if(s2 -> len > 0)
			speek(s2) -> vis = 1;
		if(s5 -> len > 0)
			speek(s5) -> vis = 1;
		if(s6 -> len > 0)
			speek(s6) -> vis = 1;
		if(s3 -> len > 0)
			speek(s3) -> vis = 1;
		if(s4 -> len > 0)
			speek(s4) -> vis = 1;
	}
	
	// draw pile: d
	CUR(0,0);
	if(d -> len > 0)
		cprint(speek(d));
	
	// waste pile: w
	{
		unsigned x;
		for(unsigned i = 1; i < 4; i++)
			if((x = (w -> len) - i) < (w -> len)) // if xth card from top of waste pile exists...
			{
				CUR(7 - (2 * (i - 1)), 0);
				cprint(sget(w, x));
			}
	}
	
	// foundations: f0-f3
	CUR(12,0);
	if(f0 -> len > 0)
		cprint(speek(f0));
	
	if(f1 -> len > 0)
		cprint(speek(f1));
	
	if(f2 -> len > 0)
		cprint(speek(f2));
	
	if(f3 -> len > 0)
		cprint(speek(f3));
	
	// tableau: tableau (s0-s6)
	// s0
	
	
	for(unsigned i = 0; i < 7; i++)
	{
		if((tableau[i] -> len) > 0)
		{
			for(unsigned j = 0; j < (tableau[i] -> len); j++)
			{
				CUR(i * 3, j + 2);
				cprint(sget(tableau[i], j));
			}
		}
	}
	
	// active card stack: a
	for(unsigned i = (a -> len) - 1; i < (a -> len) ; i--)
	{
		CUR(21, i);
		cprint(sget(a, i));
	}
	
	// user input line
	CUR(0, 22);
	printf(":");
}

int isValidInputChar(WORD ascii)
{
	if(ascii >= ' ' && ascii <= '~')
		return 1;
	return 0;
}

void queryuser(void)
{
	inputlen = 0;
	INPUT_RECORD ir;
	
	for(unsigned i = 0; i < 22; i++)
		userinput[i] = '\0';
	
	while(1)
	{
		ReadConsoleInput(conin, &ir, 1, &useless);
		
		if(ir.EventType == KEY_EVENT && ir.Event.KeyEvent.bKeyDown)
		{
			if(isValidInputChar(ir.Event.KeyEvent.uChar.AsciiChar) && inputlen < 22)
				userinput[inputlen++] = ir.Event.KeyEvent.uChar.AsciiChar;
			else if(ir.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
				return;
			else if(ir.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
			{
				for(unsigned i = 0; i < 22; i++)
					userinput[i] = '\0';
				inputlen = 0;
			}
			else if(ir.Event.KeyEvent.wVirtualKeyCode == VK_BACK && inputlen > 0)
				userinput[--inputlen] = '\0';
			
			WriteConsoleOutputCharacter(conout, userinput, 22, (COORD) {1, 22}, &useless);
		}
	}
}

#include "cards.h"

#define CUR(x,y) SetConsoleCursorPosition(conout, (COORD){(x),(y)})

void clearscreen(void);

void render(void)
{
	clearscreen();
	
	speek(s0) -> vis = 1;
	speek(s1) -> vis = 1;
	speek(s2) -> vis = 1;
	speek(s3) -> vis = 1;
	speek(s4) -> vis = 1;
	speek(s5) -> vis = 1;
	speek(s6) -> vis = 1;
	
	// draw pile: d
	CUR(0,0);
	if(d -> len > 0)
		cprint(speek(d));
	else
		cprint(nullcard);
	
	// waste pile: w
	CUR(3,0);
	if(w -> len > 0)
	{
		for(unsigned i = 0; i < 3; i++)
			if(i < w -> len)
				cprint(sget(w, i));
			else
				cprint(nullcard);
	}
	else
	{
		cprint(nullcard);
		cprint(nullcard);
		cprint(nullcard);
	}
	
	// foundations: f0-f3
	CUR(12,0);
	if(f0 -> len > 0)
		cprint(speek(f0));
	else
		cprint(nullcard);
	
	if(f1 -> len > 0)
		cprint(speek(f1));
	else
		cprint(nullcard);
	
	if(f2 -> len > 0)
		cprint(speek(f2));
	else
		cprint(nullcard);
	
	if(f3 -> len > 0)
		cprint(speek(f3));
	else
		cprint(nullcard);
	
	// tableau: tableau (s0-s6)
	for(unsigned i = 0; i < 7; i++)
	{
		for(unsigned j = 0; j < (tableau[i] -> len); j++)
		{
			CUR(i * 3, j + 2);
			cprint(sget(tableau[i], j));
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
		userinput[i] = ' ';
	
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
					userinput[i] = ' ';
				inputlen = 0;
			}
			else if(ir.Event.KeyEvent.wVirtualKeyCode == VK_BACK && inputlen > 0)
				userinput[--inputlen] = ' ';
			
			WriteConsoleOutputCharacter(conout, userinput, 22, (COORD) {1, 22}, &useless);
		}
	}
}

int parsecmd(void)
{
	// todo: write functionality :^)
}

void executecmd(void)
{
	int cmd = parsecmd();
	
	switch(cmd)
	{
		// todo: add cmd cases
	}
}

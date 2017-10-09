#include "cards.h"

card* makecard(unsigned suit, unsigned value)
{
	card* c = malloc(sizeof(card));
	c -> suit  = suit;
	c -> value = value;
	c -> vis   = 0;
	return c;
}

void cprint(card* c)
{
	unsigned char suit;
	unsigned char value;
	unsigned short attr;
	
	CHAR_INFO screen[SCREEN_X][SCREEN_Y];
	WORD bgattr;
	WORD pattr;
	
	{
		SMALL_RECT sr;
		sr.Left   = 0;
		sr.Top    = 0;
		sr.Right  = SCREEN_X - 1;
		sr.Bottom = SCREEN_Y - 1;
		ReadConsoleOutput(conout, &screen[0][0], (COORD) {SCREEN_X, SCREEN_Y}, (COORD) {0, 0}, &sr);
		CSBI csbi;
		GetConsoleScreenBufferInfo(conout, &csbi);
		pattr = csbi.wAttributes;
		bgattr = (screen[csbi.dwCursorPosition.X][csbi.dwCursorPosition.Y].Attributes) & 0xF0;
	}
	
	if(c -> value)
	{
		if(c -> vis)
		{
			attr = bgattr | (((c -> suit) >> 1)? 0x0 : 0xC);
			suit = c -> suit + 3;
			
			switch(c -> value)
			{
				case ACE:
					value = 'A';
					break;
				case TWO:
				case THREE:
				case FOUR:
				case FIVE:
				case SIX:
				case SEVEN:
				case EIGHT:
				case NINE:
					value = c -> value + '0';
					break;
				case TEN:
					value = '0';
					break;
				case JACK:
					value = 'J';
					break;
				case QUEEN:
					value = 'Q';
					break;
				case KING:
					value = 'K';
					break;
			}
		}
		else
		{
			attr = bgattr | 0x8;
			suit = value = '?';
		}
	}
	else
	{
		attr = bgattr;
		suit = value = ' ';
	}
	
	SetConsoleTextAttribute(conout, attr);
	printf("%c%c", suit, value);
	SetConsoleTextAttribute(conout, pattr);
}

void destroycard(card* c)
{
	free(c);
}

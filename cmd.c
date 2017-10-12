#include "cards.h"

#define STREQ(a, b) (strcmp((a), (b)) == 0)

/*void pushcmd(int cmd)
{
	undostack.cmds = realloc(undostack.cmds, ++undostack.len);
	undostack.cmds[undostack.len - 1] = cmd;
}

int popcmd(void)
{
	int t = undostack.cmds[undostack.len - 1];
	undostack.cmds = realloc(undostack.cmds, --undostack.len);
	return t;
}*/

void quit(void)
{
	run = 0;
}

void help(void)
{
	
}

void newgame(void)
{
	ng = 1;
}

void deal(void)
{
	card* t;
	
	for(unsigned i = 0; i < 3; i++)
	{
		if(d -> len > 0)
		{
			t = spop(d);  // remove top card from draw pile
			t -> vis = 1; // reveal that card
			spush(w, t);  // push it onto the waste pile
		}
	}
}

void pops0(void)
{
	if(s0 -> len > 0)
		spush(a, spop(s0));
}

void pops1(void)
{
	if(s1 -> len > 0)
		spush(a, spop(s1));
}

void pops2(void)
{
	if(s2 -> len > 0)
		spush(a, spop(s2));
}

void pops3(void)
{
	if(s3 -> len > 0)
		spush(a, spop(s3));
}

void pops4(void)
{
	if(s4 -> len > 0)
		spush(a, spop(s4));
}

void pops5(void)
{
	if(s5 -> len > 0)
		spush(a, spop(s5));
}

void pops6(void)
{
	if(s6 -> len > 0)
		spush(a, spop(s6));
}

void popalls0(void)
{
	while(s0 -> len > 0 && speek(s0) -> vis == 1)
		spush(a, spop(s0));
}

void popalls1(void)
{
	while(s1 -> len > 0 && speek(s1) -> vis == 1)
		spush(a, spop(s1));
}

void popalls2(void)
{
	while(s2 -> len > 0 && speek(s2) -> vis == 1)
		spush(a, spop(s2));
}

void popalls3(void)
{
	while(s3 -> len > 0 && speek(s3) -> vis == 1)
		spush(a, spop(s3));
}

void popalls4(void)
{
	while(s4 -> len > 0 && speek(s4) -> vis == 1)
		spush(a, spop(s4));
}

void popalls5(void)
{
	while(s5 -> len > 0 && speek(s5) -> vis == 1)
		spush(a, spop(s5));
}

void popalls6(void)
{
	while(s6 -> len > 0 && speek(s6) -> vis == 1)
		spush(a, spop(s6));
}

void pushs0(void)
{
	while(a -> len > 0)
	{
		spush(s0, spop(a));
		//pushcmd(CMD_PUSHS0);
	}
}

void pushs1(void)
{
	while(a -> len > 0)
	{
		spush(s1, spop(a));
		//pushcmd(CMD_PUSHS1);
	}
}

void pushs2(void)
{
	while(a -> len > 0)
	{
		spush(s2, spop(a));
		//pushcmd(CMD_PUSHS2);
	}
}

void pushs3(void)
{
	while(a -> len > 0)
	{
		spush(s3, spop(a));
		//pushcmd(CMD_PUSHS3);
	}
}

void pushs4(void)
{
	while(a -> len > 0)
	{
		spush(s4, spop(a));
		//pushcmd(CMD_PUSHS4);
	}
}

void pushs5(void)
{
	while(a -> len > 0)
	{
		spush(s5, spop(a));
		//pushcmd(CMD_PUSHS5);
	}
}

void pushs6(void)
{
	while(a -> len > 0)
	{
		spush(s6, spop(a));
		//pushcmd(CMD_PUSHS6);
	}
}

void pushf0(void)
{
	if(a -> len > 0)
	{
		spush(f0, spop(a));
		//pushcmd(CMD_PUSHF0);
	}
}

void pushf1(void)
{
	if(a -> len > 0)
	{
		spush(f1, spop(a));
		//pushcmd(CMD_PUSHF1);
	}
}

void pushf2(void)
{
	if(a -> len > 0)
	{
		spush(f2, spop(a));
		//pushcmd(CMD_PUSHF2);
	}
}

void pushf3(void)
{
	if(a -> len > 0)
	{
		spush(f3, spop(a));
		//pushcmd(CMD_PUSHF3);
	}
}

void popw(void)
{
	if(w -> len > 0)
	{
		spush(a, spop(w));
		//pushcmd(CMD_POPW);
	}
}

void undo(void)
{
	/*switch(popcmd())
	{
		
	}*/
}

void recycle(void)
{
	card* t;
	
	while(w -> len > 0)
	{
		t = spop(w);
		t -> vis = 0;
		spush(d, t);
	}
}

void (*cmdex[])(void) = {
	quit,
	help,
	newgame,
	deal,
	pops0,
	pops1,
	pops2,
	pops3,
	pops4,
	pops5,
	pops6,
	popalls0,
	popalls1,
	popalls2,
	popalls3,
	popalls4,
	popalls5,
	popalls6,
	pushs0,
	pushs1,
	pushs2,
	pushs3,
	pushs4,
	pushs5,
	pushs6,
	pushf0,
	pushf1,
	pushf2,
	pushf3,
	popw,
	undo,
	recycle
};

char** cmds[] = {
	(char*[]) {"quit", "!q", "exit", NULL},
	(char*[]) {"help", "h", "?", NULL},
	(char*[]) {"newgame", "ng", NULL},
	(char*[]) {"deal", "d", NULL},
	(char*[]) {"pops0", "p s0", "ps0", "pop s0", "p0", NULL},
	(char*[]) {"pops1", "p s1", "ps1", "pop s1", "p1", NULL},
	(char*[]) {"pops2", "p s2", "ps2", "pop s2", "p2", NULL},
	(char*[]) {"pops3", "p s3", "ps3", "pop s3", "p3", NULL},
	(char*[]) {"pops4", "p s4", "ps4", "pop s4", "p4", NULL},
	(char*[]) {"pops5", "p s5", "ps5", "pop s5", "p5", NULL},
	(char*[]) {"pops6", "p s6", "ps6", "pop s6", "p6", NULL},
	(char*[]) {"popalls0", "pa s0", "pas0", "popall s0", "pop all s0", "pa0", NULL},
	(char*[]) {"popalls1", "pa s1", "pas1", "popall s1", "pop all s1", "pa1", NULL},
	(char*[]) {"popalls2", "pa s2", "pas2", "popall s2", "pop all s2", "pa2", NULL},
	(char*[]) {"popalls3", "pa s3", "pas3", "popall s3", "pop all s3", "pa3", NULL},
	(char*[]) {"popalls4", "pa s4", "pas4", "popall s4", "pop all s4", "pa4", NULL},
	(char*[]) {"popalls5", "pa s5", "pas5", "popall s5", "pop all s5", "pa5", NULL},
	(char*[]) {"popalls6", "pa s6", "pas6", "popall s6", "pop all s6", "pa6", NULL},
	(char*[]) {"pushs0", "s s0", "ss0", "push s0", "shove s0", "shoves0", "s0", NULL},
	(char*[]) {"pushs1", "s s1", "ss1", "push s1", "shove s1", "shoves1", "s1", NULL},
	(char*[]) {"pushs2", "s s2", "ss2", "push s2", "shove s2", "shoves2", "s2", NULL},
	(char*[]) {"pushs3", "s s3", "ss3", "push s3", "shove s3", "shoves3", "s3", NULL},
	(char*[]) {"pushs4", "s s4", "ss4", "push s4", "shove s4", "shoves4", "s4", NULL},
	(char*[]) {"pushs5", "s s5", "ss5", "push s5", "shove s5", "shoves5", "s5", NULL},
	(char*[]) {"pushs6", "s s6", "ss6", "push s6", "shove s6", "shoves6", "s6", NULL},
	(char*[]) {"pushf0", "s f0", "sf0", "push f0", "shove f0", "shovef0", NULL},
	(char*[]) {"pushf1", "s f1", "sf1", "push f1", "shove f1", "shovef1", NULL},
	(char*[]) {"pushf2", "s f2", "sf2", "push f2", "shove f2", "shovef2", NULL},
	(char*[]) {"pushf3", "s f3", "sf3", "push f3", "shove f3", "shovef3", NULL},
	(char*[]) {"popw", "pw", "p w", "pop w", NULL},
	(char*[]) {"undo", "u", NULL},
	(char*[]) {"recycle", "r", NULL}
};

void executecmd(void)
{
	for(unsigned i = 0; i < 32; i++)
	{
		for(unsigned j = 0; cmds[i][j] != NULL; j++)
		{
			if(STREQ(userinput, cmds[i][j]))
			{
				(cmdex[i])();
				return;
			}
		}
	}
}

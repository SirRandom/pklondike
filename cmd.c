#include "cards.h"

#define STREQ(a, b) (strcmp((a), (b)) == 0)

void quit(void)
{
	run = 0;
}

void help(void)
{
	
}

void newgame(void)
{
	
}

void deal(void)
{
	spush(w, spop(d));
	spush(w, spop(d));
	spush(w, spop(d));
}

void pops0(void)
{
	spush(a, spop(s0));
}

void pops1(void)
{
	spush(a, spop(s1));
}

void pops2(void)
{
	spush(a, spop(s2));
}

void pops3(void)
{
	spush(a, spop(s3));
}

void pops4(void)
{
	spush(a, spop(s4));
}

void pops5(void)
{
	spush(a, spop(s5));
}

void pops6(void)
{
	spush(a, spop(s6));
}

void pushs0(void)
{
	while(a -> len > 0)
		spush(s0, spop(a));
}

void pushs1(void)
{
	while(a -> len > 0)
		spush(s1, spop(a));
}

void pushs2(void)
{
	while(a -> len > 0)
		spush(s2, spop(a));
}

void pushs3(void)
{
	while(a -> len > 0)
		spush(s3, spop(a));
}

void pushs4(void)
{
	while(a -> len > 0)
		spush(s4, spop(a));
}

void pushs5(void)
{
	while(a -> len > 0)
		spush(s5, spop(a));
}

void pushs6(void)
{
	while(a -> len > 0)
		spush(s6, spop(a));
}

void pushf0(void)
{
	spush(f0, spop(a));
}

void pushf1(void)
{
	spush(f1, spop(a));
}

void pushf2(void)
{
	spush(f2, spop(a));
}

void pushf3(void)
{
	spush(f3, spop(a));
}

void popw(void)
{
	spush(a, spop(w));
}

void undo(void)
{
	
}

void recycle(void)
{
	while(w -> len > 0)
		spush(d, spop(w));
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
	(char*[]) {"quit", "!q", NULL},
	(char*[]) {"help", "h", "?", NULL},
	(char*[]) {"newgame", "ng", NULL},
	(char*[]) {"deal", "d", NULL},
	(char*[]) {"pops0", "p s0", "ps0", "pop s0", NULL},
	(char*[]) {"pops1", "p s1", "ps1", "pop s1", NULL},
	(char*[]) {"pops2", "p s1", "ps1", "pop s1", NULL},
	(char*[]) {"pops3", "p s1", "ps1", "pop s1", NULL},
	(char*[]) {"pops4", "p s1", "ps1", "pop s1", NULL},
	(char*[]) {"pops5", "p s1", "ps1", "pop s1", NULL},
	(char*[]) {"pops6", "p s1", "ps1", "pop s1", NULL},
	(char*[]) {"pushs0", "s s0", "ss0", "push s0", "shove s0", "shoves0", NULL},
	(char*[]) {"pushs1", "s s1", "ss1", "push s1", "shove s1", "shoves1", NULL},
	(char*[]) {"pushs2", "s s2", "ss2", "push s2", "shove s2", "shoves2", NULL},
	(char*[]) {"pushs3", "s s3", "ss3", "push s3", "shove s3", "shoves3", NULL},
	(char*[]) {"pushs4", "s s4", "ss4", "push s4", "shove s4", "shoves4", NULL},
	(char*[]) {"pushs5", "s s5", "ss5", "push s5", "shove s5", "shoves5", NULL},
	(char*[]) {"pushs6", "s s6", "ss6", "push s6", "shove s6", "shoves6", NULL},
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
	for(unsigned i = 0; i < 25; i++)
	{
		for(unsigned j = 0; cmds[i][j] != NULL; j++)
		{
			if(STREQ(userinput, cmds[i][j]))
			{
				(cmdex[i])();
				goto end;
			}
		}
	}
	
	end:;
}

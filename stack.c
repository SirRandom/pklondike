#include "cards.h"

#define topOfStack(s) (((s) -> data)[((s) -> len) - 1])

stack* makestack(void)
{
	stack* s = malloc(sizeof(stack));
	s -> len = 0;
	s -> data = malloc(s -> len);
	return s;
}

void spush(stack* s, card* c)
{
	(s -> len)++;
	s -> data = realloc(s -> data, (s -> len) * sizeof(card*));
	topOfStack(s) = c;
}

card* spop(stack* s)
{
	card* c = topOfStack(s);
	(s -> len)--;
	s -> data = realloc(s -> data, (s -> len) * sizeof(card*));
	return c;
}

card* speek(stack* s)
{
	return topOfStack(s);
}

card* sget(stack* s, unsigned i)
{
	return (s -> data)[i];
}

void destroystack(stack* s)
{
	free(s);
}

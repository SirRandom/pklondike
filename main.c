#include "cards.h"

int main(void)
{
	init();
	
	while(1)
	{
		render();
		queryuser();
		executecmd();
	}
	
	cleanup();
	return 0;
}

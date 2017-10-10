#include "cards.h"

int main(void)
{
	init();
	
	while(run)
	{
		render();
		queryuser();
		executecmd();
	}
	
	cleanup();
	return 0;
}

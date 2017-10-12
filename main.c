#include "cards.h"

int main(void)
{
begin:
	init();
	
	while(run)
	{
		render();
		queryuser();
		executecmd();
		if(ng)
		{
			cleanup();
			goto begin;
		}
	}
	
	cleanup();
	return 0;
}

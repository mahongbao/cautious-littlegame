#include <stdio.h>
#include <stdlib.h>
#include <getch.h>

int main()
{
	char map[8][8] = {
	    {0,0,3,3,3,3,0,0},
        {0,0,3,5,5,3,0,0}, 
        {0,3,3,0,5,3,3,0}, 
        {0,3,0,0,4,5,3,0},  
        {3,3,0,4,0,0,3,3},  
        {3,0,0,3,4,4,0,3},
        {3,0,0,2,0,0,0,3},
        {3,3,3,3,3,3,3,3},          
    };

	int x = 6 , y = 3 , step = 0;
	
	for(;;)
	{
		system("clear");

		int cnt = 0;
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				switch(map[i][j])
				{
					case 0: printf("  "); break;
					case 2: printf("@ "); break;
					case 3: printf("# "); break;
					case 4: printf("$ "); break;
					case 5: printf("O "); break;
					case 7: printf("@ "); break;
					case 9: printf("$ "); cnt++;
				}
			}
			printf("\n");
		}

		if(4 == cnt)
		{
			printf("恭喜完成任务，一共走%d步!\n", step);
			return 0;
		}

		int ox = 0 , oy = 0;
		switch(getch())
		{
			case 183: ox--; break;
			case 184: ox++; break;
			case 185: oy++; break;
			case 186: oy--; break;

		}

		if(0 == map[x+ox][y+oy] || 5 == map[x+ox][y+oy])
		{
			map[x+ox][y+oy] += 2;
			map[x][y] -= 2;
			x += ox;
			y += oy;
			step++;
			continue;
		}

		if((4 == map[x+ox][y+oy] || 9==map[x+ox][y+oy]) && 
		   (0 == map[x+ox*2][y+oy*2] || 5 == map[x+ox*2][y+oy*2]))
		{
			map[x+ox*2][y+oy*2] += 4;
			map[x+ox][y+oy] -= 2;
			map[x][y] -= 2;
			x += ox;
			y += oy;
			step++;
		}
	}
}

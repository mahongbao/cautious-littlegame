#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getch.h>

int main()
{
	char maze[10][10] = {
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','@','#',' ',' ',' ',' ',' ',' ',' '},
		{'#',' ','#',' ','#',' ','#',' ','#','#'},
		{'#',' ','#',' ','#','#','#',' ','#','#'},
		{'#',' ','#',' ',' ',' ','#',' ',' ','#'},
		{'#',' ','#',' ','#',' ','#','#','#','#'},
		{'#',' ','#',' ','#',' ','#',' ','#','#'},
		{'#',' ','#',' ','#',' ','#',' ','#','#'},
		{'#',' ',' ',' ','#',' ',' ',' ','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
	};

	int mouse_x = 1 , mouse_y = 1;

	time_t start_time = time(NULL);

	for(;;)
	{
		system("clear");

		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				printf("%c ",maze[i][j]);
			}
			printf("\n");
		}

		if(1 == mouse_x && 9 == mouse_y)
		{
			printf("恭喜你走出迷宫，共用时%u秒!\n",time(NULL) - start_time);
			return 0;
		}

		switch(getch())
		{
			case 183:
				if(0 != mouse_x && ' '==maze[mouse_x-1][mouse_y])
				{
					maze[mouse_x][mouse_y] = ' ';
					maze[--mouse_x][mouse_y] = '@';
				}
				break;
			case 184:
				if(9 != mouse_x && ' '==maze[mouse_x+1][mouse_y])
				{
					maze[mouse_x][mouse_y] = ' ';
					maze[++mouse_x][mouse_y] = '@';
				}
				break;
			case 185:
				if(9 != mouse_y && ' '==maze[mouse_x][mouse_y+1])
				{
					maze[mouse_x][mouse_y] = ' ';
					maze[mouse_x][++mouse_y] = '@';
				}
				break;
			case 186:
				if(0 != mouse_y && ' '==maze[mouse_x][mouse_y-1])
				{
					maze[mouse_x][mouse_y] = ' ';
					maze[mouse_x][--mouse_y] = '@';
				}
				break;
		}
	}
}

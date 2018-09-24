#include <stdio.h>
#include <stdlib.h>

#define DIMENSION 1000
#define NB_ITERATION 10000


int** allocation_memory(int** grid)	{
	int i;

	grid = (int**)malloc(DIMENSION * sizeof(int*));
	for(i = 0 ; i < DIMENSION ; i++)
		grid[i] = (int*)malloc(DIMENSION * sizeof(int));

	if(grid == NULL)	{
		printf("allocation has failed\n");
		return NULL;
	}

	return grid;
}

int ** init_grid(int ** grid)	{
	int i;
	int j;

	for(i = 0 ; i < DIMENSION ; i++)
		for(j = 0 ; j < DIMENSION ; j++)
			grid[i][j] = 0;
	return grid;
}

int ** ant_shifting(int ** grid)	{
	int k, l;
	k = 500;
	l = 500;
	int ant_location = grid[k][l];
	char ant_direction = 'N';
	int i;

	for(i = 0 ; i < NB_ITERATION ; i++)	{
		//Case White square
		if(ant_location == 0 && ant_direction == 'N')	{
			grid[k][l] = 1;
			l++;
			ant_location = grid[k][l];
			ant_direction = 'E';
		}
		if(ant_location == 0 && ant_direction == 'E')	{
			grid[k][l] = 1;
			k++;
			ant_location = grid[k][l];
			ant_direction = 'S';
		}
		if(ant_location == 0 && ant_direction == 'S')	{
			grid[k][l] = 1;
			l--;
			ant_location = grid[k][l];
			ant_direction = 'W';
		}
		if(ant_location == 0 && ant_direction == 'W')	{
			grid[k][l] = 1;
			k--;
			ant_location = grid[k][l];
			ant_direction = 'N';
		}
		//Case Black square 
		if(ant_location == 1 && ant_direction == 'N')	{
			grid[k][l] = 0;
			l--;
			ant_location = grid[k][l];
			ant_direction = 'W';
		}
		if(ant_location == 1 && ant_direction == 'W')	{
			grid[k][l] = 0;
			k++;
			ant_location = grid[k][l];
			ant_direction = 'S';
		}
		if(ant_location == 1 && ant_direction == 'S')	{
			grid[k][l] = 0;
			l++;
			ant_location = grid[k][l];
			ant_direction = 'E';
		}
		if(ant_location == 1 && ant_direction == 'E')	{
			grid[k][l] = 0;
			k--;
			ant_location = grid[k][l];
			ant_direction = 'N';
		}
	}

	return grid;
}

void display(int ** grid)	{
	int i,j;

	for(i = 0 ; i < DIMENSION ; i++)	{
		for(j = 0 ; j < DIMENSION ; j++)	{
			if(grid[i][j] == 0)	
				printf(" ");
			else	
				printf("•");
		}
		printf("\n");
	}
}

int main(void)	{
	int** grid;

	grid = allocation_memory(grid);
	printf("allocation has succeeded\n");
	grid = init_grid(grid);
	printf("grid[200][976] = %d\n", grid[200][976]);
	grid = ant_shifting(grid);
	display(grid);
	return 0;
}


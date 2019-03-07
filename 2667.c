#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num;

int way(int** mat, int** visit, int xx, int yy, int num_of_inputs)
{
	if (visit[xx][yy] == 1)
		return 0;
	visit[xx][yy] = 1;

	if (mat[xx][yy] == 0)
		return 0;

	num++;

	if (xx != 0)
	{
		way(mat, visit, xx - 1, yy, num_of_inputs);
		
	}
	if (xx != num_of_inputs-1)
	{
		way(mat, visit, xx + 1, yy, num_of_inputs);
		
	}
	if (yy != 0)
	{
		way(mat, visit, xx, yy - 1,  num_of_inputs);
		
	}
	if (yy != num_of_inputs-1)
	{
		way(mat, visit, xx, yy + 1, num_of_inputs);
		
	}

	return 0;
}

int main()
{
	int num_of_inputs;
	int t = 0;
	int temp;
	scanf("%d", &num_of_inputs);
	
	int **mat = (int **)malloc(sizeof(int*) * num_of_inputs);
	int **visit = (int **)malloc(sizeof(int*) * num_of_inputs);
	int *answer = (int *)malloc(sizeof(int) * num_of_inputs * num_of_inputs);
	
	for (int x = 0; x < num_of_inputs; x++)
	{
		mat[x] = (int *)malloc(sizeof(int) * num_of_inputs);
		visit[x] = (int *)malloc(sizeof(int) * num_of_inputs);
		for (int y = 0; y < num_of_inputs; y++)
		{
			scanf("%1d", &mat[x][y]);
			visit[x][y] = 0;
		}
	}

	for (int x = 0; x < num_of_inputs; x++)
	{
		for (int y = 0; y < num_of_inputs; y++)
		{
			num = 0;
			way(mat, visit, x, y, num_of_inputs);

			if (num != 0)
			{
				answer[t] = num;
				t++;
			}
		}
	}

	for (int x = 1; x < t; x++)
	{
		for (int y = 1; y < t; y++)
		{
			if (answer[y] < answer[y - 1])
			{
				temp = answer[y - 1];
				answer[y - 1] = answer[y];
				answer[y] = temp;
			}
		}
	}

	printf("%d\n", t);
	for (int x = 0; x < t; x++)
	{
		printf("%d\n", answer[x]);
	}

	return 0;
}

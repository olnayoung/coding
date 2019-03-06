#include <stdio.h>
#include <stdlib.h>

int pos[101][101] = { 0 };

int way(int** mat, int* visit, int start, int temp, int dest, int num_of_inputs)
{
	if (visit[temp] == 1)
	{
		return 0;
	}
	for (int x = 0; x < num_of_inputs; x++)
	{
		if ((pos[start][dest] == 1))
		{
			return 0;
		}
		if (mat[temp][x] == 1)
		{
			if (x == dest)
			{
				pos[start][dest] = 1;
				return 0;
			}
			else
			{
				visit[temp] = 1;
				way(mat, visit, start, x, dest, num_of_inputs);
			}
		}
	}
	return 0;
}

int main()
{
	int num_of_inputs;
	scanf("%d", &num_of_inputs);

	int **mat = (int **)malloc(sizeof(int*) * num_of_inputs);
	int *visit = (int *)malloc(sizeof(int*) * num_of_inputs);

	for (int x = 0; x < num_of_inputs; x++)
	{
		mat[x] = (int *)malloc(sizeof(int) * num_of_inputs);
		for (int y = 0; y < num_of_inputs; y++)
		{
			scanf("%d", &mat[x][y]);
		}
	}

	for (int x = 0; x < num_of_inputs; x++)
	{
		for (int y = 0; y < num_of_inputs; y++)
		{
			for (int t = 0; t < num_of_inputs; t++)
				visit[t] = 0;
			way(mat, visit, x, x, y, num_of_inputs);
		}
	}

	for (int x = 0; x < num_of_inputs; x++)
	{
		for (int y = 0; y < num_of_inputs; y++)
		{
			printf("%d ", pos[x][y]);
		}
		printf("\n");
	}

	return 0;
}

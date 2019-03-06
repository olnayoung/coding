#include <stdio.h>
#include <stdlib.h>

int way(int* mat, int* b1, int* b2, int* check, int* visit, int* answer, int start, int present, int num_of_inputs)
{
	int temp = 0;

	for (int x = 0; x < num_of_inputs; x++)
	{
		check[x] = 0;
	}

	if ((visit[start] == 1) || (answer[start] == 1))
	{
		return 0;
	}

	b1[present-1] = start;
	b2[present-1] = mat[start];

	for (int x = 0; x < present; x++)
	{
		for (int y = 0; y < present; y++)
		{
			if (check[b2[y]] == 0)
			{
				if (b1[x] == b2[y])
				{
					temp++;
					check[b1[x]] = 1;
				}
			}
		}
	}

	if (temp == present)
	{
		for (int x = 0; x < present; x++)
		{
			answer[b1[x]] = 1;
		}
	}
	

	visit[start] = 1;
	way(mat, b1, b2, check, visit, answer, mat[start], present + 1, num_of_inputs);

	return 0;
}

int main()
{
	int num_of_inputs;
	int num = 0;
	scanf("%d", &num_of_inputs);

	int *mat = (int *)malloc(sizeof(int*) * num_of_inputs);
	int *b1 = (int *)malloc(sizeof(int*) * num_of_inputs);
	int *b2 = (int *)malloc(sizeof(int*) * num_of_inputs);
	int *check = (int *)malloc(sizeof(int*) * num_of_inputs);
	int *visit = (int *)malloc(sizeof(int*) * num_of_inputs);
	int *answer = (int *)malloc(sizeof(int*) * num_of_inputs);

	for (int x = 0; x < num_of_inputs; x++)
	{
		scanf("%d", &mat[x]);
		mat[x] = mat[x] - 1;
		answer[x] = 0;
	}

	for (int x = 0; x < num_of_inputs; x++)
	{
		for (int y = 0; y < num_of_inputs; y++)
		{
			visit[y] = 0;
			b1[y] = 0;
			b2[y] = 0;
		}
		way(mat, b1, b2, check, visit, answer, x, 1, num_of_inputs);
	}

	for (int x = 0; x < num_of_inputs; x++)
	{
		if (answer[x] == 1)
			num++;
	}

	printf("%d\n", num);

	for (int x = 0; x < num_of_inputs; x++)
	{
		if (answer[x] == 1)
		{
			printf("%d\n", x+1);
		}
	}

	return 0;
}

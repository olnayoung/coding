#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int front = 0;
int rear = 0;

int isempty()
{
	return (front - rear);
}

int que_in(int* que, int num, int node)
{
	que[rear] = num;
	rear = (rear+1) % (node);
	return 0;
}

int que_out(int* que, int node)
{
	int temp = que[front];
	front = (front + 1) % (node);
	return temp;
}


int BFS(int** mat, int* visit, int cur, int* que, int node)
{
	if (visit[cur] == 1)
		return 0;
	printf("%d ", cur + 1);
	visit[cur] = 1;

	que_in(que, cur, node);

	int temp, num = 0;
	int *order = (int *)malloc(sizeof(int*) * node);

	while (1)
	{
		num = 0;
		while (1)
		{
			temp = que_out(que, node);
			for (int x = 0; x < node; x++)
			{
				if (mat[temp][x] == 1 && visit[x] == 0)
				{
					order[num] = x;
					num++;
					visit[x] = 1;
				}
			}
			if (isempty() == 0)
			{
				break;
			}
		}
		
		for (int x = 1; x < num; x++)
		{
			if (order[x] < order[x - 1])
			{
				temp = order[x];
				order[x] = order[x - 1];
				order[x - 1] = temp;
			}
		}

		for (int x = 0; x < num; x++)
		{
			printf("%d ", order[x] + 1);
			que_in(que, order[x], node);
			visit[order[x]] = 1;
		}

		if (num == 0)
			break;
	}
	return 0;
}


int DFS(int** mat, int* visit, int cur, int node)
{
	if (visit[cur] == 1)
		return 0;
	printf("%d ", cur+1);
	visit[cur] = 1;

	for (int x = 0; x < node; x++)
	{
		if (mat[cur][x] == 1)
		{
			DFS(mat, visit, x, node);
		}
	}
	return 0;
}

int main()
{
	int node, edge, start;
	int from, to;

	scanf("%d %d %d", &node, &edge, &start);

	int **mat = (int **)malloc(sizeof(int*) * node);
	int *visit = (int *)malloc(sizeof(int*) * node);
	int *que = (int *)malloc(sizeof(int*) * node);

	for (int x = 0; x < node; x++)
	{
		mat[x] = (int *)malloc(sizeof(int) * node);
	}

	for (int x = 0; x < edge; x++)
	{
		scanf("%d %d", &from, &to);
		mat[from-1][to-1] = 1;
		mat[to-1][from-1] = 1;
	}

	for (int x = 0; x < node; x++)
	{
		visit[x] = 0;
	}

	DFS(mat, visit, start-1, node);
	printf("\n");

	for (int x = 0; x < node; x++)
	{
		visit[x] = 0;
	}

	BFS(mat, visit, start-1, que, node);

	return 0;
}

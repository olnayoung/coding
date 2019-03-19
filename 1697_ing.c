#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000

int front = 0;
int rear = 0;

int isempty()
{
	return (front - rear);
}

int que_in(int* que, int num, int node)
{
	que[rear] = num;
	rear = (rear + 1) % (node);
	return 0;
}

int que_out(int* que, int node)
{
	int temp = que[front];
	front = (front + 1) % (node);
	return temp;
}


int BFS(int* que, int* visit, int subin, int sis)
{
	int time[MAX] = { 0 };
	int num = sis * 2;
	int cur;
	que_in(que, subin, num);
	visit[subin] = 1;

	int temp = subin;
	int how_much = 1;
	int finish = 0;
	while (temp != sis)
	{
		//printf("\ntime: %d, how_much: %d", time, how_much);

		temp = que_out(que, num);
		if (temp == sis)
			finish = 1;
		//printf("\n%d %d", temp, sis);

		if (temp > 0 && visit[temp - 1] != 1)
		{
			//printf("\n1. %d", visit[temp-1]);
			cur = temp - 1;
			que_in(que, cur, num);
			visit[cur] = 1;
			time[cur] = time[temp] + 1;
		}
		if (temp - 1 == sis)	break;
		if (temp + 1 < MAX  && visit[temp + 1] != 1)
		{
			//printf("\n2. %d", visit[temp - 1]);
			cur = temp + 1;
			que_in(que, cur, num);
			visit[cur] = 1;
			time[cur] = time[temp] + 1;
		}
		if (temp + 1 == sis)	break;
		if (temp * 2 < MAX && visit[temp * 2] != 1)
		{
			//printf("\n3. %d", visit[temp * 2]);
			cur = temp * 2;
			que_in(que, cur, num);
			visit[cur] = 1;
			time[cur] = time[temp] + 1;
		}
		if (temp * 2 == sis)	break;

		//how_much = how_much * 3;
	}

	printf("%d", time[cur]);
	return 0;
}

int main()
{
	int subin, sis;

	scanf("%d %d", &subin, &sis);
	int *que = (int *)malloc(sizeof(int) * sis * 2);
	int *visit = (int *)malloc(sizeof(int) * sis * 2);
	/*
	int **mat = (int **)malloc(sizeof(int*) * node);

	for (int x = 0; x < node; x++)
	{
	mat[x] = (int *)malloc(sizeof(int) * node);
	}*/

	BFS(que, visit, subin, sis);

	return 0;
}

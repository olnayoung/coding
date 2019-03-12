#include <stdio.h>

int main()
{
	int num;
	int city, airplane;
	int temp1, temp2;
	scanf("%d", &num);

	for (int x = 0; x < num; x++)
	{
		scanf("%d %d", &city, &airplane);

		for (int y = 0; y < airplane; y++)
		{
			scanf("%d %d", &temp1, &temp2);
		}

		printf("%d\n", city - 1);
	}
}

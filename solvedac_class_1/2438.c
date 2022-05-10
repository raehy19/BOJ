#include <stdio.h>s

int main()
{
	int size;

	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
			printf("\n");
		for (int j = 0; j < i + 1; j++)
			printf("*");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int *cnt;

	scanf("%d", &n);
	cnt = (int *) malloc (sizeof(int) * (n + 1));
	*(cnt + 1) = 0;
	for (int i = 2; i < n + 1; ++i)
	{
		*(cnt + i) = *(cnt + i - 1) + 1;
		if ((i % 3 == 0) && (*(cnt + i) > *(cnt + (i / 3)) + 1))
			*(cnt + i) = *(cnt + (i / 3)) + 1;
		if ((i % 2 == 0) && (*(cnt + i) > *(cnt + (i / 2)) + 1))
			*(cnt + i) = *(cnt + (i / 2)) + 1;
	}
	printf("%d", *(cnt + n));
	free(cnt);
	return (0);
}
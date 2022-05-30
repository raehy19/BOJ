#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		n;
	short	temp;
	int 	*count;

	scanf("%d", &n);
	count = (int *) malloc(sizeof(int) * 10000);
	for (int i = 0; i < 10000; ++i)
		*(count + i) = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%hd", &temp);
		++(*(count + temp - 1));
	}
	for (int i = 0; i < 10000; ++i)
		for (int j = 0; j < *(count + i); ++j)
			printf("%d\n", i + 1);
	free(count);
	return (0);
}
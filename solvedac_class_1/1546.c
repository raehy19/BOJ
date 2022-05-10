#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		size;
	double	*scores;
	double 	max = 0;
	double	total = 0;

	scanf("%d", &size);
	scores = (double *) malloc(sizeof(double) * size);
	for (int i = 0; i < size; i++)
		scanf("%lf", scores + i);
	for (int i = 0; i < size; i++)
		if (*(scores + i) > max)
			max = *(scores + i);
	for (int i = 0; i < size; i++)
		total += *(scores + i) / max * 100;
	total /= size;
	printf("%lf", total);
	free(scores);
	return 0;
}
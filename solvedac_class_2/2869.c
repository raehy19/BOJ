#include <stdio.h>

int main()
{
	int	a, b, v, distance_per_day, day_count;

	scanf("%d %d  %d", &a, &b, &v);
	if (a == v)
	{
		printf("1");
		return (0);
	}
	v -= a;
	distance_per_day = a - b;
	if (v % distance_per_day == 0)
		day_count = (v / distance_per_day) + 1;
	else
		day_count = (v / distance_per_day) + 2;
	printf("%d", day_count);
	return (0);
}
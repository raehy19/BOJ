#include <stdio.h>

int main()
{
	int	x, y, w, h;
	int min_distance = 1000;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	if (x < min_distance)
		min_distance = x;
	if (y < min_distance)
		min_distance = y;
	if ((w - x) < min_distance)
		min_distance = (w - x);
	if ((h - y) < min_distance)
		min_distance = (h - y);
	printf("%d", min_distance);
	return 0;
}
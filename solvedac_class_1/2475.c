#include <stdio.h>

int main()
{
	int a, b, c, d, e, x;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	x = (a * a + b * b + c * c + d * d + e * e) % 10;
	printf("%d", x);
	return 0;
}
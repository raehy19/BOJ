#include <stdio.h>

int main()
{
	int n, m, k;
	int next;

	scanf("%d %d %d", &n, &m, &k);
	next = m + k - 3;
	while (next < 1 || next > n)
	{
		if (next < 1)
			next += n;
		else if (next > n)
			next -= n;
	}
	printf("%d", next);
	return 0;
}
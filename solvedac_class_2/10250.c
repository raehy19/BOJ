#include <stdio.h>

int main()
{
	int	num_of_case, w, h, n;

	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d %d %d", &h, &w, &n);
		if (n % h == 0)
			printf("%d\n", h * 100 + (n / h));
		else
			printf("%d\n", (n % h) * 100 + (n / h + 1));
	}
	return (0);
}
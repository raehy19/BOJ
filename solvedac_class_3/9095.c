#include <stdio.h>

int main()
{
	int	num_of_case, temp;
	int answer[10];

	*(answer + 0) = 1;
	*(answer + 1) = 2;
	*(answer + 2) = 4;
	for (int i = 3; i < 10; ++i)
		*(answer + i) = *(answer + i - 1) + *(answer + i - 2) + *(answer + i - 3);
	scanf("%d", &num_of_case);
	for(int i = 0; i < num_of_case; ++i)
	{
		scanf("%d", &temp);
		printf("%d\n", *(answer + temp - 1));
	}
	return (0);
}
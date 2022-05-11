#include <stdio.h>

int main()
{
	int				size;
	unsigned char	nums[102];
	int				sum = 0;

	scanf("%d", &size);
	scanf("%s", nums);
	for (int i = 0; i < size; i++)
		sum += (*(nums + i) - '0');
	printf("%d", sum);
	return 0;
}
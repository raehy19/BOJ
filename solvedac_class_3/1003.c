#include <stdio.h>

int main()
{
	int					num_of_case, temp;
	unsigned long long	fibo_arr[41];

	*(fibo_arr + 0) = 0;
	*(fibo_arr + 1) = 1;
	for (int i = 2; i < 41; ++i)
		*(fibo_arr + i) = *(fibo_arr + i - 1) + *(fibo_arr + i - 2);
	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d", &temp);
		if (temp == 0)
			printf("1 0\n");
		else
			printf("%lld %lld\n", *(fibo_arr + temp - 1), *(fibo_arr + temp));
	}
	return (0);
}
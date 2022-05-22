#include <stdio.h>
#include <stdlib.h>

int main()
{
	int				l;
	long long		hash, r_with_power;
	char			*str;
	const long long r = 31;
	const long long	M = 1234567891;

	scanf("%d", &l);
	str = (char *) malloc (sizeof(char) * (l + 1));
	scanf("%s", str);
	hash = 0;
	r_with_power = 1;
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		hash += ((long long) (*(str + i) - 'a' + 1)) * r_with_power;
		hash %= M;
		r_with_power *= r;
		r_with_power %= M;
	}
	printf("%lld", hash);
	free(str);
	return (0);
}
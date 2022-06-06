#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i, result;

	i = 0;
	result = 0;
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	return (result);
}

long long	ft_hash(char *str)
{
	long long	hash, r_with_power;
	const long long r = 59;
	const long long	M = 199996169;

	hash = 0;
	r_with_power = 1;
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		hash += ((long long) (*(str + i) - 64)) * r_with_power;
		hash %= M;
		r_with_power *= r;
		r_with_power %= M;
	}
	return (hash);
}

int main()
{
	int 	n, m;
	char	**pokemons;
	int		*hash_map;
	char	question[21];

	scanf("%d %d", &n, &m);
	pokemons = (char **) malloc(sizeof(char *) * n);
	hash_map = (int *) malloc(sizeof(int) * 199996169);
	for (int i = 0; i < n; ++i)
	{
		*(pokemons + i) = (char *) malloc(sizeof(char) * 21);
		scanf("%s", *(pokemons + i));
		*(hash_map + ft_hash(*(pokemons + i))) = i + 1;
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", question);
		if (*(question) >= '0' && *(question) <= '9')
			printf("%s\n", *(pokemons + ft_atoi(question) - 1));
		else
			printf("%d\n", *(hash_map + ft_hash(question)));
	}
	for (int i = 0; i < n; ++i)
		free(*(pokemons + i));
	free(pokemons);
	free(hash_map);
	return (0);
}
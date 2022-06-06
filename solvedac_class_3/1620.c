#include <stdio.h>
#include <string.h>
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

int main()
{
	int 	n, m;
	char	**pokemons;
	char	question[21];

	scanf("%d %d", &n, &m);
	pokemons = (char **) malloc(sizeof(char *) * n);
	for (int i = 0; i < n; ++i)
	{
		*(pokemons + i) = (char *) malloc(sizeof(char) * 21);
		scanf("%s", *(pokemons + i));
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", question);
		if (*(question) >= '0' && *(question) <= '9')
			printf("%s\n", *(pokemons + ft_atoi(question) - 1));
		else
		{
			for (int j = 0; j < n; ++j)
			{
				if (strcmp(question, *(pokemons + j)) == 0)
				{
					printf("%d\n", j + 1);
					break ;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		free(*(pokemons + i));
	free(pokemons);
	return (0);
}
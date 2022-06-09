#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
	char			data_name[21];
	int 			data_num;
	struct s_node	*next;
} t_node;

int ft_atoi(char *str)
{
	int	result;

	result = 0;
	for (int i = 0; '0' <= *(str + i) && *(str + i) <= '9'; ++i)
		result = result * 10 + (*(str + i) - '0');
	return (result);
}

int	ft_hash(char *str)
{
	long long		hash, r_with_power;
	const long long r = 59;
	const long long M = 123479;

	hash = 0;
	r_with_power = 1;
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		hash += ((long long) (*(str + i) - 64)) * r_with_power;
		hash %= M;
		r_with_power *= r;
		r_with_power %= M;
	}
	return ((int) hash);
}

void ft_add_hash_map(t_node **hash_map, char *data_name, int data_num)
{
	int 	hash_idx;
	t_node	*temp_node, *new_node;

	hash_idx = ft_hash(data_name);
	new_node = (t_node *) malloc(sizeof(t_node));
	strcpy(new_node->data_name, data_name);
	new_node->data_num = data_num;
	new_node->next = NULL;
	if (*(hash_map + hash_idx) == NULL)
		*(hash_map + hash_idx) = new_node;
	else
	{
		temp_node = *(hash_map + hash_idx);
		while (temp_node->next != NULL)
			temp_node = temp_node->next;
		temp_node->next = new_node;
	}
}

int	ft_find_hash_map(t_node **hash_map, char *data_name)
{
	t_node	*temp_node;
	int		hash_idx;

	hash_idx = ft_hash(data_name);
	temp_node = *(hash_map + hash_idx);
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->data_name, data_name) == 0)
			return (temp_node->data_num);
		temp_node = temp_node->next;
	}
	return (-1);
}

int main()
{
	int		 		n, m;
	char 			**pokemons;
	char 			question[21];
	t_node 			**hash_map;
	const long long	hash_map_size = 123479;

	scanf("%d %d", &n, &m);
	pokemons = (char **) malloc(sizeof(char *) * n);
	hash_map = (t_node **) malloc(sizeof(t_node *) * hash_map_size);
	for (int i = 0; i < hash_map_size; ++i)
		*(hash_map + i) = NULL;
	for (int i = 0; i < n; ++i)
	{
		*(pokemons + i) = (char *) malloc(sizeof(char) * 21);
		scanf("%s", *(pokemons + i));
		ft_add_hash_map(hash_map, *(pokemons + i), i + 1);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", question);
		if (*(question) >= '0' && *(question) <= '9')
			printf("%s\n", *(pokemons + ft_atoi(question) - 1));
		else
			printf("%d\n", ft_find_hash_map(hash_map, question));
	}
	for (int i = 0; i < n; ++i)
		free(*(pokemons + i));
	free(pokemons);
	for (int i = 0; i < hash_map_size; ++i)
		if (*(hash_map + i) != NULL)
			free(*(hash_map + i));
	free(hash_map);
	return (0);
}
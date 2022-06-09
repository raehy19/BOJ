#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
	char			data_adr[21];
	char			data_pwd[21];
	struct s_node	*next;
} t_node;

int	ft_hash(char *str)
{
	long long		hash, r_with_power;
	const long long r = 83;
	const long long M = 123479;

	hash = 0;
	r_with_power = 1;
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		hash += ((long long) (*(str + i) - 44)) * r_with_power;
		hash %= M;
		r_with_power *= r;
		r_with_power %= M;
	}
	return ((int) hash);
}

void ft_add_hash_map(t_node **hash_map, char *data_adr, char *data_pwd)
{
	int 	hash_idx;
	t_node	*temp_node, *new_node;

	hash_idx = ft_hash(data_adr);
	new_node = (t_node *) malloc(sizeof(t_node));
	strcpy(new_node->data_adr, data_adr);
	strcpy(new_node->data_pwd, data_pwd);
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

t_node	*ft_find_by_adr_hash_map(t_node **hash_map, char *data_adr)
{
	int		hash_idx;
	t_node	*temp_node;

	hash_idx = ft_hash(data_adr);
	temp_node = *(hash_map + hash_idx);
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->data_adr, data_adr) == 0)
			return (temp_node);
		temp_node = temp_node->next;
	}
	return (NULL);
}

int main()
{
	int		 		n, m;
	char			input_adr[21];
	char			input_pwd[21];
	t_node 			**hash_map;
	t_node			*temp;
	const long long	hash_map_size = 123479;

	scanf("%d %d", &n, &m);
	hash_map = (t_node **) malloc(sizeof(t_node *) * hash_map_size);
	for (int i = 0; i < hash_map_size; ++i)
		*(hash_map + i) = NULL;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %s", input_adr, input_pwd);
		ft_add_hash_map(hash_map, input_adr, input_pwd);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", input_adr);
		temp = ft_find_by_adr_hash_map(hash_map, input_adr);
		if (temp != NULL)
			printf("%s\n", temp->data_pwd);
	}
	for (int i = 0; i < hash_map_size; ++i)
		if (*(hash_map + i) != NULL)
			free(*(hash_map + i));
	free(hash_map);
	return (0);
}
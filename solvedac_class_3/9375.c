#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
	char			data_clothes_type[21];
	int 			data_cnt;
	struct s_node	*next;
} t_node;

int	ft_hash(char *str)
{
	long long		hash, r_with_power;
	const long long r = 31;
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

t_node	*ft_find_hash_map(t_node **hash_map, char *clothes_type)
{
	t_node	*temp_node;
	int		hash_idx;

	hash_idx = ft_hash(clothes_type);
	temp_node = *(hash_map + hash_idx);
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->data_clothes_type, clothes_type) == 0)
			return (temp_node);
		temp_node = temp_node->next;
	}
	return (NULL);
}

void ft_add_hash_map(t_node **hash_map, char *clothes_type)
{
	int 	hash_idx;
	t_node	*temp_node, *new_node;

	temp_node = ft_find_hash_map(hash_map, clothes_type);
	if (temp_node != NULL)
	{
		++(temp_node->data_cnt);
	}
	else
	{
		hash_idx = ft_hash(clothes_type);
		new_node = (t_node *) malloc(sizeof(t_node));
		strcpy(new_node->data_clothes_type, clothes_type);
		new_node->data_cnt = 1;
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
}

int main()
{
	int				num_of_case, num_of_clothes, result;
	char			cloth_name[21];
	char			cloth_type[21];
	t_node			**hash_map;
	const long long	hash_map_size = 123479;

	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		result = 1;
		hash_map = (t_node **) malloc(sizeof(t_node *) * hash_map_size);
		for (int j = 0; j < hash_map_size; ++j)
			*(hash_map + j) = NULL;
		scanf("%d", &num_of_clothes);
		for (int j = 0; j < num_of_clothes; ++j)
		{
			scanf("%s %s", cloth_name, cloth_type);
			ft_add_hash_map(hash_map, cloth_type);
		}
		for (int j = 0; j < hash_map_size; ++j)
			if (*(hash_map + j) != NULL)
			{
				result *= ((*(hash_map + j))->data_cnt + 1);
				free(*(hash_map + j));
			}
		printf("%d\n", result - 1);
		free(hash_map);
	}
	return (0);
}
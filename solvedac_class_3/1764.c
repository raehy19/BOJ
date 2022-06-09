#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
	char			data_name[21];
	struct s_node	*next;
} t_node;

int	ft_compare_str(const void *a, const void *b)
{
	int strcmp_val;

	strcmp_val = strcmp(*((char **) a), *((char **) b));
	if (strcmp_val > 0)
		return (1);
	else if (strcmp_val < 0)
		return (-1);
	else
		return (0);
}

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

void ft_add_hash_map(t_node **hash_map, char *data_name)
{
	int 	hash_idx;
	t_node	*temp_node, *new_node;

	hash_idx = ft_hash(data_name);
	new_node = (t_node *) malloc(sizeof(t_node));
	strcpy(new_node->data_name, data_name);
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

char	*ft_find_hash_map(t_node **hash_map, char *data_name)
{
	t_node	*temp_node;
	int		hash_idx;

	hash_idx = ft_hash(data_name);
	temp_node = *(hash_map + hash_idx);
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->data_name, data_name) == 0)
			return (temp_node->data_name);
		temp_node = temp_node->next;
	}
	return (NULL);
}

int main()
{
	int		 		n, m, temp, result_arr_idx;
	char			input_str[21];
	char			**result_arr;
	t_node 			**hash_map;
	const long long	hash_map_size = 123479;

	scanf("%d %d", &n, &m);
	hash_map = (t_node **) malloc(sizeof(t_node *) * hash_map_size);
	for (int i = 0; i < hash_map_size; ++i)
		*(hash_map + i) = NULL;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", input_str);
		ft_add_hash_map(hash_map, input_str);
	}
	if (n < m)
		temp = n;
	else
		temp = m;
	result_arr = (char **) malloc(sizeof(char *) * temp);
	result_arr_idx = 0;
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", input_str);
		if (ft_find_hash_map(hash_map, input_str) != NULL)
		{
			*(result_arr + result_arr_idx) = strdup(input_str);
			++result_arr_idx;
		}
	}
	qsort(result_arr, result_arr_idx, sizeof(char *), ft_compare_str);
	printf("%d\n", result_arr_idx);
	for (int i = 0; i < result_arr_idx; ++i)
	{
		printf("%s\n", *(result_arr + i));
		free(*(result_arr + i));
	}
	free(result_arr);
	for (int i = 0; i < hash_map_size; ++i)
		if (*(hash_map + i) != NULL)
			free(*(hash_map + i));
	free(hash_map);
	return (0);
}
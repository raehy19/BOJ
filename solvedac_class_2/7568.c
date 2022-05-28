#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int weight;
	int	height;
	int idx;
	int rank;
} t_data;

int	ft_compare_idx(const void *a, const void *b)
{
	if (((t_data *) a)->idx > ((t_data *) b)->idx)
		return (1);
	else if (((t_data *) a)->idx < ((t_data *) b)->idx)
		return (-1);
	else
		return (0);
}

int	ft_compare_weight_height(const void *a, const void *b)
{
	if ((((t_data *) a)->weight < ((t_data *) b)->weight)
		&& (((t_data *) a)->height < ((t_data *) b)->height))
		return (1);
	else if ((((t_data *) a)->weight > ((t_data *) b)->weight)
		&& (((t_data *) a)->height > ((t_data *) b)->height))
		return (-1);
	else
		return (0);
}

int main()
{
	int		n, temp;
	t_data	*datas;

	scanf("%d", &n);
	datas = (t_data *) malloc(sizeof (t_data) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &(datas + i)->weight, &(datas + i)->height);
		(datas + i)->idx = i;
	}
	qsort(datas, n, sizeof(t_data), ft_compare_weight_height);
	temp = 1;
	datas->rank = 1;
	for (int i = 1; i < n; ++i)
	{
		if (ft_compare_weight_height((datas + i - 1), (datas + i)) == -1)
			temp = i + 1;
		(datas + i)->rank = temp;
	}
	qsort(datas, n, sizeof(t_data), ft_compare_idx);
	for (int i = 0; i < n; ++i)
		printf("%d ", (datas + i)->rank);
	free(datas);
	return (0);
}
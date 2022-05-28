#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int weight;
	int	height;
} t_data;

int	ft_is_bigger(t_data *a, t_data *b)
{
	if ((a->weight > b->weight) && (a->height > b->height))
		return (1);
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
		scanf("%d %d", &(datas + i)->weight, &(datas + i)->height);
	for (int i = 0; i < n; ++i)
	{
		temp = 1;
		for (int j = 0; j < n; ++j)
			if (ft_is_bigger((datas + j), (datas + i)) == 1)
				++temp;
		printf("%d ", temp);
	}
	free(datas);
	return (0);
}
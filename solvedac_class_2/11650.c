#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int x;
	int	y;
} t_data;

int	ft_compare_x_y(const void *a, const void *b)
{
	if (((t_data *) a)->x > ((t_data *) b)->x)
		return (1);
	else if (((t_data *) a)->x < ((t_data *) b)->x)
		return (-1);
	else
	{
		if (((t_data *) a)->y > ((t_data *) b)->y)
			return (1);
		else if (((t_data *) a)->y < ((t_data *) b)->y)
			return (-1);
		else
			return (0);
	}
}

int main()
{
	int		n;
	t_data	*datas;

	scanf("%d", &n);
	datas = (t_data *) malloc(sizeof (t_data) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &(datas + i)->x, &(datas + i)->y);
	qsort(datas, n, sizeof(t_data), ft_compare_x_y);
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", (datas + i)->x, (datas + i)->y);
	free(datas);
	return (0);
}
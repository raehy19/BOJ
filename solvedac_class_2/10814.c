#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int 	age;
	char	name[101];
	int 	idx;
} t_data;

int	ft_compare_age_name(const void *a, const void *b)
{
	if (((t_data *) a)->age > ((t_data *) b)->age)
		return (1);
	else if (((t_data *) a)->age < ((t_data *) b)->age)
		return (-1);
	else
	{
		if (((t_data *) a)->idx > ((t_data *) b)->idx)
			return (1);
		if (((t_data *) a)->idx < ((t_data *) b)->idx)
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
	{
		scanf("%d %s", &(datas + i)->age, (datas + i)->name);
		(datas + i)->idx = i;
	}
	qsort(datas, n, sizeof(t_data), ft_compare_age_name);
	for (int i = 0; i < n; ++i)
		printf("%d %s\n", (datas + i)->age, (datas + i)->name);
	free(datas);
	return (0);
}
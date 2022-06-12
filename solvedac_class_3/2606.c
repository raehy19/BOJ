#include <stdio.h>
#include <stdlib.h>

int ft_find_virus(int **graph, int *is_visit, int node_cnt, int current_node_idx)
{
	int	virus_cnt;

	virus_cnt = 0;
	if (*(is_visit + current_node_idx) == 0)
	{
		*(is_visit + current_node_idx) = 1;
		++virus_cnt;
		for (int i = 0; i < node_cnt; ++i)
			if (*(*(graph + current_node_idx) + i) == 1)
				virus_cnt += ft_find_virus(graph, is_visit, node_cnt, i);
	}
	return (virus_cnt);
}

int main()
{
	int	node_cnt, edge_cnt, node_1, node_2;
	int	**graph;
	int *is_visit;

	scanf("%d\n%d", &node_cnt, &edge_cnt);
	graph = (int **) malloc(sizeof(int *) * (node_cnt));
	for (int i = 0; i < node_cnt + 1; ++i)
		*(graph + i) = (int *) malloc(sizeof(int) * (node_cnt));
	for (int i = 0; i < node_cnt; ++i)
		for (int j = 0; j < node_cnt; ++j)
			*(*(graph + i)+ j) = 0;
	is_visit = (int *) malloc(sizeof(int) * (node_cnt));
	for (int i = 0; i < node_cnt; ++i)
		*(is_visit + i) = 0;
	for (int i = 0; i < edge_cnt; ++i)
	{
		scanf("%d %d", &node_1, &node_2);
		*(*(graph + node_1 - 1)+ node_2 - 1) = 1;
		*(*(graph + node_2 - 1)+ node_1 - 1) = 1;
	}
	printf("%d", ft_find_virus(graph, is_visit, node_cnt, 0) - 1);
	return (0);
}
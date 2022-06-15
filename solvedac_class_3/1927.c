#include <stdio.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_heap_push(int *heap, int *heap_idx, int data)
{
	int	temp_idx;

	temp_idx = ++(*heap_idx);
	*(heap + (*heap_idx)) = data;
	while ((temp_idx > 1) && (*(heap + temp_idx) < *(heap + (temp_idx / 2))))
	{
		ft_swap((heap + temp_idx), (heap + (temp_idx / 2)));
		temp_idx /= 2;
	}
}

int	ft_heap_pop(int *heap, int *heap_idx)
{
	int	value, parent, child;

	value = *(heap + 1);
	*(heap + 1) = *(heap + *heap_idx);
	--(*heap_idx);
	parent = 1;
	while (1)
	{
		child = parent * 2;
		if ((child + 1 <= *heap_idx) && (*(heap + child) > *(heap + child + 1)))
			++child;
		if (child > *heap_idx || *(heap + child) > *(heap + parent))
			break ;
		ft_swap((heap + child),(heap + parent));
		parent = child;
	}
	return (value);
}

int main()
{
	int	n, input, heap_idx;
	int	*heap;

	scanf("%d", &n);
	heap = (int *) malloc(sizeof(int) * (n + 1));
	heap_idx = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &input);
		if (input > 0)
			ft_heap_push(heap, &heap_idx, input);
		else
		{
			if (heap_idx == 0)
				printf("0\n");
			else
				printf("%d\n", ft_heap_pop(heap, &heap_idx));
		}
	}
	free(heap);
	return (0);
}
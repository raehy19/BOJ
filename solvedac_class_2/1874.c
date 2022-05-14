#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node*	next;
} t_node;

void	ft_push(t_node **top_node, int data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = *top_node;
	*top_node = new_node;
}

int ft_pop(t_node **top_node)
{

	int 	data;
	t_node	*temp = *top_node;
	data = temp->data;
	*top_node = temp->next;
	free(temp);

	return (data);
}

int main()
{
	int 	n;
	int 	num = 1;
	int		*arr;
	char	*operators;
	int 	op_idx = 0;

	t_node	*stack = NULL;

	scanf("%d", &n);
	arr = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	operators = (char *) malloc(sizeof(char) * (2 * n + 1));
	*(operators + (2 * n)) = '\0';
	for (int i = 0; i < n; ++i)
	{
		if (stack == NULL)
		{
			ft_push(&stack, num);
			++num;
			*(operators + op_idx) = '+';
			++op_idx;
		}
		if (stack->data > *(arr + i))
			break ;
		else if (stack->data == *(arr + i))
		{
			ft_pop(&stack);
			*(operators + op_idx) = '-';
			++op_idx;
		}
		else
		{
			while (stack->data < *(arr + i))
			{
				ft_push(&stack, num);
				++num;
				*(operators + op_idx) = '+';
				++op_idx;
			}
			ft_pop(&stack);
			*(operators + op_idx) = '-';
			++op_idx;
		}
	}
	if (stack != NULL)
		printf("NO");
	else
	{
		for (int i = 0; *(operators + i) != '\0'; ++i)
		{
			if (i != 0)
				printf("\n");
			printf("%c", *(operators + i));
		}
	}
	free(arr);
	while (stack != NULL)
		ft_pop(&stack);
	free(operators);
	return 0;
}
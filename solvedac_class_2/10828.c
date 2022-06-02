#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
} t_node;

void	ft_push(t_node **top_node, int data, int *stack_size)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = *top_node;
	*top_node = new_node;
	++(*(stack_size));
}

int ft_pop(t_node **top_node, int *stack_size)
{
	int 	data;
	t_node	*temp = *top_node;

	data = temp->data;
	*top_node = temp->next;
	free(temp);
	--(*(stack_size));
	return (data);
}

int main()
{
	int		n, temp, stack_size = 0;
	char	command[6];
	t_node	*stack = NULL;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &temp);
			ft_push(&stack, temp, &stack_size);
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (stack_size > 0)
				printf("%d\n", ft_pop(&stack, &stack_size));
			else
				printf("-1\n");
		}
		else if (strcmp(command, "size") == 0)
			printf("%d\n", stack_size);
		else if (strcmp(command, "empty") == 0)
		{
			if (stack_size > 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (strcmp(command, "top") == 0)
		{
			if (stack_size > 0)
				printf("%d\n", stack->data);
			else
				printf("-1\n");
		}
	}
	while (stack != NULL)
		ft_pop(&stack, &stack_size);
	return (0);
}
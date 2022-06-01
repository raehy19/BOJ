#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	char			data;
	struct s_node	*next;
} t_node;

void	ft_push(t_node **top_node, char data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = *top_node;
	*top_node = new_node;
}

char ft_pop(t_node **top_node)
{
	char 	data;
	t_node	*temp = *top_node;

	data = temp->data;
	*top_node = temp->next;
	free(temp);
	return (data);
}

int main()
{
	char	line[102];
	int 	i;
	t_node	*stack = NULL;

	while (1)
	{
		fgets(line, 102, stdin);
		if (strcmp(line, ".\n") == 0)
			return (0);
		i = 0;
		while (*(line + i) != '.')
		{
			if (*(line + i) == '[')
				ft_push(&stack, '[');
			else if (*(line + i) == '(')
				ft_push(&stack, '(');
			else if (*(line + i) == ']')
			{
				if (stack == NULL || stack->data != '[')
					break;
				else
					ft_pop(&stack);
			}
			else if (*(line + i) == ')')
			{
				if (stack == NULL || stack->data != '(')
					break;
				else
					ft_pop(&stack);
			}
			++i;
		}
		if (*(line + i) == '.' && stack == NULL)
				printf("yes\n");
		else
		{
			printf("no\n");
			while (stack != NULL)
				ft_pop(&stack);
		}
	}
}
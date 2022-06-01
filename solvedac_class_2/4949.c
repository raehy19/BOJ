#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	char	temp;
	int 	len;
	t_node	*stack = NULL;

	temp = '\0';
	while (1)
	{
		len = 0;
		while (temp != '.')
		{
			read(0, &temp, 1);
			if (temp == '[')
				ft_push(&stack, '[');
			else if (temp == '(')
				ft_push(&stack, '(');
			else if (temp == ']')
			{
				if (stack == NULL || stack->data != '[')
					break;
				else
					ft_pop(&stack);
			}
			else if (temp == ')')
			{
				if (stack == NULL || stack->data != '(')
					break;
				else
					ft_pop(&stack);
			}
			++len;
		}
		if (temp == '.')
		{
			if (len == 1)
				return (0);
			else if (stack == NULL)
				printf("yes\n");
		}
		else
		{
			printf("no\n");
			while (stack != NULL)
				ft_pop(&stack);
			while (temp != '.')
				read(0, &temp, 1);
		}
		read(0, &temp, 1);
	}
}
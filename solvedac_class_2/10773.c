#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
} t_node;

void	ft_push(t_node **top_node, int data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
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
	int		k, temp;
	t_node	*stack = NULL;

	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &temp);
		if (temp == 0)
			ft_pop(&stack);
		else
			ft_push(&stack, temp);
	}
	temp = 0;
	while (stack != NULL)
		temp += ft_pop(&stack);
	printf("%d", temp);
	return (0);
}
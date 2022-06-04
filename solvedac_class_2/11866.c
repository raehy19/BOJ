#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	struct s_node	*previous;
	struct s_node	*next;
	int				data;
} t_node;

typedef struct s_circular_linked_list
{
	struct s_node	*head;
	int				size;
} t_circular_linked_list;

void	ft_push(t_circular_linked_list *list, int data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	if (list->size < 1)
	{
		new_node->previous = NULL;
		new_node->next = NULL;
		list->head = new_node;
	}
	else if (list->size == 1)
	{
		new_node->previous = list->head;
		new_node->next = list->head;
		list->head->previous = new_node;
		list->head->next = new_node;
	}
	else
	{
		new_node->previous = list->head->previous;
		new_node->next = list->head;
		list->head->previous->next = new_node;
		list->head->previous = new_node;
	}
	++(list->size);
}

int	ft_pop(t_circular_linked_list *list, t_node *target_node)
{
	int 	data;

	if (list->size < 1)
		return (-1);
	data = target_node->data;
	if (list->size > 1 && list->head == target_node)
		list->head = target_node->next;
	if (list->size == 2)
	{
		target_node->previous->next = NULL;
		target_node->next->previous = NULL;
	}
	else if (list->size > 2)
	{
		target_node->previous->next = target_node->next;
		target_node->next->previous = target_node->previous;
	}
	free(target_node);
	--(list->size);
	return (data);
}

int main()
{
	int 					n, k;
	t_circular_linked_list	list;
	t_node					*target_node;

	list.head = NULL;
	list.size = 0;
	scanf("%d %d", &n, &k);
	printf("<");
	for (int i = 0; i < n; ++i)
		ft_push(&list, i + 1);
	if (list.size > 1)
	{
		target_node = list.head;
		while (list.size > 1)
		{
			for (int i = 0; i < (k % list.size); ++i)
				target_node = target_node->next;
			printf("%d, ", ft_pop(&list, target_node->previous));
		}
	}
	if (list.size == 1)
		printf("%d", ft_pop(&list, list.head));
	printf(">");
	return (0);
}
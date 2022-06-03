#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*previous;
} t_node;

typedef struct s_deque
{
	struct s_node	*front_node;
	struct s_node	*rear_node;
	int				size;
} t_deque;

void	ft_push_front(t_deque *deque, int data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->previous = NULL;
	if (deque->size < 1)
	{
		new_node->next = NULL;
		deque->rear_node = new_node;
	}
	else
	{
		new_node->next = deque->front_node;
		deque->front_node->previous = new_node;
	}
	deque->front_node = new_node;
	++(deque->size);
}

void	ft_push_back(t_deque *deque, int data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	if (deque->size < 1)
	{
		new_node->previous = NULL;
		deque->front_node = new_node;
	}
	else
	{
		new_node->previous = deque->rear_node;
		deque->rear_node->next = new_node;
	}
	deque->rear_node = new_node;
	++(deque->size);
}

int	ft_pop_front(t_deque *deque)
{
	t_node	*temp;
	int 	data;

	if (deque->size < 1)
		return (-1);
	else if (deque->size > 1)
		deque->front_node->next->previous = NULL;
	else
		deque->rear_node = NULL;
	temp = deque->front_node;
	deque->front_node = temp->next;
	--(deque->size);
	data = temp->data;
	free(temp);
	return (data);
}

int	ft_pop_back(t_deque *deque)
{
	t_node	*temp;
	int 	data;

	if (deque->size < 1)
		return (-1);
	if (deque->size > 1)
		deque->rear_node->previous->next = NULL;
	else
		deque->front_node = NULL;
	temp = deque->rear_node;
	deque->rear_node = temp->previous;
	--(deque->size);
	data = temp->data;
	free(temp);
	return (data);
}

int main()
{
	int		n, temp;
	char	command[11];
	t_deque	deque;

	deque.front_node = NULL;
	deque.rear_node = NULL;
	deque.size = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", command);
		if (strcmp(command, "push_front") == 0)
		{
			scanf("%d", &temp);
			ft_push_front(&deque, temp);
		}
		else if (strcmp(command, "push_back") == 0)
		{
			scanf("%d", &temp);
			ft_push_back(&deque, temp);
		}
		else if (strcmp(command, "pop_front") == 0)
			printf("%d\n", ft_pop_front(&deque));
		else if (strcmp(command, "pop_back") == 0)
			printf("%d\n", ft_pop_back(&deque));
		else if (strcmp(command, "size") == 0)
			printf("%d\n", deque.size);
		else if (strcmp(command, "empty") == 0)
		{
			if (deque.size > 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (strcmp(command, "front") == 0)
		{
			if (deque.size > 0)
				printf("%d\n", deque.front_node->data);
			else
				printf("-1\n");
		}
		else if (strcmp(command, "back") == 0)
		{
			if (deque.size > 0)
				printf("%d\n", deque.rear_node->data);
			else
				printf("-1\n");
		}
	}
	while (deque.size > 0)
		ft_pop_front(&deque);
	return (0);
}
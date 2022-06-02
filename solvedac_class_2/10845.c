#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
} t_node;

typedef struct s_queue
{
	struct s_node	*front_node;
	struct s_node	*rear_node;
	int				size;
} t_queue;

void	ft_enqueue(t_queue *queue, int data)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	if (queue->size == 0)
	{
		queue->front_node = new_node;
		queue->rear_node = new_node;
		++(queue->size);
		return ;
	}
	queue->rear_node->next = new_node;
	queue->rear_node = new_node;
	++(queue->size);
}

int	ft_dequeue(t_queue *queue)
{
	t_node	*temp;
	int 	data;

	temp = queue->front_node;
	queue->front_node = temp->next;
	if (queue->size == 1)
		queue->rear_node = NULL;
	--(queue->size);
	data = temp->data;
	free(temp);
	return (data);
}

int main()
{
	int		n, temp;
	char	command[6];
	t_queue	queue;

	queue.front_node = NULL;
	queue.rear_node = NULL;
	queue.size = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &temp);
			ft_enqueue(&queue, temp);
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (queue.size > 0)
				printf("%d\n", ft_dequeue(&queue));
			else
				printf("-1\n");
		}
		else if (strcmp(command, "size") == 0)
			printf("%d\n", queue.size);
		else if (strcmp(command, "empty") == 0)
		{
			if (queue.size > 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (strcmp(command, "front") == 0)
		{
			if (queue.size > 0)
				printf("%d\n", queue.front_node->data);
			else
				printf("-1\n");
		}
		else if (strcmp(command, "back") == 0)
		{
			if (queue.size > 0)
				printf("%d\n", queue.rear_node->data);
			else
				printf("-1\n");
		}
	}
	while (queue.size > 0)
		ft_dequeue(&queue);
	return (0);
}
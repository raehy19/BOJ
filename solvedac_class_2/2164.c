#include <stdio.h>
#include <stdlib.h>

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

t_node	*ft_dequeue(t_queue *queue)
{
	t_node	*temp;

	if (queue->size == 0)
		return NULL;
	temp = queue->front_node;
	queue->front_node = temp->next;
	if (queue->size == 1)
		queue->rear_node = NULL;
	--(queue->size);
	return (temp);
}

int main()
{
	int		n;
	t_queue	queue;
	t_node	*temp;

	queue.front_node = NULL;
	queue.rear_node = NULL;
	queue.size = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		ft_enqueue(&queue, i + 1);
	for (int i = 0; queue.size > 1; ++i)
	{
		temp = ft_dequeue(&queue);
		if (i % 2 == 0)
			free(temp);
		else
		{
			ft_enqueue(&queue, temp->data);
			free(temp);
		}
	}
	temp = ft_dequeue(&queue);
	printf("%d", temp->data);
	free(temp);
	return (0);
}
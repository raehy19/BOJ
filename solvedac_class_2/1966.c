#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	int 			node_id;
	struct s_node	*next;
} t_node;

typedef struct s_queue
{
	struct s_node	*front_node;
	struct s_node	*rear_node;
	int				size;
} t_queue;

void	ft_enqueue(t_queue *queue, int data, int node_id)
{
	t_node *new_node = NULL;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->node_id = node_id;
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

void	ft_reset_queue(t_queue *queue)
{
	t_node	*temp;

	while (queue->size > 0)
	{
		temp = ft_dequeue(queue);
		free(temp);
	}
}

int ft_is_priority_high(t_queue *queue, int data)
{
	t_node	*node;

	node = queue->front_node;
	while (node != NULL)
	{
		if (node->data > data)
			return 0;
		node = node->next;
	}
	return 1;
}

int main()
{
	int		num_of_case, num_of_files, file_id, file_data, print_count;
	t_queue	queue;
	t_node	*temp;

	queue.front_node = NULL;
	queue.rear_node = NULL;
	queue.size = 0;
	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		ft_reset_queue(&queue);
		scanf("%d %d", &num_of_files, &file_id);
		for (int j = 0; j < num_of_files; ++j)
		{
			scanf("%d", &file_data);
			ft_enqueue(&queue, file_data, j);
		}
		print_count = 1;
		while (1)
		{
			temp = ft_dequeue(&queue);
			if (ft_is_priority_high(&queue, temp->data))
			{
				if (temp->node_id == file_id)
				{
					printf("%d\n",print_count);
					free(temp);
					break ;
				}
				free(temp);
				++print_count;
			}
			else
			{
				ft_enqueue(&queue, temp->data, temp->node_id);
				free(temp);
			}
		}
	}
	ft_reset_queue(&queue);
	return 0;
}
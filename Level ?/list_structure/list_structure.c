#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}		t_node;

void	add(struct s_node **head, int data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (struct s_node *)malloc(sizeof(struct s_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	init(struct s_node **head)
{
	*head = NULL;
}

void	print(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	main(void)
{
	t_node	*head;

	init(&head);
	add(&head, 1);
	add(&head, 2);
	add(&head, 3);
	add(&head, 4);
	add(&head, 5);
	print(head);
	free_list(head);
	return (0);
}

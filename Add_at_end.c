#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
/*struct node *create_node(int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	nu->data = data;
	nu->prev = NULL;
	nu->next = NULL;
	return nu;
}*/
void Add_end(struct node **ptr, int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	struct node *temp = NULL;
	nu->data = data;
	nu->prev = NULL;
	nu->next = NULL;
	if(*ptr == NULL)
	{
		*ptr = nu;
		return;
	}
	else
	{
		temp = *ptr;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = nu;
		nu->prev = temp;
	}
}
void Delete_at_end(struct node **ptr)
{
	struct node *temp = NULL;
	if(*ptr == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
/*	temp = *ptr;
	if(temp->prev == NULL)
	{
		free(temp);
		*ptr = NULL;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);

	printf("Last node deleted from the linked list\n");
	*/
	temp = *ptr;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	if(temp->prev == NULL)
	{
		free(temp);
		*ptr = NULL;
	}
	else
	{
		temp->prev->next = NULL;
		free(temp);
	}
	printf("last node deleted from the linked list\n");
}
void Reverse(struct node **ptr)
{
	struct node *curr = *ptr;
	struct node *temp = *ptr;
	while(curr != NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	if(temp != NULL)
	{
		*ptr = temp->prev;
	}
	printf("Reverse nodes of a linked list\n");
}
void Delete_all(struct node **ptr)
{
	struct node *curr = *ptr;
	struct node *temp = *ptr;
	if(*ptr == NULL)
	{
		printf("Linked list empty\n");
		return;
	}
	while(curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*ptr = NULL;
	printf("All nodes are deleted from the linked list\n");
}
/*void Reverse(struct node **ptr)
{
	struct node *curr = *ptr;
	struct node *temp = *ptr;
	while(curr != NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	if(temp != NULL)
	{
		*ptr = temp->prev;
	}
	printf("Reverse nodes of a linked list\n");
}*/
void Print(struct node *ptr)
{
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	else
	{
		while(ptr)
		{
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
int main()
{
	struct node *head = NULL;
	int i;
	for(i=1; i<=10; i++)
	{
		Add_end(&head,i*3);
	}
	printf("Doubly linked list of Add at End\n");
	Print(head);
	Delete_at_end(&head);
	Print(head);
	Reverse(&head);
	Print(head);
	Delete_all(&head);
	Print(head);
}


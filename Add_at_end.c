#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void Add_at_end(struct node **ptr, int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	struct node *temp = NULL;
	nu->data = data;
	nu->next = NULL;
	if(*ptr == NULL)
	{
		*ptr = nu;
		return;
	}
	else
	{
		temp = *ptr;
		while(temp -> next)
		{
			temp = temp->next;
		}
		temp ->next = nu;
	}
}
/*void Delete(struct node **ptr)
{
	struct node *temp = NULL;
	if(*ptr == NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	if((*ptr)->next == NULL)
	{
		free(*ptr);
		*ptr = NULL;
		printf("Node deleted\n");
		return;
	}
	temp = *ptr;
	while(temp->next->next)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	printf("Last node got deleted\n");
}*/
/*void Delete_all(struct node **ptr)
{
	struct node *curr = *ptr;
	struct node *temp;
	if(*ptr == NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	else
	{
		while(curr != NULL)
		{
			temp = curr->next;
			free(curr);
			curr = temp;
		}
	}
	*ptr = NULL;
	printf("All Nodes are Deleted\n");
}
*/			
void Reverse(struct node **ptr)
{
	struct node *post = NULL;
	struct node *prev = NULL;
	while(*ptr != NULL)
	{
		post = (*ptr)->next;
		(*ptr)->next = prev;
		prev = *ptr;
		*ptr = post;
	}
	*ptr = prev;
	printf("Reverse of a linked list\n");
}
void Print(struct node *ptr)
{
	if(ptr == NULL)
	{
		printf("linked list is empty\n");
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
	int i = 0;
	for(i = 1; i<10; i++)
	{
		Add_at_end(&head,i*3);
	}
	printf("Linked List\n");
	Print(head);
//	Delete(&head);
//	Print(head);
//	Delete_all(&head);
//	Print(head);
	Reverse(&head);
	Print(head);
}

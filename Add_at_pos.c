#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
void Add_at_end(struct node **ptr, int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	struct node *temp = NULL;
	nu->data = data;
	nu->prev = NULL;
	nu->next = NULL;

	if(*ptr == NULL)
	{
		*ptr = nu;
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
void Add_at_middle(struct node **ptr, int data, int pos)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	struct node *temp = NULL;
	nu->data = data;
	nu->prev = NULL;
	nu->next = NULL;
	
	if(pos == 0)
	{
		*ptr = nu;
		return;
	}
	else
	{
		temp = *ptr;
		int i = 0;
		//while(i < pos-1 && temp->next != NULL)
		while(i < pos-1 && temp->next != NULL)
		{
			temp = temp->next;
			i++;
		}
		nu->next = temp->next;
		nu->prev = temp;
		temp->next = nu;
		if(temp->next !=NULL)
		{
			nu->next->prev = nu;
		}
	}
}
void Delete_at_pos(struct node **ptr,int pos)
{
	struct node *temp = NULL;
	if(*ptr == NULL)
	{
		printf(" Linked list is empty\n");
		return;
	}
	else
	{
		temp = *ptr;
		int i = 0;
		while(i < pos-1 && temp->next)
		{
			temp = temp->next;
			i++;
		}
		temp->next = temp->next->next;
		temp->next->next->prev = temp->next;
		free(temp->next);
	}
}
void Print(struct node *ptr)
{
	if(ptr == NULL)
	{
		printf("Linked List is Empty\n");
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
	int i,pos;
	printf("Enter a position\n");
	scanf("%d",&pos);
	for(i=1; i<7; i++)
	{
		Add_at_end(&head,i);
	}
	Add_at_middle(&head,99,pos);
	printf("Modified Doubly linked list\n");
	Print(head);
	Delete_at_pos(&head,pos);
	printf("Modified Doubly linked list Deleted\n");
	Print(head);
}


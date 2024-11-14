#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void Add(struct node **ptr, int data)
{
	struct node *nu =(struct node *)malloc(sizeof(struct node));
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
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = nu;
	}
}
void Add_at_pos(struct node **ptr, int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	struct node *temp = NULL;
	int pos;
	printf("Enter a position\n");
	scanf("%d",&pos);
	nu->data = data;
	nu->next = NULL;
	pos--;
	if(pos == 0)
	{
		nu->next = *ptr;
		*ptr = nu;
		return;
	}
	else
	{
		temp = *ptr;
	while(pos != 1)
	{
		temp = temp->next;
		pos--;
	}
	nu->next = temp->next;
	temp->next = nu;
	}
}
void Delete(struct node **ptr)
{
	struct node *prev = NULL;
	struct node *curr = NULL;
	int pos;
	printf("Enter a position\n");
	scanf("%d",&pos);
	if(*ptr == NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	else if(pos == 1)
	{
		*ptr = curr->next;
		free(curr);
		curr = NULL;
	}
	else
	{
		prev = *ptr;
		curr = *ptr;
		while(pos != 1)
		{
			prev = curr;
			curr = curr->next;
			pos--;
		}
		prev->next = curr->next;
		free(curr);
		curr = NULL;
	}
	printf("Node Deleted at particular position\n");
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
	int i =0;
	for(i=1; i<7; i++)
	{
		Add(&head,i*4);
	}
	Add_at_pos(&head,99);
	printf("linked list\n");
	Print(head);
	Delete(&head);
	Print(head);
}


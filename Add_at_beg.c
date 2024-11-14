#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void Add_at_beg(struct node **ptr, int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node *));
	nu->data = data;
	if(*ptr == NULL)
	{
		*ptr = nu;
		return;
	}
	else
	{
		nu->next = *ptr;
		*ptr = nu;
	}
}
void Delete(struct node **ptr)
{
	struct node *temp = NULL;
	if(*ptr == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	else
	{
		temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);
	}
}
void Print(struct node *ptr)
{
	if(ptr == NULL)
	{
		printf("Linked list is empty\n");
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
	int i=0;
	for(i=1; i<5; i++)
	{
		Add_at_beg(&head,i*2);
	}
	printf("Linked List \n");
	Print(head);
	Delete(&head);
	printf("Modified Linked list\n");
	Print(head);
}

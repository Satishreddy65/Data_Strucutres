#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
void Add_begin(struct node **ptr, int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	nu->data = data;
	nu->prev = NULL;
	nu->next = NULL;
	if(*ptr == NULL)
	{
		nu->next = *ptr;
		*ptr = nu;
	}
	else
	{
		(*ptr)->prev = nu;
		nu->next = *ptr;
		*ptr = nu;
	}

/*	if(*ptr != NULL)
	{
		nu->next = *ptr;
		(*ptr)->prev = nu;
		
	}
	*ptr = nu;*/

}
void Delete(struct node **ptr)
{
	struct node *temp = NULL;
	if(*ptr == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	temp = *ptr;
	*ptr = (*ptr)->next;
	if(*ptr != NULL)
	{
		(*ptr)->prev = NULL;
	}
	free(temp);
	printf("Node deleted from the beginning\n");
}
void Print(struct node *ptr)
{
	if(ptr == NULL)
	{
		printf("linked list is NULL\n");
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
	int i=0;
	for(i=1; i<7; i++)
	{
		Add_begin(&head,i*2);
	}
	printf("Node Added from the beginning\n");
	Print(head);
	Delete(&head);
	Print(head);
}


#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *create_node(int data)
{
	struct node *nu = (struct node *)malloc(sizeof(struct node));
	nu->data = data;
	nu->next = NULL;
	nu->prev = NULL;
	return nu;
}


void Add_begin(struct node **ptr, int new_data)
{
	struct node *nu = create_node(new_data);
	if(*ptr != NULL)
	{
		nu->next = *ptr;
		(*ptr)->prev = nu;
	}
	*ptr = nu;
}
void Print(struct node *ptr)
{
	if(ptr == NULL)
	{
		printf("linked list is empty\n");
	printf("\n");
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
	for(i=1; i<=5; i++)
	{
		Add_begin(&head,i*2);
	}
	printf("Double linked list\n");
	Print(head);
}


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void insertAtEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
        return;
    }

    // Edge case nai

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 67;
    temp->link = NULL;

    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->link;
    }

    ptr = temp;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 20;
    temp->link = NULL;

    head->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 30;
    temp->link = NULL;
    head->link->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 40;
    temp->link = NULL;
    head->link->link->link = temp;

    printf("From custom function : ");
    insertAtEnd(head);

    
    printf("\n");
    printf("From main function : ");
    printf("%d %d %d %d %d", head->data, head->link->data, head->link->link->data, head->link->link->link->data, head->link->link->link->link->data );

    return 0;
}
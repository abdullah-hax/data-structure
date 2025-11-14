#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void insertAtBeg(struct node *head)
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

    temp->link = head;
    head = temp;

    
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
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

    insertAtBeg(head);

    return 0;
}

/* 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node * insertAtBeg(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
        return NULL;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 67;
    temp->link = NULL;

    temp->link = head;
    head = temp;
 
    return head;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\nAfter deleting: ");
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

    printList(head);
    head = insertAtBeg(head);
    printList(head);

    return 0;
}


*/
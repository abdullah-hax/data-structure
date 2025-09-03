
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *insertAtEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("empty");
        return 0;
    }

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = 67;
    new->link = NULL;

    struct node *ptr = head;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = new;

    return new;
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

    struct node *hello = insertAtEnd(head);

    struct node *ptr = head;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    printf("\n");
    printf("%d %d %d %d %d", head->data, head->link->data, head->link->link->data, head->link->link->link->data, hello->data);
    printf("\n");
    printf("%d %d %d %d %d", head->data, head->link->data, head->link->link->data, head->link->link->link->data, head->link->link->link->link->data);

    return 0;
}
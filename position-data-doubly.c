
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int position(struct node *head, int pos)
{
    int count = 1;

    struct node *ptr = malloc(sizeof(struct node));

    ptr = head;
    while (ptr != NULL)
    {
        if (count == pos)
        {
            return ptr->data;
        }
        ptr = ptr->link;
        count++;
    }

    return -1;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 27;
    temp->prev = head;
    temp->next = NULL;

    head->next = temp;

    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    temp->data = 9;
    temp->prev = temp;
    temp->next = NULL;

    head->link->link = temp;

    struct node temp2 = (struct node *)malloc(sizeof(struct node));
    temp->data = 12;
    temp->link = NULL;

    head->link->link->link = temp;

    struct node temp3 = (struct node *)malloc(sizeof(struct node));
    temp->data = 14;
    temp->link = NULL;

    head->link->link->link->link = temp;

    int pos = 3;
    int value = position(head, pos);

    if (value != -1)
    {
        printf("%d", value);
    }
    else
    {
        printf("invalid position");
    }

    return 0;
}

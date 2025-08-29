#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void count(struct node *head)
{
    int count = 1 ;
 
    if(head == NULL) {
        printf("empty");
    }

    struct node *temp = malloc(sizeof(struct node));
    temp->data = 40;
    temp->link = NULL;

    struct node *ptr = NULL;

    // ptr = head;
    // while (ptr->link != NULL) // point -> porerta check -> execute
    // {
    //     ptr = ptr->link;
    // }

    // ptr->link = temp;

    ptr = head;
    while (count < 3 - 1)
    {
        count++;
        ptr = ptr->link;
    }

    temp->link = ptr->link;
    ptr->link = temp;

    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{

    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = 20;
    temp->link = NULL;

    head->link = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 30;
    temp->link = NULL;

    head->link->link = temp;

    count(head);

    return 0;
}

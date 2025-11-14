#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node * insertAtCertain(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
        return NULL;
    }

    struct node *temp = malloc(sizeof(struct node));
    temp->data = 67;
    temp->link = NULL;

    // case 1 : pos = 1
    if(pos == 1){
        temp->link = head;
        head = temp;
        return head;
    }

    //case 2 : another position (last position er impact nai) 
    struct node *ptr = head;

    while(pos > 2){  // pos = 2 dileo kno prblm nai, karon position 2 hole ptr k ekghor age 1st node e aste hbe, ar ptr already 1st node e ache, tai ei loop er drkar i nai.
        ptr = ptr->link;
        pos--;
    }

    temp->link = ptr->link;
    ptr->link = temp;
 
    return head;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->link;
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

    printList(head); printf("\nAfter insertion: ");
    head = insertAtCertain(head, 1);
    printList(head);

    return 0;
}

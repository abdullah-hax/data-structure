#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void del_last(struct node *head){
    if(head == NULL){
        printf("List is already empty");
        return;
    }


    // Case 1 : Only 1 node
    if(head->link == NULL){
        free(head);
        return;
    }

    // Case 2 : More than 1 node
    struct node *ptr ;

    ptr = head; 
    while(ptr->link->link != NULL){
        ptr = ptr->link;
    }

    free(ptr->link);

    ptr->link = NULL;
 
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

}

int main() {
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


    del_last(head);
    return 0;
}
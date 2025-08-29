#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void del_first(struct node *head){
    if(head == NULL){
        printf("List is already empty");
    }

    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = malloc(sizeof(struct node));

    ptr = head; 
    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    ptr = NULL;
 
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


    del_first(head);
    return 0;
}
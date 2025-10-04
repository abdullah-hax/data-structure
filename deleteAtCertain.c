#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void del_certain(struct node *head, int pos){
    if(head == NULL){
        printf("List is already empty");
    }

    struct node *ptr = malloc(sizeof(struct node));

    ptr = head;

    pos--;
    while(pos != 1){
        ptr = ptr->link;
        pos--;
    }

    struct node *temp = malloc(sizeof(struct node));

    temp = ptr->link;

    ptr->link = temp->link;

    free(temp);

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
    
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 50;
    temp->link = NULL;
    head->link->link->link->link = temp;


    int pos = 3;
  
    del_certain(head, pos);
    return 0;
}
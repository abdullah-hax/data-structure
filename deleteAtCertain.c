#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void del_certain(struct node *head, int pos){
    if(head == NULL){
        printf("List is already empty");
        return;
    }

    struct node *previous = head;
    struct node *current = head;

   
    // Case 1: delete first node
    if(pos == 1){
        head = head->link;
        free(current);
    } 
    
    // Case 2: delete node at other position
    else {
        
        while(pos > 1){
            previous = current;
            current = current->link;
            pos--;

        }

        previous->link = current->link;
        free(current);
    }


    struct node *ptr = NULL;

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

  
    del_certain(head, 5);
    return 0;
}
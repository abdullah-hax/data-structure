#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node *link;
};


void delLast(struct node *head){
    if(head == NULL){
        printf("empty");
        return;
    }

    // Case 1 : Only 1 node    // ptr->link->link thakar karone 1 node er case 'must' consider krte hbe.
    if(head->link == NULL){
        free(head);
        return;
    }

    // Case 2 : More than 1 node
    struct node *temp = head;
    while(temp->link->link != NULL){   // 1 node er khettre temp->link er link nai , tai compiler eta check krte gie segmantion fault dibe.
        temp = temp->link;
    }

    free(temp->link);

    temp->link = NULL;


    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}


int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = 2;
    temp->link = NULL;

    head->link = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 3;
    temp->link = NULL;

    head->link->link = temp;
    
    temp = malloc(sizeof(struct node));
    temp->data = 4;
    temp->link = NULL;

    head->link->link->link = temp;

    delLast(head);

}

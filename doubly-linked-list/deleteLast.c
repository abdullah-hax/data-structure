#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};


void del_last(struct node *head){
    if(head == NULL){
        printf("Empty");
        return;
    }

    struct node *temp = NULL;
    temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;

    head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;

    struct node *temp = NULL;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 20;
    temp->next = NULL;

    head->next = temp;
    temp->prev = head;

    temp = malloc(sizeof(struct node));  //  ekbar declare kore felsi , tai ar krtesina.
    temp->prev = NULL;
    temp->data = 30;
    temp->next = NULL;

    head->next->next = temp;
    temp->prev = head->next;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 40;
    temp->next = NULL;

    head->next->next->next = temp;
    temp->prev = head->next->next;

    del_last(head);


}



// nodeCreate(head)

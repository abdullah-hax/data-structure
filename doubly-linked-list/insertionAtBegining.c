#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};


void insertion(struct node *head, int data){
    if(head == NULL){
        printf("Empty");
    }

    struct node *temp = NULL;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = head;

    temp->next = head;
    head->prev = temp;
    
    head = temp;
   

    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
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

    insertion(head, 50);


}

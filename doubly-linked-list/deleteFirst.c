#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void del_first(struct node *head){

    if(head == NULL){
        printf("Empty");
        return;
    }

    // case 1 : only 1 node
    if(head->next == NULL){
        free(head);
        return;
    }
    
    // case 2 : more than 1 node
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;

    free(ptr);

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
    head->prev = NULL;
    temp->data = 20;
    temp->next = NULL;
    head->next = temp;
    temp->prev = head;
    
    temp = malloc(sizeof(struct node));
    head->prev = NULL;
    temp->data = 30;
    temp->next = NULL;
    head->next->next = temp;
    temp->prev = head->next;
    
    temp = malloc(sizeof(struct node));
    head->prev = NULL;
    temp->data = 40;
    temp->next = NULL;
    head->next->next->next = temp;
    temp->prev = head->next->next;

    del_first(head);

}
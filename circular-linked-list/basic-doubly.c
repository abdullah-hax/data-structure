#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void circular(struct node *head){
    if(head == NULL){
        printf ("linked list is empty");
    }
    
    struct node *temp = malloc(sizeof(struct node));

    temp  = head;

    temp->data = 30;
    temp->prev = temp;
    temp->next = temp;

    printf ("%d ", temp->data);
}

int main(){
    struct node *head = malloc(sizeof(struct node));

    circular(head);

    // while(head != NULL){
    //     printf("%d ", head->data);
    //     head = head->next;
    // }
}
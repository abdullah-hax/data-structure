#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};


void del_certain(struct node *head, int pos){
    if(head == NULL){
        printf("Empty");
        return;
    }

    // struct node *previous = head;
    struct node *current = head;

    // case 1 : delet at 1st pos
    if (pos == 1){

        head = head->next;
        if(head != NULL){  // case 1a : if condition is for only 1 node
            head->prev = NULL;
        }
        free(current);
    }

    // case 2 : delete at another pos
    else{

        while(pos > 1){
            current = current->next;
            pos--;
        } 

        current->prev->next = current->next;

        if(current->next != NULL){    // case 2a : if condition is for last pos
            current->next->prev = current->prev;
        }

        free(current);
        
    }
    
    
    struct node *temp = NULL;
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

    temp = malloc(sizeof(struct node));  //  ekbar declare kore felsi , tai ar krtesina.
    temp->prev = NULL;
    temp->data = 20;
    temp->next = NULL;

    head->next = temp;
    temp->prev = head;

    temp = malloc(sizeof(struct node)); 
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

    del_certain(head, 3);

}



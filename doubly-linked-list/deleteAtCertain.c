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

    int count = 1;
    struct node *ptr = NULL;
    ptr = head;
    while(count <= pos - 2){
        count++;
        ptr = ptr->next;
    }

    struct node *remove = NULL;
    remove = head;
    count = 1;
    while(count <= pos - 1 ){
        count++;
        remove = remove->next;
    }

    ptr->next = remove->next;
    remove->next->prev = ptr;

    free(remove);
    
   
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

    del_certain(head, 3);


}



// nodeCreate(head)

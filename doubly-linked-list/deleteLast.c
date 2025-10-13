#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *delFirst(struct node *head){
    if(head == NULL){
        printf("empty");
        return NULL;
    }

    // case 1 : only 1 node
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    // case 2 : more than 1 node  
    struct node *temp = head;
    while(temp->next->next != NULL){  // 1 node er khettre temp->next er next nai tai seg. fault khabe. 
        temp = temp->next; 
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 1;
    head->next = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 2;
    temp->next = NULL;

    head->next = temp;
    temp->prev = head;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 3;
    temp->next = NULL;

    head->next->next = temp;
    temp->prev = head->next;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 4;
    temp->next = NULL;

    head->next->next->next = temp;
    temp->prev = head->next->next;

    printList(head);
    printf("\nAfter deleting : ");

    head = delFirst(head);

    printList(head);

}
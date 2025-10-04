#include <stdio.h>
#include <stdlib.h>



struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void countingNodes(struct node *head){
    if (head == NULL){
        printf("Linked list is empty");
    }

    int count = 0;
    struct node *ptr = head;

    while(ptr != NULL){
        count++;
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n%d\n", count);
}


int main() {
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;

    struct node *temp = malloc(sizeof(struct node));
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

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 50;
    temp->next = NULL;

    head->next->next->next->next = temp;
    temp->prev = head->next->next->next;


    countingNodes(head);

    return 0;
}
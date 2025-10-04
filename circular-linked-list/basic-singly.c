#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void circular (struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
    }

    struct node *temp = NULL;
    temp = head;
    temp->data = 20;
    temp->link = temp;

    printf("%d\n", temp->data);

}

int main() {

    struct node *head = malloc(sizeof(struct node));

    circular(head);
    
    return 0;
}
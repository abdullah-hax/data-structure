#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insertAtCertain(struct node *head, int pos){

    int count = 1;
    if(head == NULL){
        printf("Empty linked list");
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = 50;
    new->link = NULL;

    struct node *ptr = NULL;
    ptr = head;

    // while(count < pos-1){
    //     ptr = ptr->link;
    //     count++;
    // }

    pos--;
    while(pos != 1){   
        ptr = ptr->link;
        pos--;
    }

    new->link = ptr->link;  // ptr->link = 3rd node
    ptr->link = new;   // new = new 3rd node

    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }



}

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 20;
    temp->link = NULL;

    head->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 30;
    temp->link = NULL;

    head->link->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 40;
    temp->link = NULL;

    head->link->link->link = temp;

    int pos = 2;

    insertAtCertain(head, pos);
    return 0;
}



/* 

    একটা লুপে যা হয় => point -> check -> execute


    head কে point করে , 3 কে check করে
    পরেরটা point করে , 2 কে check করে
    পরেরটা point করে , 1 কে check করে  

    অর্থাৎ , pos != 1 means => 3 বার point করবে, তাই pos-- দেয়া হয় , যাতে 2 বার point করে


*/
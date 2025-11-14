#include <stdio.h>
#include <string.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    
    struct node *head = (struct node*)malloc(sizeof(struct node));

    head -> data = 45;
    head -> link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current -> data = 98;
    current -> link = NULL;

    head -> link = current;

    struct node *current2 = malloc(sizeof(struct node));
    current2 -> data = 3;
    current2 -> link = NULL;
    current -> link = current2;

    struct node *current3 = (struct node*)malloc(sizeof(struct node));
    current3 -> data = 12;
    current3 -> link = NULL;

    current2 -> link = current3;
    return 0;
}
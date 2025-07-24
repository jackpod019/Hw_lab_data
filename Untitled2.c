#include <stdio.h>
#include <stdlib.h>

struct node

{
    int data;
    struct node *next,*prev;
};

struct node *head = NULL;

void createNode(int n){
struct node *new_node,*ptr=NULL;
for(int i=n;i>=1;i--){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=i;
    new_node->next=ptr;
    ptr = new_node;
}
head=ptr;
}

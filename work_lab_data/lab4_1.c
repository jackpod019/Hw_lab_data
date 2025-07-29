#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void DisplayLL()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void DisplayAddressLL()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("Node val=%d,add=%X\t", ptr->data, ptr);

        printf("Next node add=%X\n", ptr->next);

        ptr = ptr->next;
    }
}

int main()
{
    struct node *new_node,*ptr=NULL;
    
    srand(time(NULL)); 
    int n;
    scanf("%d", &n);
for(int i=0;i<n;i++){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=rand()%100;
    new_node->next=ptr;
    ptr = new_node;
}
head=ptr;
    printf("\n");
    DisplayLL();
    DisplayAddressLL();
}

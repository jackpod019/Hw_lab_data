#include <stdio.h>
#include <stdlib.h>
#define Size 7

//Declare structure of Linked List
struct node
{
    int data;
    struct node *next;
};

//array of pointer
struct node *hash_table[Size];

void insertChain(int value)
{
    struct node *new_node;
    new_node= (struct node*)malloc(sizeof(struct node));

    new_node->data=value;
    new_node->next=NULL;

    int index=value%Size;
    new_node->next=hash_table[index];
    hash_table[index]=new_node;

}

void printChain()
{
    for(int i=0 ; i<Size ; i++)
    {
        struct node *ptr=hash_table[i];
        printf("chain[%d]",i);
        while(ptr!=NULL){
            printf("-->%d",ptr->data);
            ptr=ptr->next;
        }
        printf("-->NULL\n");
    }

}
int search_item(int x)
{
    int key = x%Size;
    int temp=1;
    struct node *ptr = hash_table[key];
    while(ptr!=NULL)
    {
        if(ptr->data==x)
            return temp;

        ptr=ptr->next;
        temp++;
    }
    return -1;
}

int main()
{
int i;
for(i=0;i< Size;i++)   //initialize a chained hash table
     hash_table[i]=NULL;
    insertChain(15);
    insertChain(22);
    insertChain(95);
insertChain(56);
insertChain(12);
insertChain(27);
insertChain(63);
insertChain(49);
insertChain(24);

printChain();

 //Code for creating Hash table from Q1
 printf("%d\n",search_item(15));
    printf("%d\n",search_item(50));

}

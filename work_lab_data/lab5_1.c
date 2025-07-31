#include <stdio.h>
#include <stdlib.h>
#define Size 7

// Declare structure of Linked List
struct node {
    int data;
    struct node *next;
};

// Array of pointers
struct node *hash_table[Size];

// Insert at head (to match sample output)
void insertChain(int value) {
    int index = value % Size;

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    // Insert at head
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

// Print the hash table
void printChain() {
    for (int i = 0; i < Size; i++) {
        printf("chain[%d]-->", i);
        struct node *temp = hash_table[i];
        while (temp != NULL) {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int search_item(int x)
{
    int index = x % Size;
    struct node *temp = hash_table[index];
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == x)
            return pos;  // เจอที่ตำแหน่ง pos
        temp = temp->next;
        pos++;
    }

    return -1;  // ไม่เจอ
}

int main() {
    int i;

    // Initialize hash table
    for (i = 0; i < Size; i++)
        hash_table[i] = NULL;

    // Insert initial values
    insertChain(15);
    insertChain(22);
    insertChain(95);
    insertChain(56);
    insertChain(12);
    insertChain(27);
    insertChain(63);

    // Display before adding more
    printChain();

    // Add values for 1.1
    insertChain(49);
    insertChain(24);

    // Display updated table
    printf("\nAfter inserting 49 and 24:\n");
    printChain();

    printf("%d\n", search_item(15));  // เจอ => ควรแสดง 1 (เพราะ insert ที่ head)
    printf("%d\n", search_item(50));  // ไม่เจอ => -1
    return 0;
}

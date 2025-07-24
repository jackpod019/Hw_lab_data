#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // เพิ่มตรงนี้

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

node* newNode(int v) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}

void DisplayLL() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

bool isCircular(node *h) {
    if (h == NULL)
        return false;

    node *ptr = h->next;

    while (ptr != NULL && ptr != h) {
        ptr = ptr->next;
    }

    return (ptr == h);
}

int main() {
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    DisplayLL();

    if (isCircular(head))
        printf("ลิงค์ลิสต์เป็นแบบวงกลม (Circular)\n");
    else
        printf("ลิงค์ลิสต์ไม่เป็นแบบวงกลม (Not Circular)\n");

    // ทำให้เป็นวงกลม:
    head->next->next->next->next = head;

    if (isCircular(head))
        printf("ลิงค์ลิสต์เป็นแบบวงกลม (Circular)\n");
    else
        printf("ลิงค์ลิสต์ไม่เป็นแบบวงกลม (Not Circular)\n");

    return 0;
}

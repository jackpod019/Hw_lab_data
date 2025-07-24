#include <stdio.h>
#include <stdlib.h>

// โครงสร้างโหนดแบบ Singly Linked List
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

// โครงสร้างโหนดแบบ Doubly Linked List
struct Dnode {
    int data;
    struct Dnode *prev;
    struct Dnode *next;
};

// แสดงค่า Singly Linked List
void DisplayLL() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// สร้าง Singly Linked List จาก 1 ถึง n
void createSinglyList(int n) {
    struct node *new_node, *ptr = NULL;
    for (int i = n; i >= 1; i--) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = ptr;
        ptr = new_node;
    }
    head = ptr;
}

// แปลงเป็น Doubly Linked List และแสดงจากหลังไปหน้า
void doublyMaker() {
    struct node *ptr = head;
    struct Dnode *dhead = NULL, *dptr = NULL, *new_dnode = NULL;

    while (ptr != NULL) {
        new_dnode = (struct Dnode *)malloc(sizeof(struct Dnode));
        new_dnode->data = ptr->data;
        new_dnode->prev = dptr;
        new_dnode->next = NULL;

        if (dptr != NULL) {
            dptr->next = new_dnode;
        } else {
            dhead = new_dnode; // เก็บหัวของ doubly linked list
        }

        dptr = new_dnode;
        ptr = ptr->next;
    }

    // แสดงค่าจากหลังไปหน้า
    printf("\nDisplay from tail to head:\n");
    while (dptr != NULL) {
        printf("%d ", dptr->data);
        dptr = dptr->prev;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    createSinglyList(n);
    DisplayLL();
    doublyMaker();

    return 0;
}

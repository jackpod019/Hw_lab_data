#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // สำหรับใช้ bool, true, false

// โครงสร้างโหนดของ Singly Linked List
typedef struct node {
    int data;
    struct node *next;
} node;

// ตัวชี้ไปยังโหนดแรก
node *head = NULL;

// ฟังก์ชันสร้างโหนดใหม่
node* newNode(int v) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}

// ฟังก์ชันแสดงข้อมูลในลิงค์ลิสต์
void DisplayLL() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// ฟังก์ชันตรวจสอบว่าเป็น Circular Linked List หรือไม่
bool isCircular(node *h) {
    if (h == NULL)
        return false;

    node *ptr = h->next;

    while (ptr != NULL && ptr != h) {
        ptr = ptr->next;
    }

    return (ptr == h);
}

// ฟังก์ชันหลัก
int main() {
    // สร้าง Singly Linked List แบบปกติ (1 -> 2 -> 3 -> 4 -> NULL)
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // แสดงลิงค์ลิสต์ก่อนแปลง
    DisplayLL();

    // ตรวจสอบและพิมพ์ผลก่อนแปลง
    if (isCircular(head))
        printf("ลิงค์ลิสต์เป็นแบบวงกลม (Circular)\n");
    else
        printf("ลิงค์ลิสต์ไม่เป็นแบบวงกลม (Not Circular)\n");

    // 🔁 ถ้าไม่เป็นวงกลม ให้แปลงให้เป็นวงกลม
    if (!isCircular(head)) {
        node *ptr = head;

        // เดินไปยังโหนดสุดท้าย
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        // ทำให้ next ของโหนดสุดท้ายชี้กลับไปยัง head
        ptr->next = head;
    }

    // ตรวจสอบและพิมพ์ผลหลังแปลง
    if (isCircular(head))
        printf("ลิงค์ลิสต์ถูกแปลงเป็นแบบวงกลมแล้ว (Circular)\n");
    else
        printf("ลิงค์ลิสต์ยังไม่เป็นแบบวงกลม (Not Circular)\n");

    return 0;
}

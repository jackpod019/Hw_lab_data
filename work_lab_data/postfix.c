#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxsize 100

char S[maxsize] = {0}; // Stack สำหรับเก็บตัวดำเนินการ
char strout[maxsize] = {0}; // String สำหรับเก็บผลลัพธ์ Postfix
int Top = -1; // Top ของ stack S
int Topstr = -1; // Top ของ string strout

// ฟังก์ชันสำหรับกำหนดลำดับความสำคัญของตัวดำเนินการ
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // สำหรับตัวอักษรอื่นๆ
}

// ฟังก์ชันเพิ่มข้อมูลลงใน stack สำหรับตัวดำเนินการ
void push(int data) {
    if (Top == maxsize - 1) {
        printf("\nStack is Full\n");
    } else {
        Top++;
        S[Top] = data;
    }
}

// ฟังก์ชันเพิ่มข้อมูลลงใน string สำหรับ Postfix
void pushstr(int data) {
    if (Topstr == maxsize - 1) {
        printf("\nOutput String is Full\n");
    } else {
        Topstr++;
        strout[Topstr] = data;
    }
}

// ฟังก์ชัน pop ข้อมูลออกจาก stack ตัวดำเนินการ และส่งไป pushstr
int pop() {
    int data = -1;
    if (Top == -1) {
        printf("\nStack is Empty\n");
    } else {
        data = S[Top];
        Top--;
        pushstr(data);
    }
    return data;
}

int main() {
    char str[100];
    printf("Enter infix expression: ");
    scanf("%s", str);

    int i = 0;
    while (str[i] != '\0') {
        char currentChar = str[i];

        // ถ้าเป็นตัวเลข (หรือตัวอักษร) ให้เพิ่มลงใน Postfix ทันที
        if (isalnum(currentChar)) {
            pushstr(currentChar);
        }
        // ถ้าเป็นวงเล็บเปิด ให้ push ลง stack
        else if (currentChar == '(') {
            push(currentChar);
        }
        // ถ้าเป็นวงเล็บปิด
        else if (currentChar == ')') {
            while (Top != -1 && S[Top] != '(') {
                pop();
            }
            if (Top != -1) {
                Top--; // Pop '(' ออกจาก stack
            }
        }
        // ถ้าเป็นตัวดำเนินการ
        else {
            while (Top != -1 && getPrecedence(S[Top]) >= getPrecedence(currentChar)) {
                pop();
            }
            push(currentChar);
        }
        i++;
    }

    // ดึงตัวดำเนินการที่เหลือทั้งหมดออกจาก stack
    while (Top != -1) {
        pop();
    }
    
    // เพิ่ม null terminator เพื่อให้เป็น string ที่สมบูรณ์
    strout[Topstr + 1] = '\0'; 

    printf("Postfix expression: %s\n", strout);

    return 0;
}

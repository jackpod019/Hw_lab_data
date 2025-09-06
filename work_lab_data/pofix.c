#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack สำหรับเก็บตัวดำเนินการ
char operatorStack[MAX_SIZE];
int opTop = -1;

// String สำหรับเก็บนิพจน์ Postfix
char postfix[MAX_SIZE];
int postfixTop = -1;

// ฟังก์ชันสำหรับกำหนดลำดับความสำคัญของตัวดำเนินการ
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // สำหรับตัวเลขและวงเล็บ
}

// ฟังก์ชันตรวจสอบว่า stack ว่างหรือไม่
int isOpStackEmpty() {
    return opTop == -1;
}

// ฟังก์ชันตรวจสอบว่า stack เต็มหรือไม่
int isOpStackFull() {
    return opTop == MAX_SIZE - 1;
}

// ฟังก์ชันเพิ่มข้อมูล (push) ลงใน stack ตัวดำเนินการ
void pushOp(char op) {
    if (isOpStackFull()) {
        printf("Operator stack is full!\n");
    } else {
        operatorStack[++opTop] = op;
    }
}

// ฟังก์ชันดึงข้อมูล (pop) ออกจาก stack ตัวดำเนินการ
char popOp() {
    if (isOpStackEmpty()) {
        return '\0'; // คืนค่า null character สำหรับ stack ว่าง
    } else {
        return operatorStack[opTop--];
    }
}

// ฟังก์ชันดูข้อมูลบนสุดของ stack โดยไม่ต้องดึงออก
char peekOp() {
    if (isOpStackEmpty()) {
        return '\0';
    } else {
        return operatorStack[opTop];
    }
}

// ฟังก์ชันเพิ่มตัวอักษรลงในสตริง postfix
void appendToPostfix(char c) {
    if (postfixTop == MAX_SIZE - 1) {
        printf("Postfix string is full!\n");
    } else {
        postfix[++postfixTop] = c;
    }
}

// ฟังก์ชันแปลง Infix เป็น Postfix
void infixToPostfix(char* infix) {
    for (int i = 0; infix[i] != '\0'; i++) {
        char currentChar = infix[i];

        // ถ้าเป็นตัวเลข (หรือตัวอักษร) ให้เพิ่มลงใน Postfix ทันที
        if (isalnum(currentChar)) {
            appendToPostfix(currentChar);
        }
        // ถ้าเป็นวงเล็บเปิด ให้ push ลง stack
        else if (currentChar == '(') {
            pushOp(currentChar);
        }
        // ถ้าเป็นวงเล็บปิด
        else if (currentChar == ')') {
            while (!isOpStackEmpty() && peekOp() != '(') {
                appendToPostfix(popOp());
            }
            if (!isOpStackEmpty() && peekOp() == '(') {
                popOp(); // ดึง '(' ออกจาก stack
            }
        }
        // ถ้าเป็นตัวดำเนินการ
        else {
            while (!isOpStackEmpty() && getPrecedence(peekOp()) >= getPrecedence(currentChar)) {
                appendToPostfix(popOp());
            }
            pushOp(currentChar);
        }
    }

    // ดึงตัวดำเนินการที่เหลือทั้งหมดออกจาก stack
    while (!isOpStackEmpty()) {
        appendToPostfix(popOp());
    }

    postfix[++postfixTop] = '\0'; // เพิ่ม null terminator
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

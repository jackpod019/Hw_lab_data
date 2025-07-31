#include <stdio.h>
#include <stdlib.h>
// Declare structure of Linked List
struct polynode
{
    int coef;
    int exp;
    struct polynode *next;
};
struct polynode *head1 = NULL;
struct polynode *head2 = NULL;
struct polynode *head3 = NULL;
// Display all element in linked list
void displayPoly(struct polynode *head) {
    struct polynode *temp = head;
    int first = 1;

    while (temp != NULL) {
        if (temp->coef != 0) {
            if (!first)
                printf(" + ");

            if (temp->exp == 0)
                printf("%d", temp->coef);
            else if (temp->exp == 1)
                printf("%dx", temp->coef);
            else
                printf("%dx^%d", temp->coef, temp->exp);

            first = 0;
        }
        temp = temp->next;
    }

    if (first)
        printf("0");

    printf("\n");
}
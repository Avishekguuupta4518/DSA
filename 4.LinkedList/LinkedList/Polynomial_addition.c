#include <stdio.h>
#include <stdlib.h>

typedef struct Poly {
    int coeff;
    int pow;
    struct Poly *next;
} Poly;

Poly* createNode(int coeff, int pow) {
    Poly *node = (Poly*)malloc(sizeof(Poly));
    node->coeff = coeff;
    node->pow = pow;
    node->next = NULL;
    return node;
}

void insertTerm(Poly **poly, int coeff, int pow) {
    Poly *newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Poly *temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Poly *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

Poly* addPolynomials(Poly *p1, Poly *p2) {
    Poly *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertTerm(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertTerm(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Poly *p1 = NULL, *p2 = NULL, *sum = NULL;

    insertTerm(&p1, 3, 3);
    insertTerm(&p1, 2, 2);
    insertTerm(&p1, 1, 0);

    insertTerm(&p2, 4, 3);
    insertTerm(&p2, 1, 1);
    insertTerm(&p2, 2, 0);

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    sum = addPolynomials(p1, p2);

    printf("Sum: ");
    display(sum);

    return 0;
}

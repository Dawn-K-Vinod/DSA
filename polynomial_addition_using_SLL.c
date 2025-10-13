
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

struct node* create_newNode(int c, int e) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;
    return newnode;
}

struct node* create_polynomial(int terms_count) {
    struct node *polynomial=NULL, *temp=NULL;
    int c,e;
    for (int i = 1; i<=terms_count; i++) {
        printf("Enter term-%d: ",i);
        scanf("%d %d",&c, &e);

        if (polynomial==NULL) {
            polynomial = temp = create_newNode(c,e);
        }
        else{
            temp->next = create_newNode(c,e);
            temp = temp->next;
        }
    }
    return polynomial;
}

struct node* add_polynomials(struct node* p1, struct node* p2) {
    struct node *result = NULL;
    struct node dummyHead;
    result = &dummyHead;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int c_sum = p1->coeff + p2->coeff;
            if (c_sum!=0) {
                result->next = create_newNode(c_sum, p1->exp);
                result = result->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result->next = create_newNode(p1->coeff, p1->exp);
            result = result->next;
            p1 = p1->next;
        }
        else {
            result->next = create_newNode(p2->coeff, p2->exp);
            result = result->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result->next = create_newNode(p1->coeff, p1->exp);
        p1 = p1->next;
        result = result->next;
    }
    while (p2 != NULL) {
        result->next = create_newNode(p2->coeff, p2->exp);
        p2 = p2->next;
        result = result->next;
    }
    return dummyHead.next;
}

void display_poly(struct node* LL) {
    struct node *temp; temp = LL;
    printf("%dx^%d", LL->coeff, LL->exp); LL=LL->next;
    while(LL != NULL){
        if (temp!=LL & LL->coeff > 0) printf("+ ");
        else if (LL->coeff < 0) printf("-");
        printf("%dx^%d ", (LL->coeff<0 ? -LL->coeff : LL->coeff) , LL->exp);
        LL = LL->next;
    }

}

int main() {
    struct node *polynomial1, *polynomial2, *res;

    printf("Enter the number of terms for both Polynomial-1 & Polynomial2: ");
    int p1_tCount, p2_tCount;
    scanf("%d %d",&p1_tCount, &p2_tCount);
    printf("Enter the terms for polynomial-1: \n");
    polynomial1 = create_polynomial(p1_tCount);
    printf("\nEnter the terms for polynomial-2: \n");
    polynomial2 = create_polynomial(p2_tCount);

    printf("Polynomial-1: ");
    display_poly(polynomial1);
    printf("\nPolynomial-2: ");
    display_poly(polynomial2);

    res = add_polynomials(polynomial1, polynomial2);
    printf("\nResultant Polynomial: ");
    display_poly(res);
    printf("\n");
    return 0;
}
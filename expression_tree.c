#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//(a+b)*c  ab+c*

char postFix[] = "ab+c*";

struct node {
    char data;
    struct node *left_operand;
    struct node *right_operand;
} *newnode;

struct node* stack[sizeof(postFix)-1];
int length=0, TOP=-1;
void PUSH(struct node* item) {
    stack[++TOP] = item;
}
struct node* POP() {
    if (TOP < 0) return NULL;
    return stack[TOP--];
}

int isOperator(char ch) {
    return strchr("+*/-^%%",ch) != NULL;
}
void create_newnode(char value) {
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left_operand = NULL;
    newnode->right_operand = NULL;
}
struct node* create_expr_tree() {
    int len = strlen(postFix);
    for (int i=0; i<len; i++) {
        
        if (isOperator(postFix[i])) {
            create_newnode(postFix[i]);
            newnode->right_operand = POP();
            newnode->left_operand = POP();
            PUSH(newnode);
        }
        else if (isalpha(postFix[i]) || isdigit(postFix[i])) {
            create_newnode(postFix[i]);
            PUSH(newnode);
        }
    }
    return POP();
}

void postOrder_expr_tree(struct node* root) {
    if (root == NULL) return;
    postOrder_expr_tree(root->left_operand);
    postOrder_expr_tree(root->right_operand);
    printf("%c", root->data);
}
void inOrder_expr_tree(struct node* root) {
    if (root == NULL) return;
    printf("(");
    inOrder_expr_tree(root->left_operand);
    printf("%c", root->data);
    inOrder_expr_tree(root->right_operand);
    printf(")");
}
void preOrder_expr_tree(struct node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preOrder_expr_tree(root->left_operand);
    preOrder_expr_tree(root->right_operand);
}

int main() {
    struct node* expression_tree = create_expr_tree();
    printf("\nPost Order: ");
    postOrder_expr_tree(expression_tree);
    printf("\nIn Order: ");
    inOrder_expr_tree(expression_tree);
    printf("\nPre Order: ");
    preOrder_expr_tree(expression_tree);
    printf("\n");
    return 0;
}
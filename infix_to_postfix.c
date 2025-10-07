/*
Infix to Postfix Conversion
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *stack;
char *expr;
int length=0, TOP=-1;

void PUSH(char ch) {
    if (TOP == length-1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++TOP] = ch;
}
void POP() {
    if (TOP == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    TOP--;
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-': return 1;
        case '/':
        case '*': return 2;
        case '^': return 3;
        default: return -1;
    }
}


int main() { 
    expr = calloc(50, sizeof(char));
    stack = calloc(50, sizeof(char));
    printf("Enter a valid Expression (eg: --(A-B)*(C+D/F))--: ");
    scanf("%[^\n]", expr);
    
    for(int i=0; expr[i]!='\0'; i++) length++;

    for (int i=0; i<length; i++) {
        if (isalpha(expr[i]) || isdigit(expr[i])) {
            printf("%c",expr[i]);
        }
        else if (strchr("+*-/^%(",expr[i]) != NULL) {
            if (stack[TOP] == '(') { 
                PUSH(expr[i]);
                continue;
            }
            while (TOP != -1 && stack[TOP]!='(' && precedence(expr[i]) <= precedence(stack[TOP])) {
                printf("%c", stack[TOP]);
                POP();
            }
            PUSH(expr[i]);
        }

        else if (expr[i] == ')') {
            while (stack[TOP] != '(' && TOP != -1) {
                printf("%c", stack[TOP]);
                POP();
            }
            POP();
        }
    }
    while (TOP != -1) {
        printf("%c", stack[TOP]);
        POP();
    }
}

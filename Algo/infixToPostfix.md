# Algorithm: Infix to Postfix Conversion

1. **Initialize**
    - Create a stack to store operators.
    - Read the infix expression.

2. **Scan the Expression**
    - For each character in the expression:
        - If the character is an operand (letter or digit):
            - Print the operand (send directly to output).
        - If the character is an operator:
            - While the stack is not empty, and the top of the stack is not '(', and precedence of current operator is less than or equal to the precedence of the operator on top of the stack:
                - Pop and print the operator from the stack.
            - Push the current operator onto the stack.
        - If the character is '(':
            - Push '(' onto the stack.
        - If the character is ')':
            - Pop and print operators from the stack until '(' is encountered.
            - Pop '(' from the stack (do not print).

3. **End of Expression**
    - Pop and print any remaining operators from the stack.

4. **Result**
    - The printed output is the postfix expression.

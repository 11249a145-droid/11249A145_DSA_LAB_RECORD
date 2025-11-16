#include <stdio.h>
#include <ctype.h>   // For isalnum()
#define SIZE 100

char stack[SIZE];
int top = -1;

// Function to push onto stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop from stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Main function
int main() {
    char infix[SIZE], postfix[SIZE];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';  // End the postfix expression

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

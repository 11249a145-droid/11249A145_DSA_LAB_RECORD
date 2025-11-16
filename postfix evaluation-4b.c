#include <stdio.h>
#include <ctype.h>   // for isdigit()

#define SIZE 100

int stack[SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *exp) {
    int i;
    char ch;
    int val1, val2, result;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        // If the character is a digit, push it to stack
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        }
        // If the character is an operator, pop two operands and apply the operator
        else {
            val2 = pop();
            val1 = pop();

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: 
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
            push(result);
        }
    }

    // Final result on top of the stack
    return pop();
}

int main() {
    char exp[SIZE];

    printf("Enter postfix expression (use single-digit numbers): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}

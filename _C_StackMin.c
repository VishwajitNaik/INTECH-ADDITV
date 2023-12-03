#include <stdio.h>
#include <stdlib.h>

#define N 100 // Size of the stack

// Structure to represent a stack
struct Stack {
    int arr[N];
    int top;
    int minStack[N];
    int minTop;
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
    stack->minTop = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int x) {
    if (stack->top + 1 == N) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack->top++;
        stack->arr[stack->top] = x;

        // Update the minimum stack
        if (stack->minTop == -1 || x <= stack->minStack[stack->minTop]) {
            stack->minTop++;
            stack->minStack[stack->minTop] = x;
        }
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        int y = stack->arr[stack->top];

        // Update the minimum stack
        if (y == stack->minStack[stack->minTop]) {
            stack->minTop--;
        }

        stack->top--;
        return y;
    }
}

// Function to get the minimum element from the stack
int getMinimum(struct Stack *stack) {
    if (stack->minTop == -1) {
        printf("Stack is empty\n");
        exit(1);
    } else {
        return stack->minStack[stack->minTop];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 4);

    // Get the minimum element
    printf("Minimum element in the stack: %d\n", getMinimum(&stack));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Get the minimum element after popping
    printf("Minimum element in the stack: %d\n", getMinimum(&stack));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }

    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);

    return poppedValue;
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeStack(struct Node* top) {
    struct Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    struct Node* stack = NULL;
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                push(&stack, data);
                break;

            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("%d popped from stack\n", data);
                }
                break;

            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("Top element is: %d\n", data);
                }
                break;

            case 4:
                display(stack);
                break;

            case 5:
                printf("Exiting...\n");
                freeStack(stack);
                exit(0);

            default:
                printf("Invalid choice. Please tr:y again.\n");
        }
    }

    return 0;
}




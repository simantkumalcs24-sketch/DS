#include <stdio.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;

void insert() {
    int x;
    printf("Enter element to insert: ");
    scanf("%d", &x);

    if ((rear + 1) % N == front) {
        printf("Queue overflow\n");
        return;
    }

    else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % N;
    }

    queue[rear] = x;
    printf("%d inserted\n", x);
}

void delete() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < N; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}




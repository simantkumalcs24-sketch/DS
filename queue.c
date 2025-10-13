#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enque(int x)
{
    if (rear == N - 1)
    {
        printf("Queue overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enque(val);
            break;

        case 2:
            deque();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}

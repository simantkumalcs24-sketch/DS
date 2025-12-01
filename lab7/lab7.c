#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void createList(int n) {
    int value;
    struct Node *newNode;

    for(int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void insertAtFront(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL)
        head = tail = newNode;
    else {
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL)
        head = tail = newNode;
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int data, int pos){
    int i;
    struct Node *newNode, *temp = head;

    if (pos == 1) {
        insertAtFront(data);
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    for (i=1; i<pos-1 && temp!= NULL; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        insertAtEnd(data);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

void deleteAtEnd() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteByValue(int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (temp == head)
        deleteAtFront();
    else if (temp == tail)
        deleteAtEnd();
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void display() {
    struct Node *temp = head;
    printf("List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, n, data, pos;

    while(1)
    {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete First Element\n");
        printf("6. Delete Specific Element\n");
        printf("7. Delete Last Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtFront(data);
            break;

        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insertAtPosition(data, pos);
            break;

        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 5:
            deleteAtFront();
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(data);
            break;

        case 7:
            deleteAtEnd();
            break;

        case 8:
            display();
            break;

        case 9:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
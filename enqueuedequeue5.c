#include <stdio.h>
#define MAX 5
 
int queue[MAX];
int front = 0, rear = -1;
 
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow, cannot insert %d\n", value);
        return;
    }
    queue[++rear] = value;
    printf("Enqueued %d\n", value);
}
 
void dequeue() {
    if (front > rear) {
        printf("Queue underflow, queue is empty\n");
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
}
 
void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
 
int main() {
    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}

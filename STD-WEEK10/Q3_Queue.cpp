#include <iostream>
using namespace std;

const int MAX = 5;

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(const Queue &q) {
    return (q.front == -1 || q.front > q.rear);
}

bool isFull(const Queue &q) {
    return (q.rear == MAX - 1);
}

void enqueue(Queue &q, int val) {
    if (isFull(q)) {
        cout << "Queue Overflow! Cannot insert " << val << ", queue is full.\n";
    } else {
        if (q.front == -1) {
            q.front = 0;
        }
        q.rear++;
        q.arr[q.rear] = val;
        cout << val << " inserted successfully.\n";
    }
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow! No elements to remove.\n";
    } else {
        cout << q.arr[q.front] << " removed successfully.\n";
        q.front++;
        if (q.front > q.rear) {
            q.front = -1;
            q.rear = -1;
        }
    }
}

void frontElement(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element: " << q.arr[q.front] << "\n";
    }
}

void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue: (empty)\n";
    } else {
        cout << "Queue: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.arr[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    Queue q;
    initQueue(q);

    int choice = 0, val;

    while (choice != 5) {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue  3. Front\n";
        cout << "4. Display  5. Exit\n";
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            enqueue(q, val);
        } else if (choice == 2) {
            dequeue(q);
        } else if (choice == 3) {
            frontElement(q);
        } else if (choice == 4) {
            display(q);
        } else if (choice == 5) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Please choose between 1 and 5.\n";
        }
    }

    return 0;
}

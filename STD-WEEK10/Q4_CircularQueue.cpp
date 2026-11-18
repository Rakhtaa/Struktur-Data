#include <iostream>
using namespace std;

const int MAX = 5;

struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
    int count;
};

void initQueue(CircularQueue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isEmpty(const CircularQueue &q) {
    return (q.count == 0);
}

bool isFull(const CircularQueue &q) {
    return (q.count == MAX);
}

void enqueue(CircularQueue &q, int val) {
    if (isFull(q)) {
        cout << "Queue Overflow! Cannot insert " << val << "\n";
    } else {
        q.rear = (q.rear + 1) % MAX;
        q.arr[q.rear] = val;
        q.count++;
        cout << val << " inserted successfully.\n";
    }
}

void dequeue(CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow! No elements to remove.\n";
    } else {
        cout << q.arr[q.front] << " removed successfully.\n";
        q.front = (q.front + 1) % MAX;
        q.count--;
    }
}

void frontElement(const CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element: " << q.arr[q.front] << "\n";
    }
}

void display(CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue: (empty)\n";
    } else {
        cout << "Queue: ";
        int i = 0;
        int current = q.front;
        while (i < q.count) {
            cout << q.arr[current] << " ";
            current = (current + 1) % MAX;
            i++;
        }
        cout << "\n";
    }
}

int main() {
    CircularQueue q;
    initQueue(q);

    cout << "=== RUNNING 10-STEP TEST SEQUENCE ===\n";

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    dequeue(q);
    dequeue(q);

    enqueue(q, 60);
    enqueue(q, 70);

    cout << "\n--- FINAL RESULT --- \n";
    display(q);

    int choice = 0, val;
    while (choice != 5) {
        cout << "\n===== CIRCULAR QUEUE MENU =====\n";
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

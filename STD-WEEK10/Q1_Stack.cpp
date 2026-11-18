#include <iostream>
using namespace std;

const int MAX = 5;

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int val) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot insert " << val << ", stack is full.\n";
    } else {
        s.top++;
        s.arr[s.top] = val;
        cout << val << " inserted successfully.\n";
    }
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! No elements to pop.\n";
    } else {
        cout << s.arr[s.top] << " popped from the stack.\n";
        s.top--;
    }
}

void peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element: " << s.arr[s.top] << "\n";
    }
}

void display(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = s.top; i >= 0; i--) {
            cout << s.arr[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    Stack s;
    initStack(s);

    int choice = 0, val;

    while (choice != 5) {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push  2. Pop  3. Peek\n";
        cout << "4. Display  5. Exit\n";
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            push(s, val);
        } else if (choice == 2) {
            pop(s);
        } else if (choice == 3) {
            peek(s);
        } else if (choice == 4) {
            display(s);
        } else if (choice == 5) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Please choose between 1 and 5.\n";
        }
    }

    return 0;
}


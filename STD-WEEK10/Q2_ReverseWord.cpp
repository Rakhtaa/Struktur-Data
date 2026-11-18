#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Stack {
    char arr[MAX];
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

void push(Stack &s, char val) {
    if (!isFull(s)) {
        s.top++;
        s.arr[s.top] = val;
    }
}

char pop(Stack &s) {
    if (!isEmpty(s)) {
        char val = s.arr[s.top];
        s.top--;
        return val;
    }
    return '\0';
}

int main() {
    Stack s;
    initStack(s);

    string word;
    cout << "Enter a word: ";
    cin >> word;

    int i = 0;
    while (i < word.length()) {
        push(s, word[i]);
        i++;
    }

    cout << "Original word: " << word << "\n";
    cout << "Reversed word: ";

    while (!isEmpty(s)) {
        cout << pop(s);
    }
    cout << "\n";

    return 0;
}

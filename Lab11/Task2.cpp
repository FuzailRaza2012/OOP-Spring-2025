#include <iostream>
#include <exception>
using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T, size_t Capacity = 5>
class Stack {
private:
    T data[Capacity];
    size_t topIndex;

public:
    Stack() : topIndex(0) {}

    void push(const T& item) {
        if (topIndex >= Capacity) {
            throw StackOverflowException();
        }
        data[topIndex++] = item;
    }

    T pop() {
        if (topIndex == 0) {
            throw StackUnderflowException();
        }
        return data[--topIndex];
    }

    bool isEmpty() const {
        return topIndex == 0;
    }

    bool isFull() const {
        return topIndex >= Capacity;
    }
};

int main() {
    Stack<int> stack;

    try {
        for (int i = 1; i <= 6; ++i) {
            stack.push(i);
            cout << "Pushed: " << i << endl;
        }
    } 
    catch (const StackOverflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        while (true) {
            cout << "Popped: " << stack.pop() << endl;
        }
    } 
    catch (const StackUnderflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

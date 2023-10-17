#include <iostream>

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    char choice;
    int value;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter a value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case '2':
                stack.pop();
                break;
            case '3':
                std::cout << "Top of the stack: " << stack.peek() << std::endl;
                break;
            case '4':
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '4');

    return 0;
}


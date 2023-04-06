#include <iostream>
#include <chrono>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }


    void push(int data) {
        Node* node = new Node(data);
        node->next = top;
        top = node;
    }
    
    

    int pop() {
        if (top==NULL) {
            cout << "Stack is empty." << endl;
        }
        else{
            Node* tem = top;
            int data = tem->data;
            top = top->next;
            delete tem;
            return data;
        }
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    int stackTop() {
        if (top==NULL) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else{
            return top->data;
        }
    }

    void display() {
        if (top==NULL) {
            cout << "Stack is empty." << endl;
        }
        else{
            Node* current = top;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};


int main() {
    auto startTime = chrono::high_resolution_clock::now();
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto endTime = chrono::high_resolution_clock:: now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
   
    cout << "Time taken for stack implemented using linked list is: " <<duration <<endl;
    return 0;
}
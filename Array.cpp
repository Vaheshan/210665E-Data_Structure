#include <iostream>
#define MaxSize 20
#include <chrono>
using namespace std;

class Stack {
  private:
    int Stack_arr[MaxSize];
    int top;

  public:
    Stack() {
        top = -1;
    }
    void push(int value){
        if (top==MaxSize){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            Stack_arr[top]=value;
        }
    }
    
    void pop(){
        if (top==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MaxSize - 1;
    }


    int stackTop() {
        if (top==-1) {
            cout << "Stack is empty" <<endl;
        }
        else{
            return Stack_arr[top];
        }    
    }
    

    void display() {
        if (top==-1) {
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Elements are: ";
            for (int i = 0; i < top+1; i++) {
                cout << Stack_arr[i] << " ";
            }
            cout << endl;
        }    
    }
};

int main() {
    auto startTime1 = chrono::high_resolution_clock::now();
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

    auto endTime1 = chrono::high_resolution_clock:: now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1).count();
   
    cout << "Time taken for stack implemented using array is: " <<duration1 <<endl;
    return 0;
}
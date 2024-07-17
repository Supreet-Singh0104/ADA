#include<iostream>
using namespace std;

class Queue{
    private:
    int front,rear,size;
    int* queue;
    int capacity;
    public:
    Queue(int c){
        front=0,rear=0;
        capacity=c;
        queue=new int[capacity];
        size=0;
    }
    ~Queue(){
        delete[] queue;
    }
    void push(int data){
        if(size==capacity){
            cout<<"Queue is Full cannot insert "<<data<<endl;
            return ;
        }
        queue[rear]=data;
        rear++;
        size++;
    }
    void pop(){
        if(size==0){
            cout<<"Queuen is empty cannot pop"<<endl;
        }
        cout << "Popped element: " << queue[front] << endl;
        front++;
        size--;
    }
     void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[front+i] << " ";
        }
        cout << endl;
    }
};


int main(){
     Queue q(5); 

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.display();

    q.push(6); 

    q.pop();
    q.pop();

    q.display();

    q.push(6);
    q.push(7);

    q.display();
    return 0;
}
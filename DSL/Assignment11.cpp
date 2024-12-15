// Queues are frequently used in computer programming, and a typical example is the 
// creation of a job queue by an operating system. If the operating system does not use 
// priorities, then the jobs are processed in the order they enter the system. Write C++ 
// program for simulating job queue. Write functions to add job and delete job from 
// queue.
#include<iostream>
using namespace std;
int const my_max = 100;
class Queue{
    public:
    int arr[my_max];
    int front,rear;

    Queue():front(-1),rear(-1){}

    bool isEmpty();
    bool isFull();
    void insert(int n);
    int my_delete();
    void display();
};
bool Queue::isEmpty(){
    return front == -1;
}
bool Queue::isFull(){
    return front==0 and rear==my_max-1;
}
void Queue::insert(int n){
    if(isFull()){
        cout<<"\nOverflow";
    }
    else if(isEmpty()){
        front = rear=0;
        arr[rear] = n;
        cout<<"\nElement added";
    }
    else{
        arr[++rear] = n;
        cout<<"\nElement added";
    }
}
int Queue::my_delete(){
    int ele;
    if(isEmpty()){
        cout<<"\nUnderflow";
        return -1;
    }
    else if(front == rear){
        ele = arr[front];
        front = rear = -1;
        return ele;
    }
    else{
        ele = arr[front];
        front++;
        return ele;
    }
}
void Queue::display(){
    if(isEmpty()){
        cout<<"\nEmpty";
    }
    else{
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<"  ";
        }
    }
}

int main(){
    Queue q;
    char ch = 'y';
    int n,ele;

    while (ch=='y'){
        cout<<"\n1. Insert";
        cout<<"\n2. Delete";
        cout<<"\n3. Display";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice: ";
        cin>>n;

        switch(n){
            case 1:
                cout<<"\nEnter elemenet: ";
                cin>>ele;
                q.insert(ele);
                break;
            case 2:
                ele = q.my_delete();
                cout<<"\nElement delete: "<<ele;
                break;
            case 3:
                cout<<"\nElements are: "<<endl;
                q.display();
                break;
            case 4:cout<<"Exit"<<endl;
                    break;
            default :cout<<"Wrong choice";
        }
        cout<<"\nPress 'y' to continue:  ";
        cin>>ch;
    }
    return 0;
}

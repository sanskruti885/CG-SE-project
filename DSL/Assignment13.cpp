// A double-ended queue (deque) is a linear list in which additions and deletions may be 
// made at either end. Obtain a data representation mapping a deque into a one
// dimensional array. Write C++ program to simulate deque with functions to add and 
// delete elements from either end of the deque. 
#include<iostream>
using namespace std;

int const m_max = 100;
class Dequeue{
    public:
    int arr[m_max];
    int front,rear;

    Dequeue():front(-1), rear(-1) {}

    bool isEmpty();
    bool isFull();
    int pop_front();
    int pop_rear();
    void push_front(int a);
    void push_rear(int a);
    void display();
};

bool Dequeue::isEmpty(){
    return front == -1;
}
bool Dequeue :: isFull(){
    return front==0 and rear==m_max-1;
}
int Dequeue :: pop_front(){
    int ele;
    if(isEmpty()){
        cout<<"\nUnderFlow";
        return -1;
    }
    else if(front==rear){
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
int Dequeue :: pop_rear(){
    int ele;
    if(isFull()){
        cout<<"\nOverflow";
        return -1;
    }
    else if(front == rear ){
        ele = arr[rear];
        front = rear =-1;
        return ele;
    }
    else {
        ele = arr[rear];
        rear--;
        return ele;
    }
}
void Dequeue :: push_rear(int n){
    if(isFull()){
        cout<<"\nOverflow";
    }
    else if(isEmpty()){
        front = rear =0;
        arr[rear] = n;
        cout<<"\nElement added.";
    }
    else if(rear == m_max-1){
        cout<<"\nCannot add element.";
    }
    else{
        arr[++rear] = n;
        cout<<"\nAdded element";
    }
}
void Dequeue::push_front(int n){
    if(isFull()){
        cout<<"\nOverflow";
    }
    else if(isEmpty()){
        front = rear = 0;
        arr[front] = n;
    }
    else if(front==0){
        for(int i=rear;i>=front;i++){
            arr[i+1] = arr[i];
        }
        rear++;
        arr[front] = n;
        cout<<"\nAdded element";
    }
    else{
        arr[--front] = n;
        cout<<"\nAdded element";
    }
}

void Dequeue :: display(){
    cout<<endl;
    for(int i = front;i<=rear;i++){
        cout<<arr[i]<<"--";
    }
}

int main(){
    Dequeue d;
    int n,ele;
    char ch = 'y';
    while(ch == 'y'){
        cout<<"\n1. Push front";
        cout<<"\n2. Push rear";
        cout<<"\n3. Pop front";
        cout<<"\n4. Pop rear";
        cout<<"\n5. Display";
        cout<<"\nEnter your choice: ";
        cin>>n;

        switch(n){
            case 1: cout<<"\nEnter element: ";
                    cin>>ele;
                    d.push_front(ele);
                    break;
            case 2: cout<<"\nEnter element: ";
                    cin>>ele;
                    d.push_rear(ele);
                    break;
            case 3: ele = d.pop_front();
                    cout<<"\nPoped elemenyt: "<<ele;
                    break;
            case 4: ele = d.pop_rear();
                    cout<<"\nPoped element: "<<ele;
                    break;
            case 5: cout<<"\nElements: ";
                    d.display();
                    break;
            default: cout<<"Wrong choice";     
        }

        cout<<"\nPress 'y' to continue: ";
        cin>>ch;
    }

}
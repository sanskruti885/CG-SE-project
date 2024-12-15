// Write program to implement a priority queue in C++ using an inorder list to store the 
// items in the queue. Create a class that includes the data items (which should be template) 
// and the priority (which should be int). The inorder list should contain these objects, with 
// operator <= overloaded so that the items with highest priority appear at the beginning 
// of the list (which will make it relatively easy to retrieve the highest item.)
#include<iostream>
#include<list>
using namespace std;

template<class T>
class item{
    public:
    T data;
    int priority;

    item(T d, int p): data(d),priority(p){}

    bool operator <=(const item& other){
        return this->priority>=other.priority;
    }
};
template <class T>
class pri_queue{
    private:
    list<item<T>> queue;

    public:
    void enqueue(T data, int pri){
        item<T> newItem(data,pri);
        auto it = queue.begin();

        while(it!=queue.end() && *it<=newItem)
        { // operator overloaded check *it> increment
            ++it;
        }
        queue.insert(it,newItem); //position
    } 

    T dequeue(){
        if(queue.empty()){
            cout<<"\nEmpty Queue";
        }
        else{
            T ele = queue.front().data;
            queue.pop_front();
            return ele;
        }
    }

    void display(){
        if(queue.empty()){
            cout<<"\nEmpty queue";
        }
        else{
            for(const auto & it: queue){
                cout<<"\nData: "<<it.data<<", Priority: "<<it.priority;
            }
        }
    }
};

int main(){
    pri_queue<string> p;
    char ch='y';
    int pri;
    string data;

    while(ch == 'y'){
        cout << "\nPriority Queue Operations:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        int opt;
        cin >> opt;

        switch(opt){
            case 1:     
                cout<<"\nEnter data: ";
                cin>>data;
                cout<<"\nEnter priority: ";
                cin>>pri;
                p.enqueue(data,pri);
                break;
            case 2: data = p.dequeue();
                    break;
            case 3: cout<<"\nElements: ";
                    p.display();
                    break;
            case 4: cout<<"\nExit"<<endl;
            default: cout<<"\n Wrong choice!!!!";
        }
        cout<<"\nPress 'y' to continue:  ";
        cin>>ch;
    }
    return 0;
}
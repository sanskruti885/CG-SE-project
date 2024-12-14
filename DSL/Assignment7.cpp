// The ticket booking system of Cinemax theatre has to be implemented using C++ 
// program. There are 10 rows and 7 seats in each row. Doubly circular linked list has 
// to be maintained to keep track of free seats at rows. Assume some random booking 
// to start with. Use array to store pointers (Head pointer) to each row. On demand  
// a) The list of available seats is to be displayed  
// b) The seats are to be booked  
// c) The booking can be cancelled.  

#include<iostream>
using namespace std;

class Seat{
    public:
    int seatnum;
    bool isBook;
    Seat* next;
    Seat* prev;

    Seat(int num){
        seatnum = num;
        isBook=false;
        next=prev=nullptr;
    }
};

class Row{
    public:
    Seat* head;
    Seat* prevptr;

    Row(int seat_row){
        head = nullptr;
        prevptr = nullptr;

        for(int i=1;i<=seat_row;i++){
            Seat* newSeat = new Seat(i);
            if(head == nullptr){
                head = newSeat;
            }
            else{
                prevptr->next = newSeat;
                newSeat->prev = prevptr;
            }
            prevptr = newSeat;
        }
        head->prev = prevptr;
        prevptr->next = head;
    }

    bool book_seat(int num){
        Seat* temp = head;
        
        do{
            if(temp->seatnum == num ){
                if(!temp->isBook){
                    temp->isBook = true;
                    cout<<"\nSeat number : "<<num<<" booked successfully";
                    return true;
                }
                else{
                    cout<<"\nSeat already booked.";
                    return false;
                }
            }
            temp = temp->next;
        }while(temp!=head);

        cout<<"\nSeat not found!!!";
        return false;
    }

    bool cancel_seat(int seat){
        Seat* temp = head;

        do{
            if(temp->seatnum == seat){
                if(!temp->isBook){
                    cout<<"\nSeat is not booked so cannot be cancelled.";
                    return false;
                }
                else{
                    temp->isBook=false;
                    cout<<"\nSeat is cancelled"<<seat;
                    return true;
                }
            }
            temp=temp->next;
        }while(temp!=head);
        cout<<"\nSeat not found";
        return false;
    }

    void display_available(){
        Seat* temp=head;
        cout<<"\nSeat: ";
        do{
            if(!temp->isBook){
                cout<<temp->seatnum<<"->";
            }
            temp=temp->next;
        }while(temp!=head);
    }

    bool book_multi(int* arr, int size){
        Seat* temp=head;
        int count=0;
        for(int i=0;i<size;i++){
            do{
                if(temp->seatnum == arr[i]){
                    if(!temp->isBook){
                        temp->isBook=true;
                        count+=1;
                        break;
                    }
                    else{
                        cout<<"\nSeat already booked "<<temp->seatnum;
                        return false;
                    }
                }
                temp=temp->next;
            }while(temp!=head);
        }
        if(count == size){
            cout<<"\nALL seats booked";
            return true;
        }
        cout<<"\nSeat not found.";
        return false;
    }
};

void display_row(Row* r[],int num){
    for(int i=0;i<num;i++){
        cout<<"\nRow: "<<i+1;
        r[i]->display_available();
    }
}

bool check_input(int r, int s){
    if(r<0 || r>7 || s>10 || s<0){
        cout<<"\nInvalid input";
        return false;
    }
    return true;
}



int main(){
    int seatnum=10;
    int numrow=7;
    Row* r[seatnum];

    for(int i=0;i<numrow;i++){
        r[i] = new Row(seatnum);
    }
    char ch = 'y';
    int n;
    int row,seat;
    while(ch == 'y'){
        cout<<"\n1. Book a seat.";
        cout<<"\n2. Cancel a seat";
        cout<<"\n3. Display available seat in all row";
        cout<<"\n4. Book multiple seat";
        cout<<"\nEnter your choice: ";
        cin>>n;

        switch(n){
            case 1: cout<<"\nEnter row from 1-7 : ";
                    cin>>row;
                    cout<<"\nEnter seat number: ";
                    cin>>seat;
                    if(check_input(row,seat)){
                        r[row]->book_seat(seat);
                    }
                    break;
            case 2: cout<<"\nEnter row from 1-7 : ";
                    cin>>row;
                    cout<<"\nEnter seat number: ";
                    cin>>seat;
                    if(check_input(row,seat)){
                        r[row]->cancel_seat(seat);
                    }
                    break;

            case 3: cout<<"\nEnter till which row you want to see available seat: ";
                    cin>>seat;
                    display_row(r,seat);
                    break;

            case 4: cout<<"\nEnter number of seats: ";
                    cin>>n;
                    cout<<"\nEnter row: ";
                    cin>>row;
                    int arr[n];
                    cout<<"\nEnter seat number: ";
                    for(int i=0;i<n;i++){
                        cin>>arr[i];
                    } 
                    r[row]->book_multi(arr,n);
                    break;
        }

        cout<<"\nPress 'y' to continue or anything to end";
        cin>>ch;
    }
}
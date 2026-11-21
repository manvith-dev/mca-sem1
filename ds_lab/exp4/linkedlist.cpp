#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node* next;
};
struct node* head = NULL,*p,*q;

class Sll{

    public:
    int element; 
    void insertFromB(){
        
        cout <<"Enter the data to insert at the beginning: ";
        cin >> element;
        p=(struct node*)malloc(sizeof(struct node));
        p->data=element;
        if(head==NULL)
        {
            p->next=NULL;
            
        }
        else{
            p->next=head;
            
        }

        head=p;
    }

    void insertFromE(){
        cout <<"Enter the data to insert at the beginning: ";
        cin >> element;
        p=(struct node*)malloc(sizeof(struct node));
        p->data=element;

        if(head==NULL)
        {
            p->next=NULL;
            head=p;
        }

        else{
           q=head;

           while(q->next!=NULL)
           {
                q=q->next;
           }

           q->next=p;
           p->next=NULL;

            
        }

        
    }

    void display(){
        if(head==NULL)
        {
            cout << "List is empty" << endl;
        }

        else{
            q= head;
            cout << "The elements in the list are: ";

            while(q!=NULL){
                cout << q->data << "-> ";
                q=q->next;
            }
        }
       
    }

    void insertBeforeValue() {
        int value;
        cout << "Enter value :";
        cin >> value;

        cout <<"Enter the data to insert before value: ";
        cin >> element;
        

        q = head;
        p=(struct node*)malloc(sizeof(struct node));
        p->data = element;
        if (head != NULL && head->data == value) {
            p->next = head;
            head = p;
            return;
        }

        while (q != NULL && q->next->data != value) {
            q = q->next;
        }

        if (q == NULL) {
            cout << "Element not present in linked list";
            return;
        } else {
            p->next = q->next;
            q->next = p;
        }
    }

    void deleteelement() {
        int value;
        cout << "Enter value to delete: ";
        cin >> value;

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == value) {
            p = head;
            head = head->next;
            free(p);
            return;
        }

        q = head;
        while (q->next != NULL && q->next->data != value) {
            q = q->next;
        }

        if (q->next == NULL) {
            cout << "Element not present in linked list" << endl;
            return;
        } else {
            p = q->next;
            q->next = p->next;
            free(p);
        }
    }


};

//  1 2 3 4     7 
//        q
int main(){
    int ch;
    Sll obj;
    do{
        cout << "\n Enter Your choice: " << endl;
        cout << "1. Insert From Beginning" << endl;
        cout << "2. Insert From End" << endl;
        
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "5. Insert before a value" << endl;
        cin >> ch;
        switch(ch){
            case 1: 
                obj.insertFromB();
                break;
            case 2:
                obj.insertFromE();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            case 5:
            obj.insertBeforeValue();
            break;
            case 6:
                obj.deleteelement();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(ch != 4);
    return 0;
}
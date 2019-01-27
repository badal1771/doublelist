#include <iostream>
using namespace std;

class Node{
    public:
    // Data
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
//1-Insert
    void insert(int value){

        // Create a new node
        Node * temp = new Node(value);
        // Check if empty list
        if(head == NULL){
            head = temp;
        }
        else{
             Node * current = head; // If not empty list.
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
	//now make it circular like shift to tail and tail point to head
        temp->next = head;
    }
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements in the linked list " << endl;
            return;
        }
        while(current->next != head){
            cout << current -> data << "->";
            current = current -> next;
        }
        cout << current -> data ;
        cout << endl;
    }
    void InsertAt(int value, int pos){
	Node *temp=new Node(value);
	Node *current=head;
	int i=1;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	if(current->next==head){
		temp->next=head;
		current->next=temp;
	}
	else{
		temp->next=current->next;
		current->next=temp;
    	}
    }
    void DeleteAt(int pos){
	Node *current=head;
	int i=1;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	Node *temp;
	temp=current->next;
	current->next=temp->next;
	temp->next=NULL;
	delete temp;
    }
    void Dele(){
        Node *current=head;
	while(current->next->next!=head){
		current=current->next;
	}
	Node *temp;
	temp=current->next;
	current->next=head;
	temp->next=NULL;
	delete temp;
    }
    void CountItems(){
        Node *current=head;
	int i=1;
	while(current->next!=head){
		current=current->next;
		i++;
	}
	cout<<"Numbers of items in the circular linked list is : "<<i<<endl;
    }

};

int main(){
    CSLL csll1;
    for(int i= 1; i < 40; i++){
       csll1.insert(i);
    }
	csll1.display();
    csll1.InsertAt(32,25);
    csll1.display();
	csll1.CountItems();
	csll1.Del();
	csll1.display();
	csll1.CountItems();
	csll1.DeleteAt(6);
	csll1.display();
	csll1.CountItems();
return 0;
}

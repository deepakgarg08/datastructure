////
//// Created by deepak on 21.03.20.
////
//
#include <iostream>

using namespace std;


class Node{

public:
    int data;
    Node* next;
    Node* prev;
};

//2 Traverse linked list
void printDoubleLinkedList(Node *head_ref){
    cout<<endl;
    while (head_ref != NULL){

        cout << head_ref->prev << " : " << head_ref->data << "  :  " << head_ref->next << "-->  ";
        head_ref = head_ref ->next;
    }
}

int insertAtBegining( Node ** head_ref ,  int new_data){

    Node *new_node = new Node();
    new_node->data =  new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;


//    cout<<"check new_data  "<< new_node->data <<endl;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;

//    printDoubleLinkedList(*head_ref);
}

void insertAtEnd( Node ** head_ref ,  int new_data){

    Node *new_node = new Node();
    new_node->data =  new_data;
    new_node->next = NULL;

    Node *temp =  *head_ref;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (temp->next != NULL){
        temp = temp->next;
        cout << "\n...."<<temp; //why only cout influencing the output
    }
    temp->next = new_node;
    new_node->prev = temp;
//    printDoubleLinkedList(*head_ref);
}


void insertAfterPosition( Node * prev_node ,  int new_data) {

    if (prev_node == NULL) {
        cout << "pointer is null";
        return;
    }


    Node *new_node = new Node();
    cout<<"check new node add"<<new_node<<endl;
    cout<<"check new node add  prev"<<new_node->next;
    new_node->data = new_data;
    prev_node->next->prev = new_node;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
}

//deletion in linked list'

void deletion(Node ** head_ref ,  int position){
    Node *temp = *head_ref;
    if (*head_ref == NULL) {

        cout << "pointer is null";
        return;
    }
    if(position == 0){
        * head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i=0; temp->next != NULL && i<position-1; i++){
        temp = temp ->next;
    }
    Node *t = temp->next;

    temp ->next =t->next;

    temp->next->next->prev = temp->next->prev;
//    temp->next->next->prev = t->prev; //alternative

    free(t);
//
}
int main(){

    Node *head= NULL;

    insertAtBegining(&head,400);
    insertAtBegining(&head,300);
    insertAtBegining(&head,200);
    insertAtBegining(&head,100);

    insertAtEnd(&head, 500);
    printDoubleLinkedList(head);

//    insertAfterPosition(head->next->next, 80000);
    deletion(&head,2);
    cout<<"\n last print";
    printDoubleLinkedList(head);
    return 0;
}

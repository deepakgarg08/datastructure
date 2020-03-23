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

void printLinkedList(Node* n ){


    while(n!= NULL){

        cout<<" ->  "<< n << "::::" << n->data ;
//        cout<<" ->  "<< n << "::::" << n->data ;
        n = n->next;
        // cout<<"check n  "<<n <<endl;
    }
    cout<< endl;
}

//3insert new node at beginning
void insertAtBegining(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
    new_node ->prev = NULL;

//    Node *temp = new Node();
//    temp = *head_ref;
//   ( *head_ref) ->prev = new_node;


    /* 4. move the head to point to the new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
    printLinkedList(*head_ref);
}

//4insertion in the end

void insertAtEnd(Node** head_ref, int new_data)
{

    /* 1. allocate node */
    Node* new_node = new Node();
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. Make next of new node as null */
    new_node->next = NULL;
    //make a new temp last node and give header reference

    Node *last = new Node();

    last = *head_ref;
    while(last -> next != NULL){
        last = last->next;
        // cout<<"chekc last value"<<last <<endl;
    }

    last-> next = new_node;
    printLinkedList(*head_ref);
}

//5 insertion in between

void insertAfter(Node * prev_node, int new_data){


    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node -> next = prev_node->next;
    prev_node ->next = new_node;
    // printLinkedList(*head_ref);

}



//6 deletion of  node

//front,last, in between

void deletionAtBegining(Node** head_ref, int position )
{

    cout << "inside deletion \n";
    Node *temp = *head_ref;

    if (position == 0){
        *head_ref = temp ->next;
        free(temp);
        return;
    }

    // for (int i=0; )
    // cout<<"check value of temp  " << temp <<endl;
    // cout<<"check value of position  " << position <<endl;
    // cout<<"check temp of value  " << temp->data <<endl;

    // while(temp->next !=NULL && temp->next-> data != val){
    // temp = temp->next;
    // }
    // if(temp->next == NULL){
    // return;
    // }else{
    // Node *t = temp-> next;
    // temp->next = t->next;
    // free(t);
    // }


    for (int i=0; temp->next !=NULL && i<position-1; i++){
        temp= temp->next;
    }


    if(temp->next == NULL){
        return;
    }else{
        Node *t = temp-> next;
        temp->next = t->next;
        free(t);
    }

    return;

}


//void func(){
//
//    Node* head = new Node();
//    head -> data = 6;
//    Node *temp = head;
//
//    free(temp);
//
//    cout <<"rahul" << head->data<<endl;;
//
//}
//1create simple linked list

int main()
{

    Node* head = NULL;
    // Node* second = new Node();
    // Node* third = new Node();

    // cout << &head << endl;
    // cout << &second << endl;
    // cout << &third << endl;


    // head-> data = 110;
    // head -> next = second;

    // second-> data = 120;
    // second -> next = third;

    // third-> data = 130;
    // third -> next = NULL;
    // cout<< "check head   "<<head <<endl; //blank node address



//    func();

    insertAtBegining(&head, 200);
    insertAtBegining(&head, 100);

    // insertAfter(head->next,150);
    // insertAtEnd(&head, 200);
    insertAtEnd(&head, 300);
    insertAfter(head->next->next, 150);
    insertAtEnd(&head, 400);
    insertAtEnd(&head, 500);
    insertAtEnd(&head, 600);
    insertAtEnd(&head, 700);
    insertAtEnd(&head, 800);



    deletionAtBegining(&head, 4);
    // deletionAtBegining(&head, 6);
    // insertAfter(head->next->next->next,96350);

    printLinkedList(head);
    cout << "\n Hello Linked list creation" << endl;

    return 0;
}

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void insert(Node** ,int);
void deleteNode(Node** , int );
void update(Node** , int , int );
void reverse(Node** );
void printList(Node* );

int main(){
    Node* head = NULL;

    insert(&head, 2);
    insert(&head, 3;
    insert(&head, 4);
    insert(&head, 7);

    cout<<"Created Linked list is: "<<endl;
    printList(head);

    deleteNode(&head, 4);
    cout<<"Linked list after deleting 4: "<<endl;
    printList(head);

    update(&head, 3, 9);
    cout<<"Linked list after updation 'replacing 3 with 9': "<<endl;
    printList(head);

    reverse(&head);
    cout<<"Reversed linked list is: "<<endl;
    printList(head);

    return 0;
}

void insert(Node** head_ref, int new_data){
    Node* new_node = new Node;

    new_node->data = new_data;
 
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void deleteNode(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev = NULL;
    
    if (temp != NULL && temp->data == key){
        *head_ref = temp->next; 
        delete temp;            
        return;
    }
 
    else{
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    delete temp;
    }
}

void update(Node** head_ref, int old_data, int new_data){
    Node* temp;
    if(head_ref==NULL){
        cout<<"Linked list not initialized "<<endl;
        return;
    }
    temp = *head_ref;
    while(temp->next!=NULL){
        if(temp->data == old_data){
            temp->data = new_data;
            return;
        }
        temp = temp->next;
    }
    cout<<""<<old_data<<" does not exist in the list "<<endl;
}

void reverse(Node** head_ref){
    Node* temp = NULL;
    Node* prev = NULL;
    Node* current = *head_ref;
    while(current != NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

void printList(Node *node){
    while (node != NULL){
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int n){
        this->data = n;
        this->next = NULL;
    }
    
};

void printList(Node *last){
    if(last==NULL){
        cout << "List is Empty \n";
        return;
    }
    
    Node *temp = last->next;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp !=last->next);
}

Node* addtoEmpty(Node *last, int data){
    if(last!=NULL)  return last;
    Node *newNode = new Node(data);
    newNode->next = newNode;
    return newNode;
}

Node* addtoFront(Node *last, int data){
    if(last==NULL) addtoEmpty(last,data);
    
    Node *newNode = new Node(data);
    
    newNode->next = last->next;
    last->next = newNode;
    
    return last;
    
}


void deleteFromList(Node **last, int data){
    if(*last==NULL)  return;

    if( (*last)->next == *last && (*last)->data == data ){
        free(*last);
        *last = NULL;
        return;
    }
    
    Node *temp = *last, *curr;
    while(temp->next!=*last && temp->next->data!=data){
        temp = temp->next;
    }

    if(temp->next->data == data){
        curr = temp->next;
        temp->next = curr->next;
        free(curr);
    }
    else{
        cout << "\nKey not found";
    }

}


Node* addtoEnd(Node *last, int data){
    if(last==NULL)  addtoEmpty(last,data);
    Node *newNode = new Node(data);
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    
    return last;
}

int main() {
    
    Node *last = NULL;

    last = addtoEmpty(last, 5);
    last = addtoEnd(last, 7);
    last = addtoFront(last, 3);
    printList(last);
    deleteFromList(&last,4);
    cout << "\n";
    printList(last);
	
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *prev, *next;
        Node(int data){
            this->data = data;
            this->prev = NULL, this->next = NULL;
        }
};

set<int> hash_table;

void push(Node **head, int data){
 Node *newNode = new Node(data);
 newNode->next = NULL;

 if(*head==NULL){
     newNode->prev = NULL;
     *head = newNode;
     return;
 }

Node *last = *head;

while(last->next!=NULL){
    last = last->next;
}

last->next  = newNode;
newNode->prev = last;
}

void printList(Node *head){
    Node *temp  = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

}



void del(Node **head, int key){

    if(*head==NULL) return;

    Node *del = *head;

    if(del->data==key){
        *head = del->next;
        (*head)->prev = NULL;
        free(del);
        return;
    }

    while(key!=del->data){
        del = del->next;
    }

    if(del->next==NULL){
        del->prev->next = del->next;
        free(del);
        return;
    }

    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);


}

int largest(Node* head){

    Node *temp = head;
    int max = INT_MIN;

    while(temp){
        if(temp->data > max)
            max = temp->data;

        temp = temp->next;
    }

    return max;

}

void createHash(int max){

    int prev = 0, curr = 1;
    hash_table.insert(prev);
    hash_table.insert(curr);

    while(curr <= max){
        int temp = prev + curr;
        hash_table.insert(temp);
        prev = curr;
        curr = temp;
    }
}

void deleteFib(Node **head){

    int max = largest(*head);
    createHash(max);

    Node *temp = *head;

    while(temp){
        if(hash_table.find(temp->data)!=hash_table.end())
            del(head,temp->data);
        
        temp = temp->next;
    }

}

int main(){

    Node *head = NULL;
    push(&head,5);
    push(&head,7);
    push(&head,11);
    push(&head,13);
    push(&head,8);
    printList(head);
    deleteFib(&head);
    printList(head);

    return 0;
}
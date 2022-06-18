#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int n){
    this->data = n;
    this->next = NULL;
    }
};


void print_List(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}


int length_List(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }

    return count;
}

int middle_element(Node *head){
    Node *slow = head, *fast = head;
    int count = 0;
    while(head && fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

void middle_sqrt_len(Node *head){
    Node *temp = head, *sqrt = NULL, *middle=NULL;
    int count = 0, i = 1 , j = 1, n = 0 ;

    if(head){
        while(temp){
            
            if(i == j*j){
                if(!sqrt)
                    sqrt = head;
                else
                    sqrt = sqrt->next;
                j++;
            }

            if(count == 2*n){
                if(!middle)
                    middle = head;
                else
                    middle = middle->next;
                n++;
            }

            temp = temp->next;
            count++;
            i++;
        }
    }

int middleElement = count%2 ? middle->data : middle->next->data;

    cout << "\n" << count << " " <<   middleElement << " " <<  sqrt->data; 
}


int main(){
    
    Node *head = new Node(5);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(19);
    head->next->next->next->next->next = new Node(21);

    print_List(head);
    middle_sqrt_len(head);
    return 0;
}
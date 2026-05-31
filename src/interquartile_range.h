#include <iostream>
#include <iomanip>
using namespace std;

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* fast = head;
    Node* q1a = head;
    Node* q3a = head;
    Node* q1b = head;
    Node* q3b = head;
    int count = 0;
    double q3 = 0;
    double q1 = 0;
    while (fast!= nullptr){
      fast = fast->next;
      count += 1;
      if (count%4 == 1){
        if (q3a == head){
          q3a = q3a->next->next;
          q3b = q3b->next;
        }
        else {
            q3a = q3a->next->next->next;
            q3b = q3b->next->next->next;
        }
      }
      if (count %4 == 0){
        if (q1a == head) {
            q1a = q1a->next;
        }
        else {
            q1a = q1a->next;
            q1b = q1b->next;
        }
      }
    }
    if (count%4 == 0){
      q1 = q1a->value + q1b->value;
      q1 = q1/2;
      q3 = q3a->value + q3b->value;
      q3 = q3/2;
    }
    else if (count%2 == 0){
      q1 = q1a->value;
      q3 = q3b->value;
    }
    else{
      q1 = q1a->value;
      q3 = q3a->value;
    }
    cout << q1a->value << " " << q3a->value << endl;
    cout << q1b->value << " " << q3b->value << endl;
    return q3 - q1;
}

#include <iostream>
using namespace std;
class Node{
    public:
          int data;
          Node *next;
          
          Node(int value)
          {
              data = value;
              next = nullptr;
          }
};

class LinkedList 
{
    private:
        Node *head;
    public:
        LinkedList()
        {
            head = nullptr;
        }
        
        void InsertElement(int data)
        {
            Node *newNode = new Node(data);
            if(head == nullptr)
            {
                head = newNode;
            }else{
                Node *temp = head;
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        
        void RemoveDuplicates()
        {
            Node *temp = head;
            Node *val = nullptr;
            val = temp;
            while(temp->next != nullptr)
            {
                if(val->data == temp->next->data)
                {
                    temp = temp->next;
                    val->next = temp->next;
                }else{
                    val = temp;
                    temp = temp->next;
                }
            }
        }
        
        void display()
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList lst;
    lst.InsertElement(2);
    lst.InsertElement(2);
    lst.InsertElement(4);
    lst.InsertElement(5);
    lst.RemoveDuplicates();
    lst.display();
}
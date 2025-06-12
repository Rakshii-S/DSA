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

class LinkedList{
    private: 
        Node *head;
    public:
        LinkedList()
        {
            head = nullptr;
        }

        void InsertAtEnd(int value)
        {
            Node *newNode = new Node(value);
            if(head == nullptr)
            {
                head = newNode;
                return;
            }else
            {
                Node *temp = head;
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }    
                temp->next = newNode;
                return;
            }
        }

        void DeleteLastOccurrence(int key)
        {
           Node *temp = head;
           Node *eleAddress = nullptr;
           while(temp != nullptr)
           {
                if(temp->data == key)
                {
                    eleAddress = temp;
                }
                temp = temp->next;
           }

           if(eleAddress == nullptr)
           {
                cout<<"Element to be deleted is not found.";
                return;
           }else if(eleAddress == head)
           {
                head = eleAddress->next;
                return;
           }

           Node *temp1 = head;
           Node *prevAddress = nullptr;
           while(temp1 != nullptr)
           {
                if(eleAddress == temp1)
                {
                    break;
                }
                prevAddress = temp1;
                temp1 = temp1->next;
           }
           prevAddress->next = eleAddress->next;
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
    lst.InsertAtEnd(1);
    lst.InsertAtEnd(5);
    lst.InsertAtEnd(3);
    lst.InsertAtEnd(4);
    lst.InsertAtEnd(5);
    lst.DeleteLastOccurrence(5);
    lst.display();
}
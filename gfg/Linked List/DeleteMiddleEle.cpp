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

        void DeleteMiddleElement()
        {
            Node *temp = head;
            int length = 0;
            while(temp != nullptr)
            {
                length++;
                temp = temp->next;
            }

            if(length % 2 == 0)
            {
                int c = 0;
                Node *t = head;
                //I will get the next element address here
                while(c != (length/2)-1)
                {
                    t = t ->next;
                    c++;
                }
                t->next = t->next->next;
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
    lst.InsertAtEnd(2);
    lst.InsertAtEnd(4);
    lst.InsertAtEnd(6);
    lst.InsertAtEnd(7);
    lst.InsertAtEnd(5);
    lst.DeleteMiddleElement();
    lst.display();
}
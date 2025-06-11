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

        void InsertAtEnd(int data)
        {
            Node *newNode = new Node(data);
            if(head == nullptr)
            {
                head = newNode;
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

        void RotateList(int k)
        {
            Node *temp = head;
            Node *holdAddress = nullptr;
            int counter = 0;
            while(counter != k)
            {
                if(temp == nullptr)
                {
                    temp = head;
                }
                if(counter+1 == k)
                {
                    holdAddress = temp;
                }
                temp = temp->next;
                counter++;
            }
            //to rotate the list get the address of the k-1 element and set it next to nullptr to break the connection
            //this is done to prevent the loops
            holdAddress->next = nullptr;
            Node *swap = head;
            head = temp;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = swap;
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
    lst.InsertAtEnd(10);
    lst.InsertAtEnd(20);
    lst.InsertAtEnd(30);
    lst.InsertAtEnd(40);
    lst.InsertAtEnd(50);

    lst.RotateList(4);
    lst.display();
}
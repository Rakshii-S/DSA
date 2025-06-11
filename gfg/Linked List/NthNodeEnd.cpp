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

        void FindNthNode(int N)
        {
            //approach: reverse the array and check from the begining
            Node *prev = nullptr;
            Node *curr = head;
            Node *next = head;
            while(next != nullptr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            Node *temp2 = head;
            int counter =1 ;
            while(counter != N)
            {
                temp2 = temp2->next;
                counter++;
            }
            cout<<"Element at "<<N<<" is: "<<temp2->data;
            return;
        }
};

int main()
{
    LinkedList lst;
    lst.InsertAtEnd(35);
    lst.InsertAtEnd(15);
    lst.InsertAtEnd(4);
    lst.InsertAtEnd(20);

    lst.FindNthNode(4);
}
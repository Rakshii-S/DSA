#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int value)
        {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList
{
    private:
        Node *head;
    public:
        DoublyLinkedList()
        {
            head = nullptr;
        }

        void InsertValues(int data)
        {
            Node *newNode = new Node(data);
            if(head == nullptr)
            {
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }

        void Reverse()
        {
            Node *curr = head;
            Node *next = head;
            Node *prev = nullptr;

            while(next != nullptr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
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
    DoublyLinkedList dl;
    dl.InsertValues(20);
    dl.InsertValues(30);
    dl.InsertValues(100);
    dl.InsertValues(3);

    dl.Reverse();
    return 0;
}
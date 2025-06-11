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

        void InsertElement(int value)
        {
            Node *newNode = new Node(value);
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
            return;
        }

        Node *reverseList()
        {
            Node *curr = head, *next = head;
            Node *prev = nullptr;
            while(next != nullptr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            return head;
        }
};

int main()
{
    LinkedList lst;
    lst.InsertElement(50);
    lst.InsertElement(60);
    lst.InsertElement(89);
    lst.InsertElement(56);
    lst.InsertElement(66);
    lst.InsertElement(90);
    Node *root = lst.reverseList();
    cout<<"Reverse of list is: ";
    Node *temp = root;
    while(temp != nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } 
    return 0;
}
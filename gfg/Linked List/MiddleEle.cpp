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

    int MiddleElement()
    {
        Node *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
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
    int middleEle = lst.MiddleElement();
    cout<<"Middle element is: "<<middleEle;
    return 0;
}
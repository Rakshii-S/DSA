#include <iostream>
using namespace std;

class Node
{
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
        
        void display()
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void DeletNnodes(int n, int m)
        {
            Node *temp = head;
            Node *prev = nullptr;
            int counter = 1, countNode = 1;
            while(temp != nullptr)
            {
                //hold previous address
                if(counter == m)
                {
                    prev = temp;
                }
                //when it moves forward update the prev adress next part with its next next elements address
                if(counter == m+1 || countNode > 1)
                {
                    prev->next = temp->next;
                    counter = 0;
                    if(countNode == n)
                    {
                        countNode = 1;
                        counter++;
                        temp = temp->next;
                        continue;
                    }else{
                        countNode++;
                        temp = temp->next;
                        continue;
                    }
                }
                counter++;
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList lst;
    lst.InsertElement(1);
    lst.InsertElement(2);
    lst.InsertElement(3);
    lst.InsertElement(4);
    lst.InsertElement(5);
    lst.InsertElement(6);
    lst.InsertElement(7);
    lst.InsertElement(8);
    lst.DeletNnodes(2,3);
    lst.display();
}
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
        
        Node *InsertElement(int data)
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
           return head;
        }
        
        bool DetectCycle()
        {
            Node *slow = head;
            Node *fast = head;

            while(slow && fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast)
                {
                    return true;
                }
            }
            return false;
        }   
};

int main()
{
    LinkedList lst;
    lst.InsertElement(1);
    lst.InsertElement(3);
    lst.InsertElement(4);
    Node *head = lst.InsertElement(3);

    //Create a loop
    head->next->next->next = head->next;      
    bool ans = lst.DetectCycle();
    if(ans == true)
    {
        cout<<"Cycle detected.";
    }else{
        cout<<"Cycle not detected.";
    }

    return 0;
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
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

        void insert(int data) 
        {
            Node* newNode = new Node(data);
            if (head == nullptr)
                head = newNode;
            else 
            {
                Node* temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;
            }
        }

        void display() 
        {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        // Function to merge second list into first at alternate positions
        void mergeAlternating(LinkedList &list2) 
        {
            Node* temp1 = head;
            Node* temp2 = list2.head;

            Node* next1;
            Node* next2;

            // While there are available positions in both lists
            while (temp1 != nullptr && temp2 != nullptr) 
            {
                next1 = temp1->next;
                next2 = temp2->next;

                // Inserting node from list2 into list1
                temp1->next = temp2;
                temp2->next = next1;

                // Move to next nodes
                temp1 = next1;
                temp2 = next2;
            }

            // Update head of list2 to remaining nodes (if any)
            list2.head = temp2;
        }
};

int main() {
    LinkedList list1, list2;

    // Creating list1: 1 → 2 → 3
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    // Creating list2: 4 → 5 → 6 → 7 → 8
    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);

    // Merge
    list1.mergeAlternating(list2);

    cout << "\nAfter merging:\n";
    cout << "List 1: ";
    list1.display();

    cout << "Remaining List 2: ";
    list2.display();

    return 0;
}

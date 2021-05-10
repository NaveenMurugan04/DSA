#include <iostream>
using namespace std;

class Node
{
public:
    char ch;
    Node *next = NULL;

    Node(char newData)
    {
        ch = newData;
    }
};

class LinkedList
{
public:
    Node *head = NULL;

    void insert(char newData)
    {
        Node *new_node = new Node(newData);
        if (head != NULL)
        {
            new_node->next = head;
        }
        head = new_node;
    }

    void deleteElement(char element)
    {

        if (head != NULL && head->ch == element)
        {

            head = head->next;
            return;
        }

        Node *traversalNode = head;

        while (traversalNode != NULL && traversalNode->next != NULL)
        {

            if (traversalNode->next->ch == element)
            {
                Node *del = traversalNode->next;

                traversalNode->next = traversalNode->next->next;

                free(del);
            }

            traversalNode = traversalNode->next;
        }
    }

    void reverse()
    {
        Node *next = NULL;
        Node *prev = NULL;
        Node *curr = head;
        Node *temp = NULL;

        while (curr != NULL)
        {

            temp = curr->next;
            next = curr;
            next->next = prev;
            prev = next;
            curr = temp;
        }
        head = next;
    }

    void display()
    {
        Node *traversalNode = head;
        while (traversalNode != NULL)
        {
            cout << traversalNode->ch << " ";

            traversalNode = traversalNode->next;
        }
    }
};

int main()
{

    LinkedList ll = LinkedList();

    ll.insert('A');
    ll.insert('S');
    ll.insert('D');

    ll.insert('B');
    ll.insert('Y');
    ll.deleteElement('B');
    ll.display();
    ll.reverse();
    cout << "\nAfter reversed \n";

    ll.display();
    return 0;
}
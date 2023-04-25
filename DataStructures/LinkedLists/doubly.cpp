#include <iostream>
using namespace std;

class Node
{
public:
    char ch;
    Node *next = NULL;
    Node *prev = NULL;
    Node(char newData)
    {
        ch = newData;
    }
};

class DoublyLinkedList
{
public:
    Node *head = NULL;

    void reverseList()
    {
        Node *traverse = head;
        Node *next = NULL;
        Node *prev = NULL;
        while (traverse != NULL)
        {
            next = traverse->next;

            traverse->next = prev;
            traverse->prev = next;
            prev = traverse;
            traverse = next;
        }
        head = prev;
    }

    void deleteElement(char key)
    {
        if (head->ch == key)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {

            Node *traverse = head;

            while (traverse != NULL)
            {
                if (traverse->next != NULL && traverse->next->ch == key)
                {
                    Node *del = traverse->next;
                    traverse->next = del->next;
                    del->prev = traverse;
                    free(del);
                    break;
                }
                traverse = traverse->next;
            }
        }
    }

    void insertAfter(char keyValue, char newData)
    {
        Node *newNode = new Node(newData);
        Node *traverseNode = head;
        while (traverseNode != NULL)
        {
            if (traverseNode->ch == keyValue)
            {
                newNode->next = traverseNode->next;
                newNode->prev = traverseNode;
                traverseNode->next = newNode;
                break;
            }

            traverseNode = traverseNode->next;
        }
    }

    void insertLast(char newData)
    {
        Node *newNode = new Node(newData);

        if (head != NULL)
        {
            Node *traverseNode = head;

            while (traverseNode != NULL)
            {

                if (traverseNode->next == NULL)
                {
                    newNode->prev = traverseNode;
                    traverseNode->next = newNode;
                    break;
                }

                traverseNode = traverseNode->next;
            }
        }
        else
            head = newNode;
    }

    void insertFirst(char newData)
    {
        Node *newNode = new Node(newData);

        if (head != NULL)
        {
            newNode->next = head;
            head->prev = newNode;
        }

        head = newNode;
    }

    void display()
    {

        Node *traverseNode = head;

        while (traverseNode != NULL)
        {
            cout << traverseNode->ch << " ";
            traverseNode = traverseNode->next;
        }
    }
};

int main()
{

    DoublyLinkedList ll = DoublyLinkedList();

    ll.insertFirst('H');
    ll.insertFirst('E');
    ll.insertFirst('L');

    ll.insertFirst('L');
    ll.insertFirst('O');
   /*  ll.insertLast('W');
    ll.insertLast('O');
    ll.insertAfter('O', 'R');
    ll.insertAfter('R', 'L'); */

  //  ll.deleteElement('L');

    ll.display();
    ll.reverseList();
    cout << "\nAfter reversed \n";
    ll.display();

    return 0;
}
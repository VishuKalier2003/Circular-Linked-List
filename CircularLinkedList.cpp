// Circular Linked List Implementation
#include <iostream>
#include <type_traits>
using namespace std;
class Node                    // Node class
{                                        
    public:
    int data;            // Data member
    Node* next;          // Data member
    public:
    Node(int val)                // Parametrized Constructor
    {data = val;next = NULL;}
};
class CircularLinkedList
{
    public:
    void InsertAtHead(Node* &head, int val)     // Inserting at Head
    {
        Node* n = new Node(val);     
        if(head == NULL)              // If Head is Null or List is Empty
        {
            n -> next = n;           // Next of New Node points to itself
            head = n;                // Head becomes the New Node
            return;
        }
        Node* temp = head;              //  Temporary Node created
        while(temp -> next != head)
        {
            temp = temp -> next;           // Incrementing Temporary pointer
        }
        temp -> next = n;        // Appending the New Node at Head
        n -> next = head;        
        head = n;
    }
    public:
    void InsertAtTail(Node* head, int val)  // Function to Insert at Tail
    {
        if(head == NULL)              //  If head is Null or List is Empty
        {
            InsertAtHead(head, val);
            return;                         // The function ends after block execution
        }
        Node* n = new Node(val);              // New Node created
        Node* temp = head;
        while(temp -> next != head)
        {
            temp = temp -> next;               // Incrementing Temporary pointer
        }
        temp -> next = n;        // Appending the New Node
        n -> next = head;
    }
    public:
    void DisplayCircularLinkedList(Node* &head)
    {
        Node* temp = head;     // Temporary Node created
        cout << "The Circular Linked List formed is : " << endl;
        do
        {
            cout << "" << temp -> data << " -> ";
            temp = temp -> next;                 // Incrementing Temporary pointer
        }while(temp -> next != head);              // If while loop is used then we cant enter the loop 
        cout << "Head" << endl;            // itself since temp is equal to head
    } 
};
int main()       // main function begins
{
    Node* head = NULL;               // First pointer specified to Null
    CircularLinkedList object;       // Object creation
    int s, x;
    cout << "Enter the Number of Nodes of the Circular Linked List : ";
    cin >> s;
    for(int i = 1; i <= s; i++)
    {
        cout << "Enter Node data : ";
        cin >> x;
        object.InsertAtTail(head, x);    // Function for Inserting at Tail
    }
    object.DisplayCircularLinkedList(head);   // Displaying Circular List
}
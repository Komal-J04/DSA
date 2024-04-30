// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

// APPROACH 1 - TLE
//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *prev = NULL;
        Node *curr = head;
        Node *forward;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtTail(Node *&sum, int x)
    {
        Node *newNode = new Node(x);

        if (sum == NULL)
        {
            sum = newNode;
            return;
        }

        Node *temp = sum;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    Node *add(Node *num1, Node *num2)
    {
        Node *temp1 = num1;
        Node *temp2 = num2;

        Node *sum = NULL;
        int carry = 0;

        while (temp1 != NULL && temp2 != NULL)
        {
            int x = temp1->data + temp2->data + carry;
            int digit = x % 10;

            insertAtTail(sum, digit);

            carry = x / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != NULL)
        {
            int x = temp1->data + carry;
            int digit = x % 10;

            insertAtTail(sum, digit);

            carry = x / 10;
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            int x = temp2->data + carry;
            int digit = x % 10;

            insertAtTail(sum, digit);

            carry = x / 10;
            temp2 = temp2->next;
        }

        while (carry != 0)
        {
            int digit = carry % 10;

            insertAtTail(sum, digit);

            carry = carry / 10;
        }

        return sum;
    }

    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node *sum = add(num1, num2);
        sum = reverse(sum);

        while (sum->data == 0 && sum->next != NULL)
            sum = sum->next; // adding the sum->next because the test case can be 0+0 ; then it will point to null if we do not add that condition

        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *num1 = buildList(n);

        cin >> m;
        Node *num2 = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2
//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *prev = NULL;
        Node *forward;

        while (head != NULL)
        {
            forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;
        }

        return prev;
    }

    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node *sum = NULL;
        Node *tail = NULL;
        Node *temp1 = num1;
        Node *temp2 = num2;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            int x = (temp1 ? temp1->data : 0) + (temp2 ? temp2->data : 0) + carry;

            Node *newNode = new Node(x % 10);
            if (sum == NULL)
            {
                sum = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            carry = x / 10;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }

        sum = reverse(sum);
        while (sum->data == 0 && sum->next != NULL)
            sum = sum->next; // adding the sum->next because the test case can be 0+0 ; then it will point to null if we do not add that condition

        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *num1 = buildList(n);

        cin >> m;
        Node *num2 = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
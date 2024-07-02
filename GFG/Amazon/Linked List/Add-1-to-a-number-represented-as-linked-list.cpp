// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/add-1-to-a-number-represented-as-linked-list

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    void reverse(Node *&head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        head = prev;
    }
    void add(Node *&head)
    {
        if (head->data < 9)
        {
            head->data = head->data + 1;
            return;
        }

        int carry = 1;
        Node *temp = head;
        while (temp != NULL && carry != 0)
        {
            if (temp)
            {
                int sum = temp->data + carry;
                temp->data = sum % 10;
                carry = sum / 10;
                temp = temp->next;
            }
        }

        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        while (carry != 0)
        {
            Node *newNode = new Node(carry % 10);
            tail->next = newNode;
            tail = newNode;
            carry = carry / 10;
        }
    }
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        reverse(head);
        add(head);
        reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
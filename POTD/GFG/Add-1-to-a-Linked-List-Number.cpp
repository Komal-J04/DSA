// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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
        while (curr)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }

    void add(Node *&head)
    {
        if (head->data < 9)
        {
            head->data += 1;
            return;
        }

        int sum = 0, carry = 1;
        Node *temp = head;
        Node *prev = head;
        while (temp || carry)
        {
            if (temp)
                sum = temp->data + carry;
            else
                sum = carry;
            if (temp)
                temp->data = sum % 10;
            else
            {
                prev->next = new Node(sum % 10);
                prev = prev->next;
            }
            carry = sum / 10;
            prev = temp;
            if (temp)
                temp = temp->next;
        }
    }

    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        if (!head)
            return head;

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
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        if (arr.empty())
        {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
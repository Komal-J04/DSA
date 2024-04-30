// https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Link list Node */
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

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

// } Driver Code Ends
/* Link list Node

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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        // Your code here
        if (head == NULL || K == 1)
            return NULL;

        Node *prev = head;
        Node *nex = head;
        int count = 1;
        while (nex) // nex->next can't be accessed if nex=null
        {
            while (count < K && nex->next)
            {
                prev = nex;
                nex = nex->next;
                count++;
            }

            // We exit from while loop either because count>=K or nex->next=null. We want to update pointers only is count>=K, but if nex->next=null, we just exit out of the loop because in that case, we do not want to update the pointers since it is probably not the Kth node.

            if (count != K)
                break; // if k > current length of the list

            prev->next = nex->next;
            delete nex;
            nex = prev->next;
            count = 1;
        }

        return head;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        int K;
        cin >> K;
        Solution obj;
        Node *res = obj.deleteK(head, K);
        Node *temp = res;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
#include <bits/stdc++.h>
/*************************************************
        Following is the structure of class Node:

        class Node{
        public:
            int data;
            Node* next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }

        }
**************************************************/

// SOLUTION 1
//  T.C. - O(n) [Traversing n nodes]     S.C. - O(1) [Iterative approach]
bool isCircular(Node *head)
{
    // 0 nodes
    if (head == NULL)
        return true;

    //>=1 node
    Node *temp = head->next;
    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return false;

    return true; // temp==head
}

// SOLUTION 2 - Recursive approach
//  T.C. - O(n) [Traversing n nodes]     S.C. - O(n) [Recursive stack space]
bool check(Node *temp, Node *head)
{
    if (temp == NULL)
        return false;
    if (temp == head)
        return true;

    return check(temp->next, head);
}

bool isCircular(Node *head)
{
    // 0 nodes
    if (head == NULL)
        return true;

    Node *temp = head->next;

    return check(temp, head);
}

// SOLUTION 3 - using a map
//  T.C. - O(n) [Traversing n nodes]     S.C. - O(n) [Map]
bool isCircular(Node *head)
{

    if (head == NULL)
        return true;

    map<Node *, bool> map;
    Node *temp = head->next;
    map[head] = true;
    while (temp != NULL && temp != head)
    {
        if (map[temp] == true)
            return false; // temp wont be head because that is the condition
        temp = temp->next;
    }

    if (temp == NULL)
        return false;
    if (temp == head)
        return true;
}
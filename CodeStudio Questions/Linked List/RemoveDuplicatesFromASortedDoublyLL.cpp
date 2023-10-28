/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *removeDuplicates(Node *head)
{
    Node *pre = head;
    Node *curr = head;

    while (curr != NULL)
    {
        curr = curr->next;

        if (curr != NULL && curr->data == pre->data)
        {
            pre->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = pre;

            curr->next = NULL;
            curr->prev = NULL;
            delete curr;

            curr = pre;
        }
        // if the curr node has same data, in the if condition curr=pre and then we increment pre to next node, and in next iteration, curr is also incremented which means it also also point to the same node as pre now=> data will definitely be equal and all pointers will be changed unnecesarily.
        else
        {
            pre = pre->next;
        }
    }
    return head;
}

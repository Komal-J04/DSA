/*************************************************

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *startNode(Node *head)
{
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    if (fast == NULL)
        return NULL;

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
        return head;

    Node *loopStartNode = startNode(head);

    if (loopStartNode == NULL)
        return head;

    Node *temp = loopStartNode;

    while (temp->next != loopStartNode)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}
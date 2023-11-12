/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

********************************************************************/
node *findMid(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *mergeList(node *left, node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    // merge 2 sorted LL
    while (left && right)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        else
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }

    while (left)
    {
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }

    while (right)
    {
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }

    return ans->next;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // break LL into 2 halves
    node *mid = findMid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // merge left and right halves
    node *result = mergeList(left, right);

    return result;
}

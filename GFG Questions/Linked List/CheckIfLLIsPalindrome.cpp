/* struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

// This modifies the original head pointer even though it is not passed by reference
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *revHead = reverse(head);

        Node *temp1 = head;
        Node *temp2 = revHead;

        while (temp1 && temp2)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};

// SOLN - Using an array (Can use string also)
// S.C. - O(N) [new array]      T.C. - O(N) + O(N/2) = O(N)
class Solution
{
public:
    void print(Node *head)
    {
        Node *temp = head;
        cout << "Current state of the linked list - ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        Node *revHead = reverse(head);
        print(revHead);
        print(head);

        Node *temp1 = head;
        Node *temp2 = revHead;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
            cout << temp1->data << " " << temp2->data << endl;
        }

        return true;
    }
};

// SOLN 2
// S.C. - O(1)      T.C. - O(N)
class Solution
{
public:
    Node *midNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *fwd = NULL;

        while (curr)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        // find middle
        Node *mid = midNode(head);

        // reverse LL after middle
        Node *temp = mid->next;
        mid->next = reverse(temp);

        // compare both halves
        Node *head1 = head;
        Node *head2 = mid->next;
        while (head2)
        {
            if (head1->data != head2->data)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};
class Solution
{
public:
    Node *reverse(Node *&head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *fwd;
        while (curr)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

    void insertAtTail(Node *&head, int digit)
    {
        Node *newNode = new Node(digit);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    Node *add(Node *head)
    {
        if (head->data < 9)
        {
            head->data = head->data + 1;
            return head;
        }

        int carry = 1;
        Node *temp = head;
        Node *ans = NULL;
        while (temp || carry != 0)
        {
            int val1 = 0;
            if (temp)
                val1 = temp->data;

            int sum = val1 + carry;
            int digit = sum % 10;

            insertAtTail(ans, digit);

            carry = sum / 10;
            if (temp)
                temp = temp->next;
        }
        return ans;
    }

    Node *addOne(Node *head)
    {
        head = reverse(head);

        Node *ans = add(head);

        return reverse(ans);
    }
};
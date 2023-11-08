/* struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

// SOLN 1
class Solution
{
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

    Node *add(Node *first, Node *second)
    {
        Node *ans = NULL;
        Node *temp1 = first;
        Node *temp2 = second;
        int carry = 0; // initially carry is 0
        while (temp1 != NULL && temp2 != NULL)
        {
            int sum = temp1->data + temp2->data + carry;
            int digit = sum % 10;

            insertAtTail(ans, digit);

            carry = sum / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
            // cout<<digit<<" "<<carry<<endl;
        }

        while (temp1)
        {
            int sum = temp1->data + carry;
            insertAtTail(ans, sum % 10);

            carry = sum / 10;
            temp1 = temp1->next;
        }

        while (temp2)
        {
            int sum = temp2->data + carry;
            insertAtTail(ans, sum % 10);

            carry = sum / 10;
            temp2 = temp2->next;
        }

        while (carry != 0)
        {
            int sum = carry;
            insertAtTail(ans, sum % 10);

            carry = sum / 10;
        }

        return ans;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // step 1 - reverse input LL
        first = reverse(first);
        second = reverse(second);

        // step 2 - add both LL
        Node *ans = add(first, second);

        // step 3 - reverse ans;
        return reverse(ans);
    }
};

// SOLN 2
// T.C. - O(M+N)    S.C.-O(max(M,N)) [new LL]
class Solution
{
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

    Node *add(Node *first, Node *second)
    {
        Node *ans = NULL;
        Node *temp1 = first;
        Node *temp2 = second;
        int carry = 0; // initially carry is 0
        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            int val1 = 0, val2 = 0;
            if (temp1)
                val1 = temp1->data;
            if (temp2)
                val2 = temp2->data;
            int sum = val1 + val2 + carry;
            int digit = sum % 10;

            insertAtTail(ans, digit);

            carry = sum / 10;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }

        return ans;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // step 1 - reverse input LL
        first = reverse(first);   // O(N)
        second = reverse(second); // O(M)

        // step 2 - add both LL
        Node *ans = add(first, second); // O(max(M,N))

        // step 3 - reverse ans;
        return reverse(ans); // O(N)
    }
};
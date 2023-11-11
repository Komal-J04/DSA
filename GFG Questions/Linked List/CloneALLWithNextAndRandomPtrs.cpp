// SOLN 1
//  T.C.-O(n)    S.C.-O(n)
class Solution
{
public:
    void insertAtTail(Node *&head, int data)
    {
        Node *newNode = new Node(data);
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

    Node *copyList(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *newHead = new Node(head->data);

        // step 1
        Node *temp = head->next;
        while (temp != NULL)
        {
            insertAtTail(newHead, temp->data);
            temp = temp->next;
        }

        // step 2
        map<Node *, Node *> mpp;
        temp = head;
        Node *temp2 = newHead;
        while (temp != NULL && temp2 != NULL)
        {
            mpp[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }

        // step 3
        temp = head;
        temp2 = newHead;
        while (temp != NULL && temp2 != NULL)
        {
            if (temp->arb)
                temp2->arb = mpp[temp->arb];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};

// SOLN 2 - works for small test cases because we are calling the find function for every node
//  T.C.-O(n^2)    S.C.-O(1)
class Solution
{
public:
    void insertAtTail(Node *&head, int data)
    {
        Node *newNode = new Node(data);
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

    Node *find(Node *head, int data)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == data)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    Node *copyList(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *newHead = new Node(head->data);
        Node *temp = head->next;
        while (temp)
        {
            insertAtTail(newHead, temp->data);
            temp = temp->next;
        }

        Node *temp2 = newHead;
        temp = head;
        while (temp && temp2)
        {
            if (temp->arb)
            {
                Node *search = find(newHead, temp->arb->data);
                if (search)
                {
                    temp2->arb = search;
                }
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};

// SOLN 3
//  T.C.-O(n)    S.C.-O(1)
class Solution
{
public:
    void insertAtTail(Node *&head, int data)
    {
        Node *newNode = new Node(data);
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

    Node *copyList(Node *head)
    {
        if (head == NULL)
            return NULL;

        // step 1 : create a clone list
        Node *newHead = new Node(head->data);
        Node *temp = head->next;
        while (temp)
        {
            insertAtTail(newHead, temp->data);
            temp = temp->next;
        }

        // step 2 : add clone nodes between original list
        temp = head;
        Node *temp2 = newHead;
        while (temp && temp2)
        {
            Node *next1 = temp->next;
            temp->next = temp2;
            temp = next1;
            Node *next2 = temp2->next;
            temp2->next = temp;
            temp2 = next2;
        }

        // step 3 : copy arb pointers
        temp = head;
        while (temp)
        {
            if (temp->arb)
                temp->next->arb = temp->arb->next;
            temp = temp->next->next;
        }

        // step 4 : revert changes done in step 2
        temp = head;
        temp2 = newHead;
        while (temp && temp2)
        {
            temp->next = temp2->next;
            temp = temp->next;
            if (temp)
                temp2->next = temp->next;
            temp2 = temp2->next;
        }

        // step 5 : return ans
        return newHead;
    }
};
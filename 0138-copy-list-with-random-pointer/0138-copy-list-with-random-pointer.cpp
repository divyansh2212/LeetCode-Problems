class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        // copying a linked list
        Node *temp = head, *front = head;
        while (temp)
        {
            Node *node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }

        // assigning random pointers
        temp = head;
        while (temp)
        {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        Node *dummynode = new Node(-1);
        Node *dummytemp = dummynode;
        while (temp)
        {
            dummytemp->next = temp->next;
            dummytemp = dummytemp->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummynode->next;
    }
};
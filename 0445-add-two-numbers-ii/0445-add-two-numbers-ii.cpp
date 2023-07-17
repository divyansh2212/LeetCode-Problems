
class Solution
{
    int length(ListNode *head)
    {
        int l = 0;
        ListNode *temp = head;
        while (temp)
            l++, temp = temp->next;
        return l;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = length(l1), len2 = length(l2);
        if (len2 > len1)
            swap(l1, l2), swap(len2, len1);

        vector<int> arr(len1, 0);
        ListNode *temp1 = l1, *temp2 = l2;
        int idx = 0;

        while (len1 != len2)
        {
            arr[idx] = temp1->val;
            temp1 = temp1->next;
            idx++, len1--;
        }

        while (temp1)
        {
            arr[idx] = temp1->val + temp2->val;
            temp1 = temp1->next, temp2 = temp2->next;
            idx++;
        }

        int carry = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] > 9)
            {
                if (i == 0)
                    arr[i] = arr[i] % 10, carry++;
                else
                    arr[i - 1]++, arr[i] = arr[i] % 10;
            }
        }

        temp1 = l1, idx = 0;
        while (temp1)
        {
            temp1->val = arr[idx];
            idx++, temp1 = temp1->next;
        }

        if (carry)
        {
            ListNode *newhead = new ListNode(1);
            newhead->next = l1;
            l1 = newhead;
        }

        return l1;
    }
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummysmall = new ListNode(1000), *dummylarge = new ListNode(1000);
        ListNode *tempsmall = dummysmall, *templarge = dummylarge;

        ListNode *temp = head;

        while (temp != NULL)
        {
            if (temp->val < x)
            {
                tempsmall->next = temp;
                tempsmall = tempsmall->next;
            }
            else
            {
                templarge->next = temp;
                templarge = templarge->next;
            }
            temp = temp->next;
        }

        if (templarge->next != NULL)
            templarge->next = NULL;
        dummylarge = dummylarge->next;
        tempsmall->next = dummylarge;
        return dummysmall->next;
    }
};
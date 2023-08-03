/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        
        while(fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        return slow;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        while(temp1 && temp2)
        {
            if(temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        while(temp1)
        {
                temp->next = temp1;
                temp1 = temp1->next;
            temp = temp->next;
        }
        while(temp2)
        {
                temp->next = temp2;
                temp2 = temp2->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* middle = findMiddle(head);
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(middle);
        
        return merge(l1, l2);
    }
};
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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
public:
    void reorderList(ListNode* head) {
        
        if(head->next == NULL)
            return;
        
        ListNode* middle = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast && fast->next)
        {
            prev = middle;
            middle = middle->next;
            fast= fast->next->next;
        }
        prev->next = NULL;
        
        
        ListNode* reverseList = reverse(middle);
        
        ListNode* temp1 = head;
        ListNode* temp2 = reverseList;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(temp1 && temp2) {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        
        head = dummy->next;
    }
};
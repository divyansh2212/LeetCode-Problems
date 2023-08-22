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
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) 
    {
        ListNode* dummynode = new ListNode(-1);
        ListNode* ptr3 = dummynode;
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        int carry=0;
        
        while(ptr1 && ptr2)
        {
            int currval = ptr1->val + ptr2->val + carry;
            if(currval > 9) {
                currval = currval % 10;
                carry = 1;
            }
            else 
                carry = 0;
            ptr3->next = new ListNode(currval);
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        
        while(ptr1) {
            int currval = ptr1->val + carry;
            if(currval > 9) {
                currval = currval % 10;
                carry = 1;
            }
            else 
                carry = 0;
            ptr3->next = new ListNode(currval);
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
        while(ptr2) {
            int currval = ptr2->val + carry;
            if(currval > 9) {
                currval = currval % 10;
                carry = 1;
            }
            else 
                carry = 0;
            ptr3->next = new ListNode(currval);
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
        
        if(carry>0)
        {
            ptr3->next = new ListNode(carry);
            ptr3 = ptr3->next;
        }
        ptr3->next = NULL;
        return dummynode->next;
    }
};
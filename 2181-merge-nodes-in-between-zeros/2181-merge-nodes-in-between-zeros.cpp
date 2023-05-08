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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* dummytemp = dummyNode;
        
        ListNode* temp = head;
        int curr = 0;
        while(temp){
            if(temp->val == 0 && curr != 0){
                
                dummytemp->next = new ListNode(curr);
                dummytemp = dummytemp->next;
                curr = 0;
                
            }else{
                curr += temp->val;
            }
            temp = temp->next;
        }
        
        return dummyNode->next;
    }
};
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
    
    int length(ListNode* head)
    {
        int l = 0;
        ListNode* temp = head;
        while(temp){
            l++; temp = temp->next;
        }
        return l;
    }
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* temp1 = head;
        int cnt1 = 1;
        
        ListNode* temp2 = head;
        int cnt2 = 1;
        
        int len = length(head);
        
        while(temp1) {
            if(cnt1 == k) 
                break;
            cnt1++; temp1 = temp1->next;
        }
        
        while(temp2) {
            if(cnt2 == len - k + 1) 
                break;
            temp2 = temp2->next;
            cnt2++;
        }
        
//         temp1 = head;
//         cnt1 = 1;
//         while(temp1)
//         {
//             if(cnt1 == k)
//             {
//                 temp1->val = val2;
//                 break;
//             }
//             cnt1++;
//         }
        
//         cout << val1 << " " << val2;
        swap(temp1->val, temp2->val);
        
        return head;
    }
};
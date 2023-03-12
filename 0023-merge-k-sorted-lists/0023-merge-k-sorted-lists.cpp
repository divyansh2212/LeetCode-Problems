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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(-100000);
        ListNode* temp = dummyHead;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        
        while(!pq.empty())
        {
            int top = pq.top(); pq.pop();
            temp->next = new ListNode(top);
            temp = temp->next;
        }
        
        return dummyHead->next;
    }
};
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
         
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp)
            {
                pq.push({temp->val, temp});
                temp = temp->next;
            }
        }
        
        while(!pq.empty())
        {
            auto top = pq.top(); pq.pop();
            auto address = top.second;
            temp->next = address;
            temp = temp->next;
        }
        
        return dummyHead->next;
    }
};
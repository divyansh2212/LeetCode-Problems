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
    int pairSum(ListNode* head) {
        stack<int> S;
        int n = 0;
        ListNode* tmp = head;
        for(;tmp != NULL;tmp = tmp->next){
            n++;
        }

        int half = n/2-1,i = 0;
        int curMax = 0, globalMax = INT_MIN;
        ListNode* cur = head;

        for(; cur != NULL;cur = cur->next){
            if(i <= half){
                S.push(cur->val);
            }
            else{
                int topVal = S.top();
                S.pop();
                curMax = topVal + cur->val; 
            }
            globalMax = max(curMax,globalMax);
            i++;
        }
        return globalMax;
    }
};
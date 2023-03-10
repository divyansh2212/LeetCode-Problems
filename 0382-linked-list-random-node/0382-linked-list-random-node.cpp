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
    vector<int> hashing;
    
    int length(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    void traversal(ListNode* head, vector<int> &hashing)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            hashing[count] = temp->val;
            count++;
            temp = temp->next;
        }
    }
    
public:
    Solution(ListNode* head) {
        int len = length(head);
        hashing.resize(len);
        traversal(head, hashing);
    }
    
    int getRandom() {
        int n = hashing.size();
        int idx = rand() % n;
        return hashing[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
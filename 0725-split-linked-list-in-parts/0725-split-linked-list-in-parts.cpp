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
        if(head==NULL)
            return 0;
        int l = 0;
        ListNode* temp = head;
        while(temp) {
            l++;
            temp = temp->next;
        }
        return l;
    }
    
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l = length(head);
        if(l <= k) {
            ListNode* temp = head;
            vector<ListNode*> ans;
            while(temp) {
                ans.push_back(temp);
                temp = temp->next;
                ans.back()->next = NULL;
            }
            
            while(ans.size() < k) {
                ans.push_back(NULL);
            }
            
            return ans;
        }
        else {
            int count = l / k;
            int rem = l % k;
            
            ListNode* temp = head;
            vector<ListNode*> ans;
            while(temp) {
                ans.push_back(temp);
                cout << rem << " ";
                temp = temp->next;
                ListNode* dummytemp = ans.back();
                
                for(int i = 0; i < count - 1; i++) {
                    dummytemp->next = temp;
                    temp = temp->next;
                    dummytemp = dummytemp->next;
                }
                
                if(rem>0) {
                    dummytemp->next = temp;
                    if(temp)
                        temp = temp->next;
                    if(dummytemp)
                        dummytemp = dummytemp->next;
                    rem--;
                }
                if(dummytemp)
                    dummytemp->next = NULL;
            }
            
            return ans;
            
        }
        
        return {};
    }
};
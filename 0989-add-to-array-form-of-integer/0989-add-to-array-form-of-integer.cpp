class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        
        int carry = 0;
        
        vector<int> ans;
        
        int i = n - 1;
        
        while(i >= 0 && k > 0)
        {
            int curr = num[i] + (k % 10) + carry;
            if(curr > 9)
            {
                ans.push_back(curr % 10);
                curr /= 10;
                carry = curr;
            }
            else
            {
                carry = 0;
                ans.push_back(curr);
            }
            i--; k /= 10;
        }
        
        while(i >= 0)
        {
            int curr = num[i] + carry;
            if(curr > 9)
            {
                ans.push_back(curr % 10);
                curr /= 10;
                carry = curr;
            }
            else
            {
                carry = 0;
                ans.push_back(curr);
            }
            i--;
        }
        
        while(k > 0)
        {
            int curr = (k % 10) + carry;
            if(curr > 9)
            {
                ans.push_back(curr % 10);
                curr /= 10;
                carry = curr;
            }
            else
            {
                carry = 0;
                ans.push_back(curr);
            }
            k /= 10;
        }
        
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
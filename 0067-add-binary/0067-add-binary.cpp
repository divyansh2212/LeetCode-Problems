class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans = "";
        
        int carry = 0;
        
        int i = a.length() - 1, j = b.length() - 1;
        
        while(i >= 0 && j >= 0)
        {
            int curr = a[i] - '0' + b[j] - '0';
            curr += carry;
            if(curr == 2)
            {
                carry = 1;
                ans.push_back('0');    
            }
            else if(curr == 3)
            {
                carry = 1;
                ans.push_back('1');
            }
            else if(curr == 1)
            {
                carry = 0;
                ans.push_back('1');
            }
            else
            {
                carry = 0;
                ans.push_back('0');
            }
            i--, j--;
        }
        
        while(i >= 0)
        {
            int curr = a[i] - '0';
            curr += carry;
            if(curr == 2)
            {
                carry = 1;
                ans.push_back('0');    
            }
            else if(curr == 3)
            {
                carry = 1;
                ans.push_back('1');
            }
            else if(curr == 1)
            {
                carry = 0;
                ans.push_back('1');
            }
            else
            {
                carry = 0;
                ans.push_back('0');
            }
                
            i--;
        }
        
        while(j >= 0)
        {
            int curr = b[j] - '0';
            curr += carry;
            if(curr == 2)
            {
                carry = 1;
                ans.push_back('0');    
            }
            else if(curr == 3)
            {
                carry = 1;
                ans.push_back('1');
            }
            else if(curr == 1)
            {
                carry = 0;
                ans.push_back('1');
            }
            else
            {
                carry = 0;
                ans.push_back('0');
            }
            j--;
        }
        
        if(carry)
            ans.push_back('1');
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
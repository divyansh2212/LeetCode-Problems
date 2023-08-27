
class Solution {
    
    bool static comparator(string &a, string &b) {
        return a+b > b+a;
    }
    
public:
    string largestNumber(vector<int>& nums) {
                
        int n = nums.size();
        
        vector<string> temp;
        for(int x : nums) {
            temp.push_back(to_string(x));
        }
        sort(temp.begin(), temp.end(), comparator);
        
        string ans = "";
        for(string x : temp) {
            ans += x;
        }
        
        int zeros = 0;
        for(char &x : ans) {
            if(x == '0') zeros++;
            else break;
        }
        
        if(zeros == ans.length())
            return "0";
        
        return ans;
    }
};
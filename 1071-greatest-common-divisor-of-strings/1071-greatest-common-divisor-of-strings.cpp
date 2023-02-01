class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n = str1.length(), m = str2.length();
        string ans = "";
        
        string curr = "";
        
        for(int i = 0; i < str1.length(); i++)
        {
            curr.push_back(str1[i]);
            
            string curr1 = curr, curr2 = curr;
            
            while(curr1.length() < str1.length())
                curr1 = curr1 + curr;
            
            while(curr2.length() < str2.length())
                curr2 = curr2 + curr;
            
            if(curr1 == str1 && curr2 == str2)
                ans = curr;
        }
        
        return ans;
    }
};
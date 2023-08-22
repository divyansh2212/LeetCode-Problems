class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        while(columnNumber > 0)
        {
            int rem = columnNumber % 26;
            if(rem == 0)
                rem = 26;
            ans.push_back(char('A' + rem - 1));
            columnNumber = columnNumber / 26;
            if(rem == 26)
                columnNumber--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
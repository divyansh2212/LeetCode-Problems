class Solution {
public:
    string convert(string s, int numRows) 
    {
        int n = s.length();
        int i = 0, j = 0;
        int idx = 0;
        
        vector<vector<char>> temp(numRows, vector<char> (1000, '#'));
        
        while(idx < n)
        {
            // if(i == 0)
            // {
                while(i < numRows && idx < n)
                {
                    temp[i][j] = s[idx];
                    i++, idx++;
                }
                if(idx == n)
                    break;
            // }
            i--, j++;
            
            if(numRows > 1)
                i--;
            
            while(i > 0 && idx < n)
            {
                temp[i][j] = s[idx];
                i--, j++, idx++;
            }
            
        }
        
        string ans = "";
        
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < 1000; j++)
            {
                if(temp[i][j] == '#')
                    continue;
                ans.push_back(temp[i][j]);
            }
        }
        
        return ans;
    }
};



// P A Y P A L I S H I R I N G

// P I N
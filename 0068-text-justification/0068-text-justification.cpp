class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxi) {
        vector<string> ans;
        int n = words.size();
        
        vector<vector<string>> temp;
        int currLen = 0;
        
        for(int i = 0; i < n; i++) {
            int m = words[i].length();
            if(currLen == 0 || currLen + 1 + m <= maxi) {
                if(currLen == 0)
                    currLen--;
                currLen += 1 + m;
                if(temp.size() == 0) {
                    temp.push_back({words[i]});
                }
                else {
                    temp.back().push_back(words[i]);
                }
            }
            else {
                temp.push_back({words[i]});
                currLen = m;
            }
        }
        
        for(int i = 0; i < temp.size(); i++) {
            int no_of_words = temp[i].size();
            int currLen = 0;
            for(int j = 0; j < no_of_words; j++) {
                currLen += temp[i][j].length();
            }
            int reqd_spaces = maxi - currLen;
            int space_in_between = 0;
            if(no_of_words > 1)
                space_in_between = reqd_spaces / (no_of_words - 1);
           
            int leftSpaces = reqd_spaces - ((no_of_words - 1) * space_in_between);
            
            string curr = "";
            for(int j = 0; j < no_of_words; j++) 
            {
                curr += temp[i][j];
                if(i < temp.size() - 1)
                {
                    for(int k = 0; k < space_in_between && j < no_of_words - 1; k++)  {
                        curr.push_back(' ');
                    }
                }
                else {
                    if(j < no_of_words - 1)
                    {
                        curr.push_back(' ');
                    
                        leftSpaces += space_in_between - 1;
                    }
                }
                if(leftSpaces > 0 && i < temp.size() - 1)
                {
                    curr.push_back(' ');
                    leftSpaces--;
                }
            }
            while(leftSpaces > 0) {
                curr.push_back(' '); leftSpaces--;
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int length = 0;
        
        int i = 0;
        vector<int> newChars;
        while(i < n)
        {
            char curr = chars[i];
            newChars.push_back(curr);
            i++, length++;
            int freq = 1;
            while(i < n && chars[i] == curr)
                i++, freq++;
            if(freq > 1)
            {
                string freq_s = to_string(freq);
                for(int j = 0; j < freq_s.length(); j++)
                    newChars.push_back(freq_s[j]);
                length += freq_s.length();
            }
        }
        while(chars.size())
            chars.pop_back();
        chars.resize(newChars.size());
        // chars = newChars;
        for(int i = 0; i < newChars.size(); i++)
            chars[i] = newChars[i];
        return length;
    }
};
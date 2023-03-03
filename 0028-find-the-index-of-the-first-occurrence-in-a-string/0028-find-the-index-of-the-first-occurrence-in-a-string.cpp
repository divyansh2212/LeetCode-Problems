class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m > n)
            return -1;
        
        for(int i = 0; i < n; i++)
        {
            if(i + m - 1 >= n)
                break;
            if(haystack[i] == needle[0])
            {
                int k = i, j = 0;
                for(j = 0; j < m; j++, k++)
                    if(haystack[k] != needle[j])
                        break;
                if(j == m)
                    return i;
            }
        }
        return -1;
    }
};
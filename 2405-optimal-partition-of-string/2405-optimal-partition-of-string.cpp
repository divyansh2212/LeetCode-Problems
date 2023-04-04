class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        
        vector<int> hashTable(26, 0);
        
        int partitions = 1;
        
        for(int i = 0; i < n; i++)
        {
            if(hashTable[s[i] - 'a'] > 0)
            {
                partitions++;
                for(int j = 0; j < 26; j++)
                    hashTable[j] = 0;
            }
            
            hashTable[s[i] - 'a']++;
        }
        
        return partitions;
    }
};
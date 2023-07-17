class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> hashTable(n + 1, 0);
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            hashTable[arr[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(hashTable[arr[i]] == 2) {
                ans.push_back(arr[i]);
                hashTable[arr[i]] = -1;
            }
        }
        
        return ans;
    }
};
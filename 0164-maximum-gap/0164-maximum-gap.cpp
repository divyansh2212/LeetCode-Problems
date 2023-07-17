class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        map<int, int> hashTable;
        for(int i = 0; i < n; i++) {
            hashTable[nums[i]] = 1;
        }
        
        int ans = 0;
        int last = -1;
        for(auto &it : hashTable) {
            if(last == -1) {
                last = it.first;
            }
            else {
                ans = max(ans, it.first - last);
                last = it.first;
            }
        }
        
        return ans;
    }
};
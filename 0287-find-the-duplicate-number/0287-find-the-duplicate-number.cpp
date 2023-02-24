class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashTable(n, 0);
        for(int i = 0; i < n; i++)
        {
            hashTable[nums[i]]++;
            if(hashTable[nums[i]] == 2)
                return nums[i];
        }
        return -1;
    }
};
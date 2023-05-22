class Solution {
    
    bool static comparator (pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> frequencyTable;
        vector<pair<int, int>> numFreqPair;
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            frequencyTable[nums[i]]++;
        }
        
        for(auto &it : frequencyTable) {
            numFreqPair.push_back({it.second, it.first});
        }
        
        sort(numFreqPair.begin(), numFreqPair.end(), comparator);
        
        for(auto &it : numFreqPair) {
            if(ans.size() == k)
                break;
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
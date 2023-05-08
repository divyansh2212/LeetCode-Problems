class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int, int>> people;
        int n = groupSizes.size();
        
        for(int i = 0; i < n; i++)
            people.push_back({groupSizes[i], i});
        
        sort(people.begin(), people.end());
        
        vector<vector<int>> ans;
        
        int i = 0;
        while(i < n)
        {
            int size = people[i].first;
            vector<int> curr;
            while(size--)
            {
                curr.push_back(people[i].second);
                i++;
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int sum = 0;
        int initial = 0;
        int idx = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];
            if(initial + gas[i] >= cost[i])
            {
                initial = initial + gas[i] - cost[i];
            }
            else
            {
                idx = i + 1;
                initial = 0;
            }
        }
        
        if(sum < 0)
            return -1;
        
        return idx;
    }
};
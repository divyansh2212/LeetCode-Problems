class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
    
        sort(tasks.begin(), tasks.end());
        int curr = 1, ans = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(tasks[i] == tasks[i - 1])
                curr++;
            else
            {
                if(curr == 1)
                    return -1;
                else
                {
                    ans += ceil((curr * 1.0) / 3);
                    curr = 1;
                }
            }
        }
        
        if(curr == 1)
            return -1;
        else
            ans += ceil((curr * 1.0) / 3);
        
        return ans;
    }
};
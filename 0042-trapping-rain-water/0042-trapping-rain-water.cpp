class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        // 0 1 0 2 1 0 1 3 2 1 2 1
        // 0 0 1 1 2 2 2 2 3 3 3 3
        // 3 3 3 3 3 3 3 2 2 2 1 0
        
        vector<int> forward(n, 0);
        vector<int> backward(n, 0);
        
        forward[0] = 0;
        backward[n - 1] = 0;
        
        for(int i = 1; i < n; i++) {
            forward[i] = max(forward[i - 1], height[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            backward[i] = max(backward[i + 1], height[i + 1]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int curr = min(forward[i], backward[i]);
            curr -= height[i];
            if(curr > 0)
                ans += curr;
        }
        
        return ans;
    }
};
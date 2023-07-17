class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int prefix = 0;
        int suffix = 0;
        
        for(int i = 0; i < k; i++) {
            prefix += cardPoints[i];
        }
        
        int ans = prefix;
        int i = k - 1, j = n;
        
        while(i >= 0)
        {
            prefix -= cardPoints[i];
            i--, j--;
            suffix += cardPoints[j];
            ans = max(ans, suffix + prefix);
        }
     
        return ans;
    }
};
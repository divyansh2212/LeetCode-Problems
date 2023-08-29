class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.length();
        
        vector<int> yprefix(n, 0);
        yprefix[n - 1] = (customers[n - 1] == 'Y') ? 1 : 0;
        for(int i = n - 2; i >= 0; i--) {
            yprefix[i] += yprefix[i + 1];
            yprefix[i] += (customers[i] == 'Y') ? 1 : 0;
        }
        
        vector<int> nprefix(n + 1, 0);
        nprefix[0] = (customers[0] == 'N') ? 1 : 0;
        for(int i = 1; i < n; i++) {
            nprefix[i] += nprefix[i - 1];
            nprefix[i] += (customers[i] == 'N') ? 1 : 0;
        }
        nprefix[n] += nprefix[n - 1];
        
        int mini = n + 1;
        int curr;
        unordered_map<int,int> counts;
        for(int i = 0; i < n; i++) {
            curr = yprefix[i];
            if(i > 0) {
                curr += nprefix[i - 1];
            }
            mini = min(mini, curr);
            if(counts.find(curr) == counts.end())
            counts[curr] = i;
        }
        curr = nprefix[n];
        mini = min(mini, curr);
        if(counts.find(curr) == counts.end())
        counts[curr]= n;
        return counts[mini];
    }
};
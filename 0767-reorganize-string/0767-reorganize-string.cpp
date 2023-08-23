class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        
        for(char x : s) mp[x]++;
        priority_queue<pair<int, char>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        while(pq.size() > 1) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            ans.push_back(top1.second);
            ans.push_back(top2.second);
            
            top1.first--;
            top2.first--;
            
            if(top1.first) {
                pq.push(top1);
            }
            if(top2.first) {
                pq.push(top2);
            }
        }
        
        if(pq.size()) {
            auto top = pq.top(); pq.pop();
            if(top.first > 1) return "";
            ans.push_back(top.second);
        }
        
        return ans;
    }
};
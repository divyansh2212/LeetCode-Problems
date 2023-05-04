class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        
        vector<bool> banned(n, false);
        int bans = 0;
        
        for(int i = 0; ; i++)
        {
            i = i % n;
            if(banned[i])
                continue;
            int initialbans = bans;
            
            for(int j = i + 1; ; j++) {
                j = j%n;
                if(j == i)
                    break;
                if(banned[j] == false && senate[i] != senate[j]){
                    banned[j] = true;
                    bans++;
                    break;
                }
            }
            
            if(bans == initialbans)
                break;
            
        }
        
        int d = 0, r = 0;
        
        for(int i = 0; i < n; i++){
            if(banned[i] == false){
                if(senate[i] == 'D')
                    d++;
                else
                    r++;
            }
        }
        
        if(d > r)
            return "Dire";
        
        return "Radiant";
    }
};
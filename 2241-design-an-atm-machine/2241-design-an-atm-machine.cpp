class ATM {
    vector<long long> notes;
    const int mod = 1e9 + 7;
public:
    ATM() {
        notes.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < banknotesCount.size(); i++)
            notes[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        // ans.clear();
        vector<long long> initial = notes;
        vector<int> ans(5, 0);
        if(notes[4] > 0 && amount > 0)
        {
            long long freq = amount / 500;
            freq = min(notes[4], freq);
            amount -= (freq * 500);
            notes[4] -= freq;
            if(amount >= 500 && notes[4] > 0)
            {
                notes = initial;
                return {-1};
            }
            ans[4] = freq % mod;
        }
        if(notes[3] > 0 && amount > 0)
        {
            long long freq = amount / 200;
            freq = min(notes[3], freq);
            amount -= (freq * 200);
            notes[3] -= freq;
            if(amount >= 200 && notes[3] > 0)
            {
                notes = initial;
                return {-1};
            }
            ans[3] = freq % mod;
        }
        if(notes[2] > 0 && amount > 0)
        {
            long long freq = amount / 100;
            freq = min(notes[2], freq);
            amount -= (freq * 100);
            notes[2] -= freq;
            if(amount >= 100 && notes[2] > 0)
            {
                notes = initial;
                return {-1};
            }
            ans[2] = freq % mod;
        }
        if(notes[1] > 0 && amount > 0)
        {
            long long freq = amount / 50;
            freq = min(notes[1], freq);
            amount -= (freq * 50);
            notes[1] -= freq;
            if(amount >= 50 && notes[1] > 0)
            {
                notes = initial;
                return {-1};
            }
            ans[1] = freq % mod;
        }
        if(notes[0] > 0 && amount > 0)
        {
            long long freq = amount / 20;
            freq = min(notes[0], freq);
            amount -= (freq * 20);
            notes[0] -= freq;
            if(amount >= 20 && notes[0] > 0)
            {
                notes = initial;
                return {-1};
            }
            ans[0] = freq % mod;
        }
        if(amount > 0)
        {
            notes = initial;
                return {-1};
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
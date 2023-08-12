class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());
        
        unordered_multiset<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(hand[i]);
        }
        
        for(int i = 0; i < n; i++) 
        {
            if(st.find(hand[i]) != st.end())
            {
                for(int j = hand[i]; j < hand[i] + groupSize; j++)
                {
                    if(st.find(j) != st.end()) {
                        auto it = st.find(j);
                        st.erase(it);
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        
        return st.size() == 0;
    }
};
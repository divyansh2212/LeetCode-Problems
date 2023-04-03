class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        
        sort(people.begin(), people.end());
        
//         int i = 0, j = 0;
//         int boats = 0;
        
//         while(i < n)
//         {
//             if(i == j)
//                 j++;
//             while(j < n && people[j] + people[i] <= limit)
//             {
//                 j++;
//             }
            
            
            
//             i = j;
//             boats++;
//         }
        
        multiset<int> st(people.begin(), people.end());
        int boats = 0;
        
        while(st.size())
        {
            auto it1 = st.begin();
            int val1 = *it1;
            st.erase(it1);
            int reqd = limit - val1;
            
            if(st.size())
            {
                auto it2 = st.upper_bound(reqd);
                if(it2 != st.begin())
                it2--;
                int val2 = *it2;
                if(val2 <= reqd)
                    st.erase(it2);
            }
            
            boats++;
        }
        
        return boats;
        
    }
};
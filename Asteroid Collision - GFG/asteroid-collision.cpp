//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            if(st.size() == 0)
                st.push(asteroids[i]);
            else if(asteroids[i] < 0 && st.top() > 0)
            {
                bool flag = true;
                while(st.size() && st.top() > 0)
                {
                    int top = st.top();
                    if(top > abs(asteroids[i]))
                    {
                        flag = false;
                        break;
                    }
                    else if(top == abs(asteroids[i]))
                    {
                        st.pop();
                        flag = false;
                        break;
                    }
                    else
                        st.pop();
                }
                if(flag)
                    st.push(asteroids[i]);
            }
            else if(asteroids[i] > 0 && st.top() < 0)
            {
                // bool flag = true;
                // while(st.size() && st.top() < 0)
                // {
                //     int top = st.top();
                //     if(abs(top) > abs(asteroids[i]))
                //     {
                //         flag = false;
                //         break;
                //     }
                //     else if(abs(top) == abs(asteroids[i]))
                //     {
                //         st.pop();
                //         flag = false;
                //         break;
                //     }
                //     else
                //         st.pop();
                // }
                // if(flag)
                    st.push(asteroids[i]);
            }
            else
                st.push(asteroids[i]);
        }
        
        vector<int> ans;
        
        while(st.size())
        {
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    vector<int> dx = {2, 2, -2, -2, -1, -1, 1, 1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    int solve(int x, int y, int tx, int ty, int &n)
    {
        vector<vector<bool>> visited(n + 1, vector<bool> (n + 1, false));
        queue<vector<int>> q;
        q.push({x, y});
        visited[x][y] = true;
        int steps = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int s = 0; s < size; s++)
            {
                auto front = q.front(); q.pop();
                int currx = front[0], curry = front[1];
                
                if(currx == tx && curry == ty)
                    return steps;
                
                for(int i = 0; i < 8; i++)
                {
                    int currxx = currx + dx[i], curryy = curry + dy[i];
                    if(currxx >= 1 && curryy >= 1 && currxx <= n && curryy <= n && !visited[currxx][curryy])
                    {
                        visited[currxx][curryy] = true;
                        q.push({currxx, curryy});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
	{
	    return solve(knightPos[0], knightPos[1], targetPos[0], targetPos[1], n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
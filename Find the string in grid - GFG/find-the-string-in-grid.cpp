//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool hleft(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(j >= 0 && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            j--; k++;
        }
        return k == word.length();
    }
    
    bool vup(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(i >= 0 && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            i--; k++;
        }
        return k == word.length();
    }
    
    bool hright(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(j < grid[0].size() && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            j++; k++;
        }
        return k == word.length();
    }
    
    bool vdown(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(i < grid.size() && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            i++; k++;
        }
        return k == word.length();
    }
    
    bool downright(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(i < grid.size() && j < grid[0].size() && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            i++; k++; j++;
        }
        return k == word.length();
    }
    
    bool upright(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(i >= 0 && j < grid[0].size() && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            i--; k++; j++;
        }
        return k == word.length();
    }
    
     
    bool upleft(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(i >= 0 && j >= 0 && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            i--; k++; j--;
        }
        return k == word.length();
    }
    
    bool downleft(vector<vector<char>>&grid, int i, int j, string &word) {
        int k = 0;
        while(i < grid.size() && j >= 0 && k < word.length()) {
            if(word[k] != grid[i][j])
                return false;
            i++; k++; j--;
        }
        return k == word.length();
    }
    
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    int len = word.length();
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(hleft(grid, i, j, word) || hright(grid, i, j, word) || vup(grid, i, j, word)
	            || vdown(grid, i, j, word) || downright(grid, i, j, word) || downleft(grid, i, j, word)
	            || upright(grid, i, j, word) || upleft(grid, i, j, word)
	            ) {
	               // cout << i << " " << j << endl;
	                ans.push_back({i, j});
	            }
	        }
	    }
	    
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
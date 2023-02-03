//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        
        int n = matrix.size(), m = matrix[0].size();
        
        // right = 0, down = 1, up = 2, left = 3; 
        
        int i = 0, j = 0, direction = 0;
        
        while(1)
        {
            int or1 = i, or2 = j;
            if(matrix[i][j] == 0)
            {
                if(direction == 0)
                    j++;
                else if(direction == 1)
                    i++;
                else if(direction == 2)
                    i--;
                else if(direction == 3)
                    j--;
                if(i < 0 || j < 0 || i == n || j == m)
                    return make_pair(or1, or2);
            }
            
            else
            {
                matrix[i][j] = 0;
                if(direction == 0)
                    direction = 1;
                else if(direction == 1)
                    direction = 3;
                else if(direction == 2)
                    direction = 0;
                else if(direction == 3)
                    direction = 2;
                    
                if(direction == 0)
                    j++;
                else if(direction == 1)
                    i++;
                else if(direction == 2)
                    i--;
                else if(direction == 3)
                    j--;
                if(i < 0 || j < 0 || i == n || j == m)
                    return make_pair(or1, or2);  
            }
        }
        
        return {0, 0};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
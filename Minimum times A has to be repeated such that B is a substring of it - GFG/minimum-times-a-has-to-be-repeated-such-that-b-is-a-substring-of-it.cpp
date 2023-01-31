//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        string to_add = a;
        
        int counter = 1;
        
        while(a.length() < b.length()){
            
            a = a + to_add;
            counter++;
            
            
        }
        
        for(int i = 0; i < a.length(); i++)
        {
            if(a.length() - i < b.length())
                break;
                
            string sub = a.substr(i, b.length());
            if(sub == b)
                return counter;
        }
        
        a = a + to_add;
        counter++;
        for(int i = 0; i < a.length(); i++)
        {
            if(a.length() - i < b.length())
                break;
                
            string sub = a.substr(i, b.length());
            if(sub == b)
                return counter;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends
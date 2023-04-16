//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int n, vector<int> &arr, vector<int> &brr) {
        // code here
        long long sum1 = 0, sum2 = 0, odds1 = 0, odds2 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 += arr[i];
            if(arr[i] % 2)
                odds1++;
        }
            
        for(int i = 0; i < n; i++)
        {
            sum2 += brr[i];
            if(brr[i] % 2)
                odds2++;
        }
        
        if(sum1 != sum2 || odds1 != odds2)
            return -1;
        
        vector<int> evenA, evenB, oddA, oddB;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] % 2)
                oddA.push_back(arr[i]);
            else
                evenA.push_back(arr[i]);
            if(brr[i] % 2)
                oddB.push_back(brr[i]);
            else
                evenB.push_back(brr[i]);
        }
        
        sort(oddA.begin(), oddA.end());
        sort(oddB.begin(), oddB.end());
        sort(evenA.begin(), evenA.end());
        sort(evenB.begin(), evenB.end());
        
        long long ans = 0;
        
        for(int i = 0; i < oddA.size(); i++)
        {
            ans += abs(oddA[i] - oddB[i]) / 2;
        }
        for(int i = 0; i < evenA.size(); i++)
        {
            ans += abs(evenA[i] - evenB[i]) / 2;
        }
        
        return ans/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
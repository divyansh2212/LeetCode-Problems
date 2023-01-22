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
    int solve(int n, int k, vector<int> &arr) {
        // code here
        
        // vector<bool> is_prime(100001, true);
        // is_prime[0] = false, is_prime[1] = false;
        // vector<int> primes;
        
        // for(int i = 2; i <= 1e5; i++)
        // {
        //     if(is_prime[i])
        //     {
        //         primes.push_back(i);
        //         for(int j = 2 * i; j <= 1e5; j += i)
        //             is_prime[j] = false;
        //     }
        // }
        
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
            
        if(k == 1)
            return sum;
            
        vector<int> factors;
        for(long i = 1; i * i <= sum; i++)
        {
            if(sum % i == 0)
            {
                factors.push_back(i);
                if(i != (sum / i))
                    factors.push_back(sum / i);
            }
        }
        
        int ans = 1;    
        
        for(int i = 0; i < factors.size(); i++)
        {
            int number = factors[i];
            
            int currk = k, currSum = 0;
            
            for(int idx = 0; idx < n; idx++)
            {
                if(currk == 1)
                {
                    while(idx < n)
                    {
                        currSum += arr[idx];
                        idx++;
                    }
                    
                    if(currSum % number == 0)
                        ans = max(ans, number);
                    break;
                }
                currSum += arr[idx];
                if(currSum % number == 0)
                    currk--;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
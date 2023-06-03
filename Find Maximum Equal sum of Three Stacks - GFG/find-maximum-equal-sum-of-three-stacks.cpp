//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    int calcSum(vector<int> &arr, int &n)
    {
        int sum = 0;
        for(auto &it : arr)
            sum += it;
        return sum;
    }
    
public:
    int maxEqualSum(int n1, int n2, int n3, vector<int> &s1, vector<int> &s2, vector<int> &s3)
    {
        int sum1 = calcSum(s1, n1);
        int sum2 = calcSum(s2, n2);
        int sum3 = calcSum(s3, n3);
        
        int i = 0, j = 0, k = 0;
        
        while(1)
        {
            if(sum1 == sum2 && sum2 == sum3)
                break;
            
            if(sum1 >= sum2 && sum1 >= sum3)
            {
                sum1 -= s1[i];
                i++;
            }
            else if(sum2 >= sum1 && sum2 >= sum3)
            {
                sum2 -= s2[j];
                j++;
            }
            else if(sum3 >= sum2 && sum3 >= sum1)
            {
                sum3 -= s3[k];
                k++;
            }
        }
        
        return sum1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
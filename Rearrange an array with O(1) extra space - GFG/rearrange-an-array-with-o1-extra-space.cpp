//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        
        // for(int i = 0; i < n; i++)
        // {
        //     if(arr[i] == i) continue;
            
        //     int temp = arr[i];
        //     for(int j = i + 1; j < n; j++)
        //     {
        //         if(arr[j] == i)
        //         {
        //             arr[j] = temp;
        //             break;
        //         }
        //     }
        //     swap(arr[i], arr[arr[i]]);
        // }
        
        long long newArr[n];
        for(int i = 0; i < n; i++)
            newArr[i] = arr[i];
            
        for(int i = 0; i < n; i++)
            arr[i] = newArr[newArr[i]];
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
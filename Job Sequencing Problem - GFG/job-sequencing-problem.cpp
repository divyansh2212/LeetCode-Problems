//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    
    bool static comparator(Job &a, Job &b)
    {
        if(a.profit == b.profit)
        {
            return a.dead < b.dead;
        }
        return a.profit > b.profit;
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> slot(n + 1, 0);
        
        sort(arr, arr + n, comparator);
        
        int tasks = 0, sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(slot[arr[i].dead] == false)
            {
                sum += arr[i].profit;
                tasks++;
                slot[arr[i].dead] = true;
            }
            else
            {
                for(int j = arr[i].dead - 1; j >= 1; j--)
                {
                    if(slot[j] == false)
                    {
                        sum += arr[i].profit;
                        tasks++;
                        slot[j] = true;
                        break;
                    }
                }
            }
        }
        
        return {tasks, sum};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
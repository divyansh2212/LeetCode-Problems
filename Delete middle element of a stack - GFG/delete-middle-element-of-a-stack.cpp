//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&st, int n)
    {
        int middle = n / 2;
            middle++;
        int count = 1;
        vector<int> popped;
        for(int i = 1; i <= n; i++)
        {
            int top = st.top();
            st.pop();
            if(count == middle) {
                break;
            }
            popped.push_back(top);
            count++;
        }
        
        for(int i = popped.size() - 1; i >= 0; i--) {
            st.push(popped[i]);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
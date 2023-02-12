//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
    const int N = 10030;
    vector<bool> is_prime;
    
    void primeCalculator()
    {
        is_prime.resize(N);
        for(int i = 0; i < N; i++)
            is_prime[i] = true;
        is_prime[0] = false, is_prime[1] = false;
        for(int i = 2; i < 10030; i++)
            if(is_prime[i])
                for(int j = 2 * i; j < 10030; j += i)
                    is_prime[j] = false;
    }
    
public:
    Node *primeList(Node *head)
    {
        primeCalculator();
        
        Node *temp = head;
        
        while(temp)
        {
            if(is_prime[temp->val] == false)
            {
                int j1 = -1, j2 = -1;
                for(int i = temp->val - 1; i >= 2; i--)
                {
                    if(is_prime[i])
                    {
                        j1 = i;
                        break;
                    }
                }
                
                for(int i = temp->val + 1; i < 10030; i++)
                {
                    if(is_prime[i])
                    {
                        j2 = i;
                        break;
                    }
                }
                
                if(j1 == -1)
                    temp->val = j2;
                else if(abs(temp->val - j1) <= abs(temp->val - j2))
                    temp->val = j1;
                else
                    temp->val = j2;
            }
            temp = temp->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
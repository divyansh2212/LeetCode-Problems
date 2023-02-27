//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
Node* reverseList(Node* head) 
{
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
    
public:
    Node *reverse(Node *head, int k)
    {
        int point = 0;
        Node *temp = head;
        Node *firstTail, *firstHead;
        
        while(temp)
        {
            point++;
            if(point == k)
                firstTail = temp;
            else if(point == k + 1)
                firstHead = temp;
            temp = temp->next;
        }
        firstTail->next = NULL;
        
        Node *firstList = reverseList(head);
        Node *secondList = reverseList(firstHead);
        
        temp = firstList;
        
        while(temp->next)   temp = temp->next;
        temp->next = secondList;
        
        // firstList->next = secondList;   
        
        return firstList;
    }
    
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
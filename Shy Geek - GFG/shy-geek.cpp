//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        
        long long ans = 0;
        int lo = 0, hi = n - 1, lastPoint = -1;
        
        while(1)
        {
            long long price = -1;
            long long pointPrice = -1;
            while(lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                price = shop.get(mid);
                if(price > k)
                    hi = mid - 1;
                else
                    pointPrice = price, lastPoint = mid, lo = mid + 1;
            }
            
            if(lastPoint == -1)
                break;
            // long long price = shop.get(lastPoint);
            long long to_add = (k / pointPrice);
            k -= (to_add * pointPrice);
            ans += to_add;
            hi = lastPoint - 1, lo = 0;
            lastPoint = -1, pointPrice = -1;
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
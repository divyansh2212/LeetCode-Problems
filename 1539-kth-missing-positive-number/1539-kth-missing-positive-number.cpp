class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> hashing(2001, 0);
        for(int i = 0; i < arr.size(); i++)
            hashing[arr[i]] = true;
        
        int counter = 0;
        for(int i = 1; i <= 2000; i++)
        {
            if(hashing[i] == false)
            {
                counter++;
                if(counter == k)
                    return i;
            }
        }
        return -1;
    }
};
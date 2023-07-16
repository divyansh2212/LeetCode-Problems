class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        if(sum % 3)
            return false;
        
        int singleset = sum / 3;
        int idx = -1;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum == singleset) {
                idx = i;
                break;
            }
        }
        
        if(sum != singleset || idx == n - 1) {
            return false;
        }
        
        sum = 0;
        for(int i = idx + 1; i < n; i++) {
            sum += arr[i];
            if(sum == singleset) {
                idx = i;
                break;
            }
        }
        
        if(sum != singleset || idx == n - 1) {
            return false;
        }
        
        sum = 0;
        for(int i = idx + 1; i < n; i++) {
            sum += arr[i];
        }
        
        if(sum != singleset) {
            return false;
        }
        
        return true;
    }
};
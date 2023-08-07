class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            int lo = 0, hi = m - 1, mid;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                if (matrix[i][mid] == target)
                    return true;
                if (matrix[i][mid] > target)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }

        return false;
    }
};
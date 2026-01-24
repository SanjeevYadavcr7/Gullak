class Solution {
public:

    int getPossibleRowIdx(vector<vector<int>>& matrix, int target) {
        int beg = 0, end = matrix.size()-1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            int curr_val = matrix[mid][0];
            if(curr_val == target) return mid;
            else if(curr_val < target) beg = mid+1;
            else end = mid-1;
        }
        return end;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rowIdx = getPossibleRowIdx(matrix, target);
        int beg = 0, end = n-1;
        
        if(rowIdx < 0) rowIdx = 0;
        if(rowIdx == m) rowIdx = m-1;

        while(beg <= end) {
            int mid = (beg + end) / 2;
            int curr_val = matrix[rowIdx][mid];
            if(curr_val == target) return true;
            else if(curr_val < target) beg = mid+1;
            else end = mid-1;
        }
        return false;
    }
};

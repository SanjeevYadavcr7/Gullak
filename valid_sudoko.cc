class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row[9];
        unordered_map<char, int> col[9];
        unordered_map<char, int> box[9];

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;

                char ch = board[i][j];
                int box_idx = (i / 3) * 3 + j / 3;
                
                if(row[i][ch]++ > 0 || col[j][ch]++ > 0 || box[box_idx][ch]++ > 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

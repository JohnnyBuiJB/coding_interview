#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    auto n = board.size();
    
    unordered_map<char, bool> seen_row, seen_col;
    unordered_map< string, unordered_map<char,bool> > seen_boxes;
    
    for (size_t i = 0; i < n; i++) {
        seen_row.clear();
        seen_col.clear();
        
        if (i / 3 == 0) {
            seen_boxes.clear();
        }
        
        for (auto j = i; j < n; j++) {
            if (board[i][j] != '.') {
                // Check the row
                if (seen_row.count(board[i][j])) {
                    return false;
                } else {
                    seen_row[board[i][j]] = true;
                }

                // Check the boxes
                string key = to_string(i/3) + to_string(j/3);
                if (seen_boxes[key].count(board[i][j])) {
                    return false;
                } else {
                    seen_boxes[key][board[i][j]] = true;
                }
            }
            
            if (board[j][i] != '.') {
                // Check the column
                if (seen_col.count(board[j][i])) {
                    return false;
                } else {
                    seen_col[board[j][i]] = true;
                }

                // Check the boxes
                if (i != j) {
                    string key = to_string(j/3) + to_string(i/3);
                    if (seen_boxes[key].count(board[j][i])) {
                        return false;
                    } else {
                        seen_boxes[key][board[j][i]] = true;
                    }
                }
            }
        }
    }
    
    return true;
}

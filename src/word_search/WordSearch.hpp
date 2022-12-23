#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * \Intuition: use recursive backtracking to test paths starting from each cell. 
 *      
 *      There is a little trick to save some time and space for checking visited 
 *      nodes. Instead of using a hashmap, use the input itself to mark visited 
 *      nodes. Notice that the children nodes can inherit the visited map from 
 *      their parent. Note that the marked cell has to be restored before the 
 *      algorithm leaves a node.
 * 
 * \Time: O(m * n * 4^l), with mxn as the size of the board, and l = |word|
 * \Space: O(4^l), recursive calls
 * \Ref: Vy Bui
 */
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        // Trivial
        if (board.size() == 0) {
            return false;
        }

        m = board.size();
        n = board[0].size();
        mpWord = &word;
        WordLen = word.size();

        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (dfs(board, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    int m = 0;
    int n = 0;
    string *mpWord;
    int WordLen = 0;

    bool dfs(vector<vector<char> >& board, int iLetter, int iRow, int iCol) {
        // Trivial
        if (iLetter >= WordLen) {
            return true;
        }

        // Index out of range
        if (iRow >= m || iRow < 0 || iCol >= n || iCol < 0) {
            return false;
        }

        string &word = *mpWord;

        if (board[iRow][iCol] != word[iLetter]) {
            return false;
        } else {
            board[iRow][iCol] = '#';
            
            auto ret = 
                dfs(board, iLetter + 1, iRow, iCol - 1)     // left
                || dfs(board, iLetter + 1, iRow, iCol + 1)  // right
                || dfs(board, iLetter + 1, iRow - 1, iCol)  // top
                || dfs(board, iLetter + 1, iRow + 1, iCol); // bottom)

            board[iRow][iCol] = word[iLetter];

            return ret;
                
        }
    }
};

#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

struct location {
    size_t i_row;
    size_t i_col;

    location(int iRow, int iCol) : i_row(iRow), i_col(iCol) {};
};

/**
 * \Trick   DFS
 * 
 * \Time    O(mn), where m = number of rows and n = number of columns
 * \Space   O(mn), hash set for visited
 * \Ref     Bui V.
 */
int numIslands(vector<vector <char> >& grid) {
    // Trivial
    if (grid.size() == 0) {
        return 0;
    }
    
    unordered_set<int> visited; // key = row * n_row + col
    int n_islands = 0;
    size_t m = grid.size();
    size_t n = grid[0].size();

    for (size_t i = 0; i < m; i++) {
        auto row = grid[i];

        for (size_t j = 0; j < n; j++) {
            auto cell_loc = i*n + j;    // Roll out the matrix
            auto cell_val = grid[i][j];

            // Found new island
            if (cell_val == '1' && !visited.count(cell_loc)) {
                n_islands++;
                stack< location > new_island;
                new_island.push(location(i,j));

                // Explore the entire new island
                while (!new_island.empty()) {
                    auto new_space_loc = new_island.top();
                    new_island.pop();
                    auto i_new_space = 
                        new_space_loc.i_row*n + new_space_loc.i_col;
                    
                    if (!visited.count(i_new_space)) {
                        // Left
                        if (new_space_loc.i_col > 0) {
                            auto adj_left_r = new_space_loc.i_row;
                            auto adj_left_c = new_space_loc.i_col - 1;
                            auto adj_left = grid[adj_left_r][adj_left_c];
                            auto adj_left_loc = location (adj_left_r, adj_left_c);

                            // Not yet visited land
                            if (adj_left == '1') {
                                new_island.push(adj_left_loc);
                            }
                        }

                        // Right
                        if (new_space_loc.i_col < n - 1) {
                            auto adj_right_r = new_space_loc.i_row;
                            auto adj_right_c = new_space_loc.i_col + 1;
                            auto adj_right = grid[adj_right_r][adj_right_c];
                            auto adj_right_loc = location (adj_right_r, adj_right_c);

                            // Not yet visited land
                            if (adj_right == '1') {
                                new_island.push(adj_right_loc);
                            }
                        }

                        // Above
                        if (new_space_loc.i_row > 0) {
                            auto adj_above_r = new_space_loc.i_row - 1;
                            auto adj_above_c = new_space_loc.i_col;
                            auto adj_above = grid[adj_above_r][adj_above_c];
                            auto adj_above_loc = location (adj_above_r, adj_above_c);

                            // Not yet visited land
                            if (adj_above == '1') {
                                new_island.push(adj_above_loc);
                            }
                        }

                        // Below
                        if (new_space_loc.i_row < m - 1) {
                            auto adj_below_r = new_space_loc.i_row + 1;
                            auto adj_below_c = new_space_loc.i_col;
                            auto adj_below = grid[adj_below_r][adj_below_c];
                            auto adj_below_loc = location (adj_below_r, adj_below_c);

                            // Not yet visited land
                            if (adj_below == '1') {
                                new_island.push(adj_below_loc);
                             }
                        }

                        visited.insert(i_new_space);
                    }
                }
            }
        }
    }

    return n_islands;
}

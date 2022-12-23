#include <vector>

using namespace std;


/**
 * \Intuition: Use recursion to track explored combinations. It's basically 
 *      binary decision tree with the decision whether to include the next 
 *      candidate in the solution and also remove it from the candidate set.
 * 
 *      For example, candidates = [2,3,5], target = 8. The algorithm will first 
 *      ask if it should include "2" to the solution. The left node will be [2]
 *      with access to all candidates, and the right node will be [] with access 
 *      to only [3,5].
 * \Time: O(n^target)
 * \Space: O(target)
 * \Ref: Neetcode
 */
class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        mpCandidates = &candidates;
        mNumCandidates = candidates.size();
        vector<vector<int> > combs;
        mpCombs = &combs;

        // Trivial
        if (mNumCandidates == 0 ) {
            return combs;
        }

        vector<int> comb;
        dfs(0, comb, target);

        return combs;
    }

private:
    size_t mNumCandidates = 0;
    vector<int>* mpCandidates = nullptr;
    vector<vector<int> > *mpCombs = nullptr;

    void dfs(size_t i, vector<int>& comb, int target) {
        // Trivial
        if (target == 0) {
            mpCombs->push_back(comb);
            return;
        }
        
        // Trivial
        if (i >= mNumCandidates) {
            return;
        }

        // Early stop
        vector<int>& candidates = *mpCandidates;

        dfs(i + 1, comb, target);

        // Proceed with the search space shrunk
        if (candidates[i] <= target) {
            auto comb2 = comb;
            comb2.push_back(candidates[i]);
            dfs(i, comb2, target - candidates[i]);
        }
    }
};

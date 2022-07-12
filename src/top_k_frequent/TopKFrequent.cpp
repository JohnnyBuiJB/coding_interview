#include "TopKFrequent.hpp"

using namespace std;

struct item {
    int val;
    int count;
};

namespace solution
{
/**
 * \Time    O(kn)
 * \Space   O(n + k)
 * \Trick   Count nums' occurrences then linear search for the k most 
 *          frequent.
 */
namespace linear_min_update 
{
    vector<int> 
    mTopKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> ht;
        
        // Count the nums, O(n) space and time
        for (const auto& n : nums) {
            // Found
            if (ht.count(n)) {
                ht[n]++;
            } 
            // New
            else {
                ht[n] = 1;
            }
        }
        
        // Pick the most frequent, O(k) space
        vector< item > top_k(k, item({0,0}));
        
        bool is_first = true;
        item *p_min = &top_k[0];
        
        // O(nk) time
        for (const auto& x : ht) {
            if (is_first) {
                p_min->val = x.first;
                p_min->count = x.second;
                is_first = false;
            } 
            // Add new top frequent num 
            else if (x.second > p_min->count) {
                p_min->val = x.first;
                p_min->count = x.second;
            }

            // Update min (here the k comes from)
            for (auto& y : top_k) {
                if (y.count < p_min->count) {
                    p_min = &y;
                }
            }
        }

        // Extract output
        vector<int> out;
        for (const auto& x : top_k) {
            out.push_back(x.val);
        }
        
        return out;
    }
}

/**
 * \Time    O(n)
 * \Space   O(n)
 * \Trick   Count num's occurrences and store them in a hash table, but use 
 *          the counts as keys instead of values. As a result, we only need to 
 *          linear search through the hashmap for the k-biggest bucket (with 
 *          largest counts).
 * \Ref     Neetcode, https://www.youtube.com/watch?v=YPTqKIgVk-k
 */
inline namespace bucket_sort 
{
    vector<int> 
    mTopKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> val_ht;

        // Count the nums, O(n) space and time
        for (const auto& n : nums) {
            // Found
            if (val_ht.count(n)) {
                val_ht[n]++;
            } 
            // New
            else {
                val_ht[n] = 1;
            }
        }

        // Convert to the count-as-key hash table, O(n) space and time
        unordered_map< int,vector<int> > cnt_ht;

        for (const auto& x : val_ht) {
            if (cnt_ht.count(x.second)) {
                cnt_ht[x.second].push_back(x.first);
            } 
            // New count
            else {
                cnt_ht[x.second] = vector<int>({x.first});
            }
        }

        // Search for the k-biggest bucket, O(k) space
        vector<int> top_k;

        // O(n) time
        for (int i = nums.size(); i > 0; i--) {
            // Found enough
            if (!k) {
                break;
            }
            
            if (cnt_ht.count(i)) {
                auto i_bucket = cnt_ht.bucket(i);
                
                for (const auto& x : cnt_ht[i_bucket]) {
                    // The answer is guaranteed to be unique
                    // -> There wouldn't be more than k values with the same 
                    // count
                    top_k.push_back(x);
                    k--;
                }
            }
        }

        return top_k;
    }
}

vector<int> 
topKFrequent(vector<int>& nums, int k) 
{
    return mTopKFrequent(nums, k);
}
}

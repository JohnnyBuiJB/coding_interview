#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * \Trick   We keep track of a list of candidates and find their left and right 
 *          limits along the way.
 *          
 *          Observation 1: a bar can only extend forward if the next bar is 
 *          higher or at the same high. If a bar cannot extend forward, it 
 *          reaches its right limit. We need to store its left limit at the 
 *          first time we see it. With the left and right limits, we can compute 
 *          the area and find the max one.
 * 
 *          Observation 2: when a bar is lower than the previous bar
 *          (unnecessarily next to it), we can extend the next bar backward, 
 *          which means that we can extend its left limit.
 * \Time    O(n), each element is pushed into the stack only once, and there is 
 *          only one pass through the array with constant operations inside the 
 *          loop.
 * \Space   O(n), for the stack
 * \Ref     Neetcode
 */
int largestRectangleArea(vector<int>& heights) {
    struct Rec {
        int iLeftLim;   // Index of the left limit
        int h;          // Height

        Rec(int index, int height) : iLeftLim(index), h(height) {};
    };

    stack<Rec> recs;

    int i = 0;
    int max_area = 0;
    for (auto const &h : heights) {
        // Any previous recs can extend?
        if (recs.empty()) {
            recs.push(Rec(i, h));
        } else {
            // Check if the new bar sets the limit for previous bars
            int i_left_lim_new_rec = i;
            
            do {
                auto prev_rec = recs.top();

                if (prev_rec.h > h) {
                    // Extend backward
                    i_left_lim_new_rec = prev_rec.iLeftLim;
                    recs.pop();

                    // Update max area
                    int area = prev_rec.h * (i - prev_rec.iLeftLim);
                    if (area > max_area) {
                        max_area = area;
                    }
                } else {
                    break;
                }
            } while (!recs.empty());

            recs.push(Rec(i_left_lim_new_rec, h));
        }

        i++;
    }

    int n = heights.size();
    while (!recs.empty()) {
        auto rec = recs.top();

        // Update max area
        int area = rec.h * (n - rec.iLeftLim);
        if (area > max_area) {
            max_area = area;
        }

        recs.pop();
    }

    return max_area;
}

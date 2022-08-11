#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * \Trick   It's only hard to implement getMin in O(1). Implementing other 
 *          operations in O(1) is straightforward.
 * 
 *          Keeping a stack of non increasing minimum values.
 * 
 *          Observe that we can seperate the stack to contiguous chunks with 
 *          their own mins by keeping track of these mins value. The min value 
 *          of the stack only changes when a new min is added or the min value 
 *          is popped out. 
 * 
 *          By keeping a stack of mins, we can always get the current min of 
 *          the stack by popping out the newest element of the stack of mins. 
 * 
 *          Because the stack works in LIFO manner, the newest 
 *          min is always popped out first because it was pushed in last. And 
 *          the newest min is also the current min of the stack at any given 
 *          point in time.
 * \Time    Time
 * \Space   Space
 * \Ref     Reference
 */
class MinStack {
public:
    stack<int> *ps_min = nullptr;
    vector<int> *pv_val = nullptr;

    MinStack() {
        pv_val = new vector<int>;
        ps_min = new stack<int>;
    }

    ~MinStack() {
        delete pv_val;
        delete ps_min;
    }
    
    void push(int val) {
        pv_val->push_back(val);
        
        if (ps_min->empty()) {
            ps_min->push(val);
        } else {
            if (val <= ps_min->top()) {
                ps_min->push(val);
            }
        }
    }
    
    void pop() {
        int top = pv_val->back();
        pv_val->pop_back();
        
        if (top == ps_min->top()) {
            ps_min->pop();
        }
    }
    
    int top() {
        return pv_val->back();
    }
    
    int getMin() {
        return ps_min->top();
    }
};

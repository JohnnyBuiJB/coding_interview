#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * \Trick   Using stack to keep track of seen open brackets because at any once
 *          we see a closing bracket, its predecessor must be a matching opening
 *          bracket, which indicates the LIFO storing manner.
 * \Time    O(n), only 1 pass through the string
 * \Space   O(n)
 * \Ref     Bui V.
 */
bool isValid(string s) {
    // Keep a stack of open brackets
    stack<char> opens;
    
    for (const auto &c : s) {
        // Open brackets
        if (c == '(' || c == '[' || c == '{') {
            opens.push(c);
        } 
        // Close brackets, based on the input's constraints
        else {
            if (opens.empty()) {
                return false;
            } else {
                char last_brac = opens.top();
                bool is_match = false;
                
                switch (c) {
                    case ')':
                        if (last_brac == '(') 
                            is_match = true;
                        break;
                    case ']':
                        if (last_brac == '[') 
                            is_match = true;
                        break;
                    case '}':
                        if (last_brac == '{') 
                            is_match = true;
                        break;
                    default:
                        break;
                }

                if (is_match) {
                    opens.pop();
                } else {
                    return false;
                }
            }
        }
    }

    // More open than close
    if (!opens.empty()) {
        return false;
    }
    
    return true;
}

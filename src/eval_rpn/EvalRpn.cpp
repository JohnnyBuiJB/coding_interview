#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;

#define STACK_POP_2(stack, op1, op2) \
    do { \
        op2 = stack.top();  \
        stack.pop();        \
        op1 = stack.top();  \
        stack.pop();        \
    } while(0);


/**
 * \Trick   Observe that the format of the arithmetic is 
 *              EXPR = <EXPR> <EXPR> <operator> | decimal degits
 *              operator = + | - | * | /
 * 
 *          Whenever we see an operator, we need to check the two last operands 
 *          right before it, then evaluate the expression, and store the result 
 *          as the last operand. Stack is the best data structure to get the 
 *          last data item in constant time.
 * \Time    O(n)
 * \Space   O(n), the stack of operands may have to store all of the operands in 
 *          the tokens in the worst case, in which all operators are at the end 
 *          of the tokens.
 * \Ref     Bui V.
 */
int evalRPN(vector<string>& tokens) {
    stack<int> seen_ope;
    
    for (auto const &s : tokens) {
        int op1 = 0;
        int op2 = 0;
        // To avoid mistaking negative numbers with '-' operator
        if (s.size() == 1) {
            switch (s[0]) {
            case '+':
                STACK_POP_2(seen_ope, op1, op2);
                seen_ope.push(op1 + op2);
                break;

            case '-':
                STACK_POP_2(seen_ope, op1, op2);
                seen_ope.push(op1 - op2);
                break;

            case '*':
                STACK_POP_2(seen_ope, op1, op2);
                seen_ope.push(op1 * op2);
                break;

            case '/':
                STACK_POP_2(seen_ope, op1, op2);
                seen_ope.push(op1 / op2);
                break;
            
            default:
                seen_ope.push(atoi(s.data()));
                break;
            }
        } else {
            seen_ope.push(atoi(s.data()));
        }
    }

    return seen_ope.top();
}

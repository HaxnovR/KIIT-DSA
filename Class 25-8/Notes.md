# DSA Class 15th Sept

### Prefix to Infix algo

Scan from left to right

if character is operand, push to stack

if operator -> pop operand from stack(op1 op2) cancatenate and push it back to stack

repeat process till end of prefix expression

whe there is only 1 value in the stack i.e. infix expression, return it to the stack by popping.



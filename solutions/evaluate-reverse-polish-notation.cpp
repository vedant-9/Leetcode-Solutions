// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<long long> s;
        for(int i=0; i<t.size(); i++) {
            if(t[i]=="+" or t[i]=="-" or t[i]=="*" or t[i]=="/"){
                long long op2=s.top();
                s.pop();
                long long op1=s.top();
                s.pop();
                switch(t[i][0]){
                    case '+':
                        s.push(op1+op2);
                        break;
                    case '-':
                        s.push(op1-op2);
                        break;
                    case '*':
                        s.push(op1*op2);
                        break;
                    case '/':
                        s.push(op1/op2);
                        break;
                }
            }
            else{
                s.push(stoi(t[i]));
            }
        }
        return s.top();
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1)
            return stoi(tokens[0]);

        stack<int> nums;

        for(int i = 0; i < tokens.size(); i++) {
            string t = tokens[i];
            
            if((t != "*") && (t != "/") && (t != "+") && (t != "-")) {
                nums.push(stoi(t));
            } else if (nums.size() > 1) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                
                if(t == "*")
                    nums.push(a * b);
                else if(t == "/")
                    nums.push(a / b);
                else if(t == "+")
                    nums.push(a + b);
                else if(t == "-")
                    nums.push(a - b);
            }
        }

        return nums.top();
    }
};
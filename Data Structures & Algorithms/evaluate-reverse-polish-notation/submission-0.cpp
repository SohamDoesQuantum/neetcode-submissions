class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string s : tokens){
            if(s=="*"){
                int a = stoi(st.top()); st.pop();
                int b = stoi(st.top()); st.pop();
                string c = to_string(a*b);
                st.push(c);
            }
            else if(s=="+"){
                int a = stoi(st.top()); st.pop();
                int b = stoi(st.top()); st.pop();
                string c = to_string(a+b);
                st.push(c);
            }
            else if(s=="-"){
                int a = stoi(st.top()); st.pop();
                int b = stoi(st.top()); st.pop();
                string c = to_string(b-a);
                st.push(c);
            }
            else if(s=="/"){
                int a = stoi(st.top()); st.pop();
                int b = stoi(st.top()); st.pop();
                string c = to_string(b/a);
                st.push(c);
            }
            else st.push(s);
        }
        return stoi(st.top());
    }
};

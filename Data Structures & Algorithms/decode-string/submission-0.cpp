class Solution {
public:

    string decodeString(string s) {

        stack<char> st;

        for(char c : s){

            if(c != ']'){
                st.push(c);
            }

            else{

                // get substring

                string curr = "";

                while(st.top() != '['){
                    curr = st.top() + curr;
                    st.pop();
                }

                st.pop();

                // get number

                string num = "";

                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }

                int repeat = stoi(num);

                // build repeated string

                string expanded = "";

                for(int i = 0; i < repeat; i++){
                    expanded += curr;
                }

                // push back into stack

                for(char ch : expanded){
                    st.push(ch);
                }
            }
        }

        // build final answer

        string ans = "";

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
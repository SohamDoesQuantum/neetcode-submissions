class Solution {
public:
    string simplifyPath(string path) {
        std::stack<std::string> st;
        path.push_back('/');
        std::string txt = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/')
                txt += std::string(1, path[i]);
            else {
                if (txt == "..") {
                    if (!st.empty())
                        st.pop();
                   
                } else if (txt == "" || txt == ".") {
                    txt = "";
                    continue;
                }

                else
                    st.push(txt);
                txt = "";
            }
        }
        if(st.empty()) return "/";

        std::string ans ;
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
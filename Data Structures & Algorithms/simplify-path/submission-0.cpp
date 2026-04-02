class Solution {
public:
    std::string simplifyPath(std::string path)
    {
        std::stack<std::string> st;
        std::string cur = "";
        path += '/';

        for(char c : path)
        {
            if(c != '/')
            {
                cur += c;
            }
            else
            {
                if(cur == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else if(cur.size() > 0 && cur != ".")
                {
                    st.push(cur);
                }

                cur = "";
            }
        }

        if(st.empty())
            return "/";

        while(!st.empty())
        {
            cur = "/" + st.top() + cur;
            st.pop();
        }

        return cur;
    }
};
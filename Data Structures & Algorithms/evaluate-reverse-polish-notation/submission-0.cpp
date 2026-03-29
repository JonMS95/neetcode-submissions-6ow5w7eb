class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<std::string> st;
        int a, b;

        for(std::string t : tokens)
        {
            if(t != "+" && t != "-" && t != "*" && t != "/")
            {
                st.push(t);
                continue;
            }
            
            b = std::atoi(st.top().c_str()); st.pop();
            a = std::atoi(st.top().c_str()); st.pop();

            switch (t[0])
            {
                case '+':
                {
                    st.push(std::to_string(a + b));
                }
                break;

                case '-':
                {
                    st.push(std::to_string(a - b));
                }
                break;

                case '*':
                {
                    st.push(std::to_string(a * b));
                }
                break;

                case '/':
                {
                    st.push(std::to_string(a / b));
                }
                break;

                default:
                {
                    throw std::runtime_error("Found unexpected operator");
                }
                break;
            }
        }

        return std::atoi(st.top().c_str());
    }
};

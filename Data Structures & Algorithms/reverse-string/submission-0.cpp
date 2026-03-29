class Solution {
public:
    void reverseString(std::vector<char>& s)
    {
        const int s_size = static_cast<int>(s.size());

        for(int i = 0; i < (s_size / 2); i++)
            std::swap(s[i], s[s_size - i - 1]);
    }
};
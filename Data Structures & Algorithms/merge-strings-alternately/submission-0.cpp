class Solution {
private:
    void _addRemainder(const std::string& long_word, std::string& target)
    {
        for(int i = static_cast<int>(target.size()) / 2; i < static_cast<int>(long_word.size()); i++)
            target += long_word[i];
    }

public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        const int word1_size = static_cast<int>(word1.size());
        const int word2_size = static_cast<int>(word2.size());

        std::string ret = "";

        for(int i = 0; i < std::min(word1_size, word2_size); i++)
        {
            ret += word1[i];
            ret += word2[i];
        }

        std::cout << ret << std::endl;

        if(word1_size > word2_size)
            this->_addRemainder(word1, ret);
        else if(word1_size < word2_size)
            this->_addRemainder(word2, ret);
        
        return ret;
    }
};
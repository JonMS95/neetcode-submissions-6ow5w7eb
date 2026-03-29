class Solution {
private:
    bool _samePrefix(const std::string& s, const std::string& cand)
    {
        if(cand.size() > s.size())
            return false;
        
        for(int i = 0; i < static_cast<int>(cand.size()); i++)
            if(s[i] != cand[i])
                return false;
        
        return true;
    }

    bool _wordBreak(std::string s, std::vector<std::string>& wordDict, std::string& cur, std::unordered_map<long, bool>& known_paths)
    {
        if(known_paths.count(cur.size()))
            return known_paths[cur.size()];

        bool ret = false;

        for(const std::string& word : wordDict)
        {
            cur += word;

            if(this->_samePrefix(s, cur) && (cur.size() == s.size() || this->_wordBreak(s, wordDict, cur, known_paths)))
                ret = true;
            
            cur.resize(cur.size() - word.size());
        
            if(ret)
                break;
        }

        known_paths[cur.size()] = ret;

        return ret;
    }

public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        std::string cur = "";
        std::unordered_map<long, bool> known_paths;
        return this->_wordBreak(s, wordDict, cur, known_paths);
    }
};

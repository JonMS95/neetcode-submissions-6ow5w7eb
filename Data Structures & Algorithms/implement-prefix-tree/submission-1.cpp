class PrefixTree {
private:
    using trie = PrefixTree;
    using u_ptr = std::unique_ptr<trie>;
    using map_char_trie = std::unordered_map<char, u_ptr>;
    using str = std::string;

    const char c_;
    bool is_word_;
    map_char_trie pending_;

    void _insert(const str& s, const int idx = 0)
    {
        if(idx == static_cast<int>(s.size()))
        {
            this->is_word_ = true;
            return;
        }

        if(!this->pending_.count(s[idx]))
            this->pending_[s[idx]] = std::make_unique<trie>(s[idx]);
        
        this->pending_[s[idx]]->_insert(s, idx + 1);
    }

    bool _search(const str& s, bool word_mode = true, const int idx = 0)
    {
        if(idx >= static_cast<int>(s.size()))
            if(word_mode)
                return this->is_word_;
            else
                return true;

        if(!this->pending_.count(s[idx]))
            return false;

        return this->pending_[s[idx]]->_search(s, word_mode, idx + 1);
    }

public:
    PrefixTree(void): c_('\0'), is_word_(false) {}
    PrefixTree(const char c): c_(c), is_word_(false) {}
    
    void insert(string word)
    {
        this->_insert(word);
    }
    
    bool search(string word)
    {
        return this->_search(word);
    }
    
    bool startsWith(string prefix)
    {
        return this->_search(prefix, false);
    }
};

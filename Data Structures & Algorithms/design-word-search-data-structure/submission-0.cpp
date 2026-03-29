class WordDictionary {
private:
    using dict = WordDictionary;
    using p_dict = std::unique_ptr<dict>;
    using map_char_dict = std::unordered_map<char, p_dict>;
    using map_char_dict_iter = map_char_dict::iterator;
    using str = std::string;

    const char c_;          // Current node's character.
    bool is_word_;          // Tells whether current letter is the last one for a word (represents words ending).
    map_char_dict pending_; // Maps pending nodes (next characters) to WordDictionary type unique pointers.

    void _addWord(const str& word, const int idx = 0)
    {
        // If current node belongs to the last character, then mark it as a whole word and return.
        if(idx == static_cast<int>(word.size()))
        {
            this->is_word_ = true;
            return;
        }

        // Check whether current character exists among pending_'s keys. Create it if it doesn't.
        if(!this->pending_.count(word[idx]))
            this->pending_[word[idx]] = std::make_unique<dict>(word[idx]);

        // Call current function from the next node.
        this->pending_[word[idx]]->_addWord(word, idx + 1);
    }

    bool _search(const str& s, const int idx = 0)
    {
        // Check whether we are already at the last node.
        if(idx == s.size())
            return this->is_word_;
        
        // If it's a regular letter (non-wildcard), then return false if no pending node has been
        // found for such letter, and go ahead with recursion otherwise.
        if(s[idx] != '.')
            if(!this->pending_.count(s[idx]))
                return false;
            else
                return this->pending_[s[idx]]->_search(s, idx + 1); 
        
        for(map_char_dict_iter it = this->pending_.begin(); it != this->pending_.end(); it++)
            if(it->second->_search(s, idx + 1))
                return true;
        
        return false;
    }

public:
    WordDictionary(void): c_('\0'), is_word_(false) {}
    WordDictionary(const char c): c_(c), is_word_(false) {}
    
    void addWord(str word)
    {
        this->_addWord(word);
    }
    
    bool search(str word)
    {
        return this->_search(word);
    }
};

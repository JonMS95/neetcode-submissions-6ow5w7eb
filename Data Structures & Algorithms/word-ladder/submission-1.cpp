class Solution {
private:
    int _getWordIdx(const std::string& s, const std::vector<std::string>& word_list)
    {
        for(int i = 0; i < static_cast<int>(word_list.size()); i++)
            if(s == word_list[i])
                return i;
        
        return -1;
    }

	// For words of same length, return true only if (and only if) they are one
	// different character away from each other.
	bool _areWordsAdjacent(const std::string& a, const std::string& b)
	{
		if(a.size() != b.size())
			return false;

		int diff_chars = 0;
		
		for(int i = 0; i < static_cast<int>(a.size()); i++)
			if(a[i] != b[i])
				if(diff_chars > 0)
					return false;
				else
					diff_chars++;
		
		return true;
	}
	
	std::vector<std::string> _getAdjacentWords(const std::string& cur, const std::vector<std::string>& word_list, std::unordered_set<std::string>& words_to_avoid)
	{
		std::vector<std::string> ret;
	
		for(const std::string& w : word_list)
            if(words_to_avoid.count(w))
                continue;
            else
                if(cur != w && this->_areWordsAdjacent(cur, w))
                    ret.emplace_back(w);
				
		return ret;
	}
	
	int _bfs(const std::string& start, const std::vector<std::string>& word_list, const std::string& end)
	{
		std::unordered_set<std::string> known; // Known words (those that have already been visited).
		known.insert(start);
		
		std::queue<std::string> cur;
		cur.push(start);
		
		int queue_size = static_cast<int>(cur.size());
		
		int ret = 0;
		
		while(!cur.empty())
		{
			++ret;
		
			for(int i = 0; i < queue_size; i++)
			{
				// If current word is equal to our target, then
				if(cur.front() == end)
					return ret;

				// Add current word to set of visited words so as not to visit it afterwards.
				known.insert(cur.front());
			
				// For the current word (queue's front), get the adjacent words that have not been
				// visited (not found within known words set). Push them to the queue.
				for(const std::string& adj : this->_getAdjacentWords(cur.front(), word_list, known))
					if(!known.count(adj))
						cur.push(adj);
				
				cur.pop();
			}
			
			queue_size = static_cast<int>(cur.size());
		}
		
		return 0;
	}

public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
    {
        if(this->_getWordIdx(endWord, wordList) < 0)
            return 0;
        
        wordList.emplace_back(beginWord);
		
		return this->_bfs(beginWord, wordList, endWord);
    }
};
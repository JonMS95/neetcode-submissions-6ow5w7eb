class Solution {	
private:
	int getSumOfSquaredNumberFigures(int n)
	{
		int ret = 0;
		int fig;
		
		while(n > 0)
		{
			fig = n % 10;
			ret += fig * fig;
			n /= 10;
		}
		
		return ret;
	}

public:
    bool isHappy(int n)
	{
		std::unordered_set<int> known_values;
	
        while(n != 1)
		{
			n = this->getSumOfSquaredNumberFigures(n);
			
			if(known_values.count(n))
				return false;
			
			known_values.insert(n);
		}
		
		return true;
    }
};

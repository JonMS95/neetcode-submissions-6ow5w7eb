/*
Approach: create a histogram including each number's frequency. Then, keep trying
to group straight starting from the lowest number in the histogram. To keep such
lowest value, use a priority queue. Erase queue's top whenever the key for that
value has been erased from the histogram.

Example (this will clarify many things):
hand = [1,2,4,2,3,5,3,4], groupSize = 4

hist = 
{
    {1, 1},
    {2, 2},
    {3, 2},
    {4, 2},
    {5, 1},
}

Heap (no duplicates): 1 2 3 4 5

Start with the lowest: 1

Iterate the histogram looking for the next value (if any) on the heap. Return -1 (or
whatever) if not found, erase key-pair from hist and heap's top if value reached 0.
*/

class Solution
{
private:
    using min_pq = std::priority_queue<int, std::vector<int>, std::greater<int>>;

    std::unordered_map<int, int> _makeHistFromVector(std::vector<int>& vec)
    {
        std::unordered_map<int, int> ret;

        for(int n : vec)
            ++ret[n];
        
        return ret;
    }

    min_pq _getMinHeapFromHistKeys(std::unordered_map<int, int>& hist)
    {
        min_pq ret;

        for(auto it = hist.begin(); it != hist.end(); it++)
            ret.push(it->first);
        
        return ret;
    }

public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        std::unordered_map<int, int> hist = this->_makeHistFromVector(hand);

        min_pq min_heap = this->_getMinHeapFromHistKeys(hist);
        int start, end;

        while(!min_heap.empty())
        {
            start = min_heap.top();
            end = min_heap.top() + groupSize - 1;

            for(int i = start; i <= end; i++)
            {
                if(!hist.count(i))
                    return false;
                
                --hist[i];

                if(!hist[i])
                {
                    hist.erase(i);
                    min_heap.pop();
                }
            }
        }

        return true;
    }
};

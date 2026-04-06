class CountSquares {
private:
    std::vector<std::vector<int>> known_points_;

    // Returns points set in a diagonal line with respect to the given point.
    // Note that the point itself is not being returned.
    std::vector<int> _getIndicesOfDiagonalsToPoint(const std::vector<int>& point)
    {
        std::vector<int> ret;
        int new_x, new_y;

        for(int i = 0; i < static_cast<int>(known_points_.size()); i++)
        {
            new_x = this->known_points_[i][0] - point[0];
            new_y = this->known_points_[i][1] - point[1];
        
            if(!new_x && !new_y)
                continue;
            
            if(new_x == new_y || new_x == -new_y)
                ret.emplace_back(i);
        }

        return ret;
    }

    int _countPointsInGivenCoords(const int row, const int col)
    {
        int ret = 0;

        for(const std::vector<int>& kp : this->known_points_)
            if(kp[0] == row && kp[1] == col)
                ++ret;
        
        return ret;
    }

public:
    CountSquares() {}
    
    void add(std::vector<int> point)
    {
        this->known_points_.emplace_back(point);
    }
    
    int count(std::vector<int> point)
    {
        int ret = 0;

        // Count number of points in a diagonal (taking current point as origin).
        std::vector<int> diag_idcs = this->_getIndicesOfDiagonalsToPoint(point);

        // If no diagonal points have been found, then exit immediately.
        if(diag_idcs.empty())
            return ret;
        
        // For each diagonal point found (might have been repeated), look for:
        // ·Points in same row as current point and same column as diagonal point.
        // ·Points in same col as current point and same row as diagonal point.
        // Add the multiplication of both numbers to the result.
        for(int idx : diag_idcs)
            ret += this->_countPointsInGivenCoords(this->known_points_[idx][0], point[1]) * this->_countPointsInGivenCoords(point[0], this->known_points_[idx][1]);

        return ret;
    }
};

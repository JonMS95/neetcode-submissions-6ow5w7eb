class CountSquares {
private:
    std::vector<std::vector<int>> known_points_;

    // Returns indices of points on a diagonal with respect to the given point.
    std::vector<int> _getIndicesOfDiagonalsToPoint(const std::vector<int>& point)
    {
        std::vector<int> ret;

        for (int i = 0; i < static_cast<int>(known_points_.size()); i++)
        {
            int dx = known_points_[i][0] - point[0];
            int dy = known_points_[i][1] - point[1];

            // Skip the point itself
            if (dx == 0 && dy == 0)
                continue;

            // Diagonal if |dx| == |dy|
            if (dx == dy || dx == -dy)
                ret.emplace_back(i);
        }

        return ret;
    }

    // Counts number of points at (row, col)
    int _countPointsInGivenCoords(const int row, const int col)
    {
        int ret = 0;
        for (const auto& kp : known_points_)
            if (kp[0] == row && kp[1] == col)
                ++ret;
        return ret;
    }

public:
    CountSquares() {}

    void add(std::vector<int> point)
    {
        known_points_.emplace_back(point);
    }

    int count(std::vector<int> point)
    {
        int ret = 0;

        // Get all diagonal points
        std::vector<int> diag_idcs = _getIndicesOfDiagonalsToPoint(point);

        for (int idx : diag_idcs)
        {
            int diag_x = known_points_[idx][0];
            int diag_y = known_points_[idx][1];

            // Count points forming a square
            int count1 = _countPointsInGivenCoords(diag_x, point[1]); // same row as diagonal, col as query
            int count2 = _countPointsInGivenCoords(point[0], diag_y); // row as query, col as diagonal

            ret += count1 * count2;
        }

        return ret;
    }
};
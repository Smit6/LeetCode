class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int up = 0, left = 0;
        int down = matrix.size() - 1, right = matrix[0].size() - 1;
        unsigned int num_elements = (down + 1) * (right + 1);

        vector<int> result;

        while (result.size() < num_elements)
        {
            for (int c = left; c <= right; c++)
                result.emplace_back(move(matrix[up][c]));

            for (int r = up + 1; r <= down; r++)
                result.emplace_back(move(matrix[r][right]));

            if (up != down)
                for (int c = right - 1; c >= left; c--)
                    result.emplace_back(move(matrix[down][c]));

            if (left != right)
                for (int r = down - 1; r > up; r--)
                    result.emplace_back(move(matrix[r][left]));

            ++left, --right, ++up, --down;
        }

        return result;
    }
};

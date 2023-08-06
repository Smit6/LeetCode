class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int up = 0, left = 0;
        int down = matrix.size() - 1, right = matrix[0].size() - 1;
        int up_left = 0;

        while (up < down)
        {
            for (int i = 0; i < right - left; i++)
            {
                up_left = matrix[up][left + i];
                matrix[up][left + i] = matrix[down - i][left];
                matrix[down - i][left] = matrix[down][right - i];
                matrix[down][right - i] = matrix[up + i][right];
                matrix[up + i][right] = up_left;
            }
            ++up, --down, ++left, --right;
        }
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool is_first_row_zero = false;
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (matrix[r][c] == 0)
                {
                    if (r != 0)
                        matrix[r][0] = 0;
                    else
                        is_first_row_zero = true;
                    matrix[0][c] = 0;
                }
        
        for (int r = 1; r < rows; r++)
            for (int c = 1; c < cols; c++)
                if (!matrix[0][c] || !matrix[r][0])
                    matrix[r][c] = 0;
        
        if (matrix[0][0] == 0)
            for (int r = 0; r < rows; r++)
                matrix[r][0] = 0;
        
        if (is_first_row_zero)
            for (int c = 0; c < cols; c++)
                matrix[0][c] = 0;
    }
};
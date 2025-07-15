#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution
{
public:
    bool backtrack(vector<vector<char>> &board, const string &word, vector<vector<bool>> &used, int len, int row, int col)
    {
        if (len == word.size()) // 如果检测的长度等于需要的长度
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[len] || used[row][col] == true)
            return false; // 检测到数组越界或都检查完毕
        /*对二维数组进行检查*/
        used[row][col] = true;
        if (backtrack(board, word, used, len + 1, row, col + 1) || // 右
            backtrack(board, word, used, len + 1, row + 1, col) || // 下
            backtrack(board, word, used, len + 1, row, col - 1) || // 左
            backtrack(board, word, used, len + 1, row - 1, col))   // 上
            return true;
        used[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int rowsize = board.size();
        int colsize = board[0].size();
        for (int row = 0; row < rowsize; row++)
        {
            for (int col = 0; col < colsize; col++)
            {
                vector<vector<bool>> used(rowsize, vector<bool>(colsize, false));
                if (backtrack(board, word, used, 0, row, col))
                    return true;
            }
        }
        return false;
    }
};
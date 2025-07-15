#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_map<int, vector<int>> map; // Key:行号,value:列
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                    map[i].push_back(j);
            }
        }

        for (auto &entry : map)
        {
            int row = entry.first;
            // 处理行
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[row][i] = 0;
            }
            // 处理列
            for (int col : entry.second) // 遍历某一行的列
            {
                for (int i = 0; i < matrix.size(); i++)
                {
                    matrix[i][col] = 0;
                }
            }
        }
    }
};
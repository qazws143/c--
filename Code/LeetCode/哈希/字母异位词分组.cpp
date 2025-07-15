#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 第一个表示一个字符串,第二个参数表示和字符串异位的字符串
        unordered_map<string, vector<string>> map;
        for (const string &s : strs) // 遍历每个字符串
        {
            string key = s;
            sort(key.begin(), key.end()); // 升序字符串
            map[key].push_back(s);        // 将相同的字符串放在一个数组
        }
        vector<vector<string>> result;
        for (auto &pair : map)
            result.push_back(pair.second); // 将元素放入数组
        return result;
    }
};
#include"iostream"
#include<unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& origi_list, vector<int> current_list,
                            int current_layer, int len, vector<bool>& used) {
        // 所有数都填完了
        if (current_layer == len) {
            vector<int> list_copy = current_list;
            res.emplace_back(list_copy);
            return;
        }

        for (int i = 0; i < len; i++)
        {
            if (used[i] == true)
            {
                continue;
            }
            else
            {
                used[i] = true;
                current_list.push_back(origi_list[i]);
                dfs(res, origi_list, current_list, current_layer + 1, len, used);
                used[i] = false;
                current_list.pop_back();
            }
        }
        //for (int i = first; i < len; ++i) {
        //    // 动态维护数组
        //    swap(output[i], output[first]);
        //    // 继续递归填下一个数
        //    dfs(res, output, first + 1, len);
        //    // 撤销操作
        //    swap(output[i], output[first]);
        //}
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<bool> used(nums.size(), false);
        vector<int> current_list;
        dfs(res, nums, current_list ,0, (int)nums.size(),used);
        return res;
    }
};



int main()
{
    Solution b;
    vector<int> a = { 1,2,3 };
    auto c = b.permute(a);
    vector<vector<int >>::iterator iter;
    for (iter = c.begin(); iter < c.end(); iter++)
    {
        auto vec_tmp = *iter;
        for (auto j = 0; j < (*iter).size(); j++)
            cout << (*iter)[j];
        cout << endl;
    }

}
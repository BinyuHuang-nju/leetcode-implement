#include <iostream>
using namespace std;
#include<vector>
#include <map>
class Solution {
private:
    struct Item {
        int count;
        int data;
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums;
        map<int, int> count;
        int i;
        for (i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        vector<Item> item;
        Item temp;
        map<int, int>::iterator iter;
        for (iter = count.begin(); iter!=count.end();  iter++) {
            temp.count = iter->second;
            temp.data = iter->first;
            item.push_back(temp);
        }
        select_elinear(item, 0, item.size() - 1, k);
        quick_sort(item, 0, k - 1);
        vector<int> res;
        for (i = 0; i < k; i++)
            res.push_back(item[i].data);
        return res;
    }

    void select_elinear(vector<Item>& item, int start, int end, int k) {
        if (start == end)
            return;
        int q = partition(item, start, end);
        int x = q - start + 1;
        if (k == x)
            return;
        else if (k < x)
            select_elinear(item, start, q - 1, k);
        else
            select_elinear(item, q + 1, end, k - x);
    }
    int partition(vector<Item>& item, int start, int end) {
        Item pivot = item[end], temp;
        int i = start;
        for(int j=start;j<end;j++)
            if (item[j].count > pivot.count) {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
                i++;
            }
        temp = item[i];
        item[i] = item[end];
        item[end] = temp;
        return i;
    }
    void quick_sort(vector<Item>& item, int start, int end) {
        if (start < end) {
            int q = partition(item, start, end);
            quick_sort(item, start, q - 1);
            quick_sort(item, q + 1, end);
        }
    }
};
int main() {
    vector<int> nums = { 1,1,3,2,1,2,1,1,2 };
    Solution sol;
    sol.topKFrequent(nums, 2);
    return 0;
}
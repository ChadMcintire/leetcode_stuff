#include <vector>

using namespace std;
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int count1 = 0;
        int count2 = 0;
         for (auto& it : nums) {
            for (auto& it2 : nums) {
                if (count1 != count2){
                    int test_num = nums[count1] + nums[count2];
                    if (test_num == target){
                        vector<int> found {count1, count2};
                        return found;
                    }
                }
                else {
                }
                count2++;
                if (count2 > nums.size() -1){
                    count2 = 0;
                }
            }
         count1++;
         }
    return nums;
    }

};

int main()
{
    vector<int> finder {1, 2, 3, 4, 5};
    Solution s;
    s.twoSum(finder, 9);
}

class Solution {
public:
    bool duplicate(int nums[], int length, int* duplication) {
        for (int i = 0; i < length; i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    duplication[0] = nums[i];
                    return true;
                } else {
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        return false;
    }
};


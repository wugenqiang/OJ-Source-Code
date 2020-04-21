class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty() || array[0].empty()) {
            return false;
        }
        int i = 0, j = array[0].size() - 1;
        while (i <= array.size() - 1 && j >= 0) {
            if (array[i][j] == target) {
                return true;
            }
            if (array[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};


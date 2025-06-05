// find the starting and ending position of a given target value.
#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(vector<int>& nums, int key) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == key) {
            result = mid;
            high = mid - 1; // search left
        } else if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(vector<int>& nums, int key) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == key) {
            result = mid;
            low = mid + 1; // search right
        } else if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int start = findFirstOccurrence(nums, target);
    int end = findLastOccurrence(nums, target);
    return {start, end};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "Start: " << result[0] << ", End: " << result[1] << endl;
    return 0;
}

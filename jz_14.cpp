#include <iostream>
#include <utility>

using namespace std;

void sort(int* nums, int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        while (left < right && nums[right] % 2 == 0) {
            right--;
        }

        while (left < right && nums[left] % 2 != 0) {
            left++;
        }

        swap(nums[left], nums[right]);
    }

    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    int nums[] = {1, 2, 3, 4, 5, 6};
    sort(nums, sizeof(nums) / sizeof(int));

    return 0;
}
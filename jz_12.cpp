#include <vector>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

void print_n(int n) {
    string str{"0"};
    
    while (str.size() <= n) {
        int m = str.back() - '0' + 1;
        if (m < 10) {
            str[str.size() - 1] += 1;
        } else {
            int size_9 = 0;
            for (int i = str.length() - 1; i >= 0; i--) {
                if (str[i] == '9') {
                    size_9++;
                }
                else
                    break;
            }

            if (size_9 == str.length()) {
                str.clear();
                str.push_back('1');
                for (int i = 0; i < size_9; i++)
                    str.push_back('0');
            } else {
                str[str.length() - size_9 - 1] += 1;
                for (int i = str.length() - 1; i > str.length() - 1 - size_9; i--) {
                    str[i] = '0';
                }
            }
        }

        cout << str << " ";
    }
}

void print_n_1(int n) {
    string nums;
    nums.assign(n, '0');

    function<void(int)> dns = [&](int m) {
        if (m == n)
            cout << nums << " ";
        else {
            for (int i = 0; i < 10; i++) {
                nums[m] = '0' + i;
                dns(m + 1);
            }
        }
    };
    dns(0);
}

void print_abcd() {
    int m = 4;
    string ret(m, '0');

    function<void(int)> dns = [&](int n) {
        if (n  == m) {
            cout << ret << " ";
        } else {
            for (int i = 0; i < m; i++) {
                ret[n] = 'a' + i;
                dns(n + 1);
            }
        }
    };
    dns(0);
}

void backtrack(vector<char>& nums, string& track) {
    if (track.size() == nums.size()) {
        cout << track << " ";
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}

void print_abcd_1() {
    vector<char> nums{'a', 'b', 'c', 'd'};
    string track;
    backtrack(nums, track);
}

int main(int argc, char* argv[]) {
    // print_n_1(atoi(argv[1]));
    print_abcd_1();
    cout << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // vector<int> nums{10, 7, -9, 14, -3, 4, -22};
    vector<int> nums{10, 10, -20, -14, 10, -20};

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int a = nums[n - 1] * nums[0] * nums[1]; // maior positivo vezes os 2 menores negativos 
    int b = nums[n - 1] * nums[n - 2] * nums[n - 3]; // 3 maiores positivos

    cout << (a > b ? a : b) << endl;
}
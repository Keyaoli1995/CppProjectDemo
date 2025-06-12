#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int value = arr[5]; // 明显的数组越界
    std::cout << value << std::endl;
    return 0;
}
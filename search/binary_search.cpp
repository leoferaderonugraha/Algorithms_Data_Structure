#include <iostream>
#include <vector> // daripada array

int bin_srch(std::vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int mid = (left + right) / 2;

    while (left < right) {
        if (arr[mid] == target) {
            return mid;
        } else {
            if (arr[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }   
            
            mid = (left + right) / 2;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};

    std::cout << bin_srch(arr, 7) << std::endl;
}

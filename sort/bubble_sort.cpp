/* ascending */
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &vect)
{
    for (auto i = 0; i < vect.size()-1; i++) {
        if (vect[i] > vect[i + 1]) {
            // swapping with xor
            vect[i] ^= vect[i + 1];
            vect[i + 1] ^= vect[i];
            vect[i] ^= vect[i + 1];
        }
    }
}

void print_vect(std::vector<int> vect) {
    for (int i : vect) {
        std::cout << i << ' ';
    }
}

int main()
{
    std::vector<int> vect = {1,3,2,5,4};
    
    std::cout << "Before: ";
    print_vect(vect);
    std::cout << "\nAfter : ";
    bubble_sort(vect);
    print_vect(vect);
    std::cout << '\n';
}

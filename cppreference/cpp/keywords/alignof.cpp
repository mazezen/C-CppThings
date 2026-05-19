#include <cstddef>
#include <iostream>

int main()
{
    std::cout << __APPLE__ << '\n';
    std::cout << alignof(std::max_align_t) << '\n';
}

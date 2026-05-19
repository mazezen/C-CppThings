#include <iostream>

int main(void)
{
    
#if defined(__cplusplus)
    std::cout << "cplusplus_version: " << __cplusplus << "\n";
#endif

    return 0;
}
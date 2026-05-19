#include <iostream>

int main(void)
{

    #if defined(__cplusplus)

    switch (__cplusplus)
    {
    

    case 199711L:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version C++98 or C++03 " << "\n";
        break;

    case 201103L:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version C++11 " << "\n";
        break;

    case 201402L:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version C++14 " << "\n";
        break;

    case 201703L:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version C++17 " << "\n";
        break;

    case 202002L:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version C++20 " << "\n";
        break;

    case 202302L:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version C++23 " << "\n";
        break;

    default:
        std::cout << __cplusplus << "\n";
        std::cout << "cplusplus version earlier or later " << "\n";
        break;
    }

    #endif


    return 0;
}
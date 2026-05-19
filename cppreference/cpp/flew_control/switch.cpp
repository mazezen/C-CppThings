#include <iostream>

int main()
{
    int i = 1;
    switch (i)
    {
        case 1:
            std::cout << '1';
            break;
        case 2:
            std::cout << '2';
            break;
        default:
            break;
    }


    switch (1)
    {
        case 1:
            {
                int x = 2;
                std::cout << x << '\n';
                break;
            }
        default:
            std::cout << "default\n";
            break;
    }

}

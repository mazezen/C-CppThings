#include <iostream>

int main()
{
    int i = 2;
    if (i > 2)
        std::cout << i << " is greater than 2\n";
    else
        std::cout << i << " is not greater than 2\n";

    int j = 1;
    if (i > 1) {
        if (j > 2)
            std::cout << i << " > 1 and " << j << " > 2\n";
        else
            std::cout << i << " > 1 and " << j <<" < 2\n";
    }
       
    struct Base {
        virtual ~Base() {}
    };

    struct Derived : Base {
        void df() { std::cout << "df()\n"; }
    };

    // Derived *bp1 = new Base;
    Derived *bp2 = new Derived;

    if (auto p = dynamic_cast<Derived*>(bp2)) {
        p->df();
    }
}

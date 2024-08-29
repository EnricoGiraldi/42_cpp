#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception> // Per gestire le eccezioni

using std::cout;
using std::endl;

Base *generate(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    char c = "ABC"[rand() % 3];

    cout << "Type " << c << " created!" << endl;
    switch (c)
    {
        case 'A':
            return new A;
        case 'B':
            return new B;
        case 'C':
            return new C;
        default:
            return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
    {
        cout << "A" << endl;
    }
    else if (dynamic_cast<B *>(p) != NULL)
    {
        cout << "B" << endl;
    }
    else if (dynamic_cast<C *>(p) != NULL)
    {
        cout << "C" << endl;
    }
    else
    {
        cout << "Invalid type" << endl;
    }
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        cout << "A" << endl;
    }
    catch (std::exception &)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            cout << "B" << endl;
        }
        catch (std::exception &)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                cout << "C" << endl;
            }
            catch (std::exception &)
            {
                cout << "Invalid type" << endl;
            }
        }
    }
}

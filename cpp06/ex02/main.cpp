#include "Functions.hpp"

int main() {
    Base* basePtr = generate();
    identify(basePtr);     // Identificazione tramite puntatore
    identify(*basePtr);    // Identificazione tramite riferimento

    delete basePtr;        // Non dimenticare di deallocare la memoria
    return 0;
}

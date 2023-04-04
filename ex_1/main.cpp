#include <cstdlib>
#include <cstdio>


int main() {
    int gettyburg{};
    int* gettyburg_address = &gettyburg;

    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);

    *gettyburg_address = 124; // derefence operator
    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);
}
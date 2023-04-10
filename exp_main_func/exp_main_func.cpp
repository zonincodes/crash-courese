#include <cstdio>
#include <cstdint>

struct HelloWorld
{
    int one; 
    int two;
};
int main(int argc, char** argv){
    printf("Arguments: %d\n", argc);
    for(size_t i{1}; i < argc; i++)
    {
        printf("%zd: %s\n", i, argv[i]);
    }

    // 
    HelloWorld greets{1, 3};
    printf("one: %d | two: %d\n", greets.one, greets.two);
}
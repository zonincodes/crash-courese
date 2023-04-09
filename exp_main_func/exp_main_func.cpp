#include <cstdio>
#include <cstdint>

int main(int argc, char** argv){
    printf("Arguments: %d\n", argc);
    for(size_t i{1}; i < argc; i++)
    {
        printf("%zd: %s\n", i, argv[i]);
    }
}
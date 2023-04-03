#include <iostream>

using namespace std;

#include <system_error>
#include <cstdio>

struct File {
    File(const char* path, bool write)
    {
        auto file_mode = write ? "w" : "r";
        file_pointer = fopen(path, file_mode);
        if(!file_pointer) throw system_error(errno, system_category());
    }

    ~File()
    {
        fclose(file_pointer);
    }

    FILE *file_pointer;
};
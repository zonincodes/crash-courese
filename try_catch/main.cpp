#include <iostream>

using namespace std;

#include <system_error>
#include <cstdio>
#include <cstring>

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


int main()
{
    {
        File file("last_message.txt", true);
        const auto message = "We apologize for the inconvenience.";

        fwrite(message, strlen(message), 1, file.file_pointer);
    }

    {
        File file("last_message.txt", false);
        char read_message[37]{};
        fread(read_message, sizeof(read_message), 1, file.file_pointer);
        printf("Read last message: %s\n", read_message);
    }
}
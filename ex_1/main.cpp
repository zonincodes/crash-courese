#include <cstdlib>
#include <cstdio>

/*
First initialize gettysburg to zero
Initialize the pointer gettyburg_address to the address of gettysburg
Print the int pointed to vy gettysburg_address
and the value of gettysburg_address itseld
Write the value 124 into the memory pointed to by gettysburg_adress and 
then print the pointed-to value
and adress
*/
struct ClockOfTheLongNow{
    ClockOfTheLongNow(){
        set_year(2019);
    }

    void add_year(){
        year++;
    }

    bool set_year(int new_year){
        if(new_year < 2019) {
            year = 2019;
            return false;
        };
        year = new_year;
        return true;
    }

    int get_year(){
        return year;
    }

    private:
        int year;
};

int main() {
    int gettyburg{};
    int* gettyburg_address = &gettyburg;

    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);

    *gettyburg_address = 124; // derefence operator
    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);
}
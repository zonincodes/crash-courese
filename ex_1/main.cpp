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

struct College{
    char name[256];
};

void print_names(College *colleges, size_t n_colleges)
{
    for(size_t i =0; i < n_colleges; i++)
    {
        printf("%s College\n", colleges[i].name);
    }
}

int main() {
    int gettyburg{};
    int* gettyburg_address = &gettyburg;

    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);

    *gettyburg_address = 124; // derefence operator
    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);

    // 
    ClockOfTheLongNow clock;
    ClockOfTheLongNow* clock_ptr = &clock;

    clock_ptr ->set_year(2020);
    printf("Address of cloack: %p\n", clock_ptr);
    printf("Value of clock's year: %d\n", clock_ptr->get_year());
    printf("Value of clock's year: %d derefence\n", (*clock_ptr).get_year());

    // Handling decay
    printf("\n*****************  handling decay ***************** \n");
    College oxford[] = {"Magdalen", "Nuffield", "Kellogg"};
    print_names(oxford, sizeof(oxford)/ sizeof(College));
}
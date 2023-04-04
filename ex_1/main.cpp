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

void add_year(ClockOfTheLongNow& clock)
{
    clock.set_year(clock.get_year() + 1);
}   

struct Element
{
    Element* next{};
    void insert_after(Element* new_element)
    {
        new_element -> next = next;
        next = new_element;
    }

    char prefix[2];
    short operating_number;
};


int main() {
    int gettyburg{};
    int* gettyburg_address = &gettyburg;

    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);
    printf("\n*************************************************\n");
    *gettyburg_address = 124; // derefence operator
    printf("Value at gettysburg_address: %d\n", *gettyburg_address);
    printf("Gettysburg Address: %p\n", gettyburg_address);
    printf("\n*************************************************\n");

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

    printf("\n***************** Pointer Arithmetic  ***************** \n");
    College* third_college_ptr = &oxford[2]; 
    College* third_college_ptr_arithmetic = oxford + 2; 

    printf("%s direct access. \n%s indirect access\n", third_college_ptr -> name, third_college_ptr_arithmetic -> name);

    printf("\n***************** References  ***************** \n");

    ClockOfTheLongNow newClock;
    printf("The year is %d. \n", newClock.get_year());
    add_year(newClock); //clock is implicityly passed by refence!
    printf("The year is %d.\n", clock.get_year());
    // Forward-Linked Lists: The Canonical Pointer-Based Data Structure
    printf("\n***************** Forward-Linked Lists: The Canonical Pointer-Based Data Structure  ***************** \n");

    Element trooper1, trooper2, trooper3;
    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    trooper1.insert_after(&trooper2);
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3);
    trooper3.prefix[0] = 'M';
    trooper3.prefix[1] = 'K';
    trooper3.operating_number = 005;

    for (Element* cursor = &trooper1; cursor; cursor = cursor -> next)
    {
        printf("Stormtrooper %c%c-%d\n", 
        cursor ->prefix[0],
        cursor->prefix[1],
        cursor->operating_number);
    }
}
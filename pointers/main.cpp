#include <iostream>

struct HolmesIV{
    bool is_sentient;
    int sence_of_humor_rating;
};

void mannie_service(HolmesIV*);
void mannie_service(HolmesIV&);

void make_sentient(HolmesIV*);
void make_sentient(HolmesIV&);

int main() {
    HolmesIV john;

    HolmesIV *mike = &john;

    make_sentient(*mike);
    
    std::cout << "Made sentient :" << mike->is_sentient <<std::endl;

    make_sentient(&john);
    std::cout << "Made sentient :" << mike->is_sentient << std::endl;
}

void make_sentient(HolmesIV* mike){
    mike ->is_sentient = true;
}

void make_sentient(HolmesIV& mike){
    mike.is_sentient = false;
}
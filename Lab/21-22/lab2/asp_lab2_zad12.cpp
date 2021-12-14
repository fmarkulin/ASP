#include <iostream>

class Osoba
{
private:
    std::string ime;
    unsigned short int starost;

public:
    Osoba(std::string ime, unsigned short int starost) : ime(ime), starost(starost) {}
    std::string getIme() {return ime;}
    unsigned short int getStarost() {return starost;}
    void setIme(std::string ime) {this->ime = ime;}
    void setStarost(unsigned short int starost) {this->starost = starost;}
    ~Osoba() {std::cout << "Obrisan/a " << this->ime << "|" << this->starost << std::endl;}

    friend bool operator<(Osoba const &a, Osoba const &b);
};

bool operator<(Osoba const &a, Osoba const &b)
{
    if(a.starost < b.starost)
        return a.starost < b.starost;
    return a.ime[0] < b.ime[0];
}


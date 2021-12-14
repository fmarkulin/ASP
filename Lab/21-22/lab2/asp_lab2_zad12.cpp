#include <iostream>

class Osoba
{
private:
    std::string ime;
    unsigned short int starost;

public:
    Osoba(std::string ime, unsigned short int starost) : ime(ime), starost(starost) {}
    std::string getIme() { return ime; }
    unsigned short int getStarost() { return starost; }
    void setIme(std::string ime) { this->ime = ime; }
    void setStarost(unsigned short int starost) { this->starost = starost; }
    ~Osoba() { std::cout << "Obrisan/a " << this->ime << "|" << this->starost << std::endl; }

    friend bool operator<(Osoba const &a, Osoba const &b);
    Osoba &operator=(const Osoba &osoba)
    {
        this->ime = osoba.ime;
        this->starost = osoba.starost;

        return *this;
    }
};

bool operator<(Osoba const &a, Osoba const &b)
{
    if (a.starost < b.starost)
        return a.starost < b.starost;
    return a.ime[0] < b.ime[0];
}

template <typename T>
void InsertionSort(T A[], int n)
{
    T temp;
    for(int i = 0; i < n; i++)
    {
        temp = A[i];
        int j;
        for(j = i + 1; j >= 1 && A[j - 1] > A[j]; j--)
            A[j] = A[j - 1];   
    }
}
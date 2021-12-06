#include <iostream>

template <class T>
class Lista
{
    template <class X>
    struct Cvor
    {
        std::string string;
        Cvor<X> *next;
        Cvor<X> *prev;
    };

    Cvor<T> *head = nullptr;
    Cvor<T> *tail = nullptr;

public:
    bool upis(std::string string)
    {
        Cvor<std::string> *newElement = new (std::nothrow) Cvor<std::string>;
        if (!newElement)
            return false;

        newElement->string = string;
        newElement->next = nullptr;
        newElement->prev = tail;

        if (tail == nullptr)
            head = newElement;
        else
            tail->next = newElement;

        tail = newElement;
        return true;
    }

    void ispis()
    {
        Cvor<T> **p = &head;
        int i = 1;
        while (*p)
        {
            std::cout << i++ << ".| " << (*p)->string << std::endl;
            p = &((*p)->next);
        }
        return;
    }
};

int main(void)
{
    int n;
    std::cout << "Upišite željeni broj upisa stringova: ";
    std::cin >> n;
    std::cin.ignore(1,'\n');
    Lista<std::string> *lista = new Lista<std::string>;
    for(int i = 0; i < n; i++)
    {
        std::string upis;
        std::cout << "Upišite " << i + 1 << ". string: ";
        std::getline(std::cin, upis);
        lista->upis(upis);
    }

    std::cout << "Ispis svih string-ova u listi: " << std::endl;
    lista->ispis();

    delete lista;

    return 0;
}
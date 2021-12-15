#include <iostream>

template <class T>
class Lista
{
    template <class X>
    struct Cvor
    {
        X data;
        Cvor<X> *next;
        Cvor<X> *prev;
    };

    Cvor<T> *head = nullptr;
    Cvor<T> *tail = nullptr;

public:
    bool upis(T element)
    {
        Cvor<T> *newElement = new (std::nothrow) Cvor<T>;
        if (!newElement)
            return false; // neuspjelo stvaranje novog elementa
        newElement->data = element;
        newElement->next = nullptr;
        newElement->prev = tail;

        if (!head)
            head = newElement;
        else
            tail->next = newElement;

        tail = newElement;
        return true;
    }

    void ispis()
    {
        Cvor<T> **p = &head;
        while(*p)
        {
            std::cout << "|" << (*p)->data << "|";
            p = &((*p)->next);
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    int n;
    std::cout << "n: ";
    std::cin >> n;
    std::cin.ignore(1, '\n');

    Lista<std::string> *lista = new Lista<std::string>;
    for(int i = 0; i < n; i++)
    {
        std::string string;
        std::getline(std::cin, string);
        lista->upis(string);
    }

    lista->ispis();

    delete lista;

    return 0;
  }
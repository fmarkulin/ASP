#include <iostream>

template <class T>
class List
{
    template <class X>
    struct Cvor
    {
        X data;
        Cvor<X> *next;
    };

    Cvor<T> *head = nullptr;

public:
    bool upis(T data)
    {
        Cvor<T> *newElement = new (std::nothrow) Cvor<T>;
        if (!newElement)
            return false;
        newElement->data = data;
        newElement->next = nullptr;
        Cvor<T> **p = &head;
        while ((*p))
        {
            if ((**p).data < data)
                p = &((*p)->next);
            else
                break;
        }

        newElement->next = *p;
        *p = newElement;
        return true;
    }

    void ispis()
    {
        Cvor<T> **p = &head;
        while (*p)
        {
            std::cout << (*p)->data << " ";
            p = &((*p)->next);
        }
        return;
    }
};

int main(void)
{
    int n;
    std::cout << "Upišite željeni broj elemenata za upis: ";
    std::cin >> n;

    List<int> *lista = new List<int>;

    for(int i = 0; i < n; i++)
    {
        int element;
        std::cout << "Upišite " << i + 1 << ". element: ";
        std::cin >> element;
        lista->upis(element);
    }

    std::cout << "Ispis elemenata liste: ";
    lista->ispis();

    delete lista;

    return 0;
}
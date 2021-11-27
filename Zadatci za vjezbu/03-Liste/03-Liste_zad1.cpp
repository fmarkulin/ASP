#include <iostream>

template <typename T>
struct ListElement
{
    T data;
    ListElement<T> *next;
};
template <typename T>
class ListIterator
{
private:
    ListElement<T> *ptr = nullptr;

public:
    ListIterator<T>() : ptr(nullptr) {}
    ListIterator<T>(ListElement<T> *ptr) : ptr(ptr) {}
    ListIterator<T> &operator++();   // prefix ++
    ListIterator<T> operator++(int); // postfix ++
    bool operator!=(const ListIterator<T> &other) { return ptr != other.ptr; }
    T &operator*() { return ptr->data; }
};
template <typename T>
class List
{
    ListElement<T> *head = nullptr;

public:
    typedef ListIterator<T> iterator;
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(); }
    bool insert(T data);       // dodavanje na početak liste
    bool append(T data);       // dodavanje na kraj liste
    bool insertSorted(T data); // umetanje po sortiranom redoslijedu
    bool remove(T data);
    void print();

    T& at(int k)
    {
        List<int>::iterator it;
        int i;
        for(i = 0, it = this->begin(); i < k && it != this->end(); i++, it++);
        if (k >= 0 && it != this->end())
            return *it;
        else
            throw std::runtime_error("Index out of bounds");
    }
};

int main(void)
{
    List<int> l;
    l.append(4);
    l.append(5);
    l.insert(1);
    l.insert(2);
    l.insert(3);
    //3 2 1 4 5

    int p = l.at(3);
    std::cout << p << std::endl;
    return 0;
}
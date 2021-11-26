#include <iostream>

template <class T>
class Queue
{
private:
    template <class X> struct QueueElement
    {
        T data;
        QueueElement<X> *next;
    };
    QueueElement<T> *read = nullptr;
    QueueElement<T> *write = nullptr;

public:
    bool enqueue(T data)
    {
        QueueElement<T> *newElement = new (nothrow) QueueElement<T>;
        if (newElement == nullptr)
            return false;

        newElement->next = nullptr;
        newElement->data = data;

        if (write == nullptr)
        {
            read = newElement;
        }
        else
        {
            write->next = newElement;
        }
        write = newElement;
        return true;
    }

    bool dequeue(T &data)
    {
        if (read == nullptr)
            return false;
        data = read->data;
        QueueElement<T> *tmp = read;
        read = read->next;
        if(read == nullptr)
        {
            write = nullptr;
        }
        delete tmp;
        return true;
    }

    template <class T> Queue<T> *split(Queue<T> *q)
    {
        Queue<T> *retQueue = new Queue<T>();
        Queue<T> *tempQueue = new Queue<T>();

        T deqEl;
        int i = 1;
        
        while(q->dequeue(deqEl))
        {
            if(i % 2 == 1)
            {
                retQueue->enqueue(deqEl);
            }
            else
            {
                tempQueue->enqueue(deqEl);
            }
            i++;
        }

        while(tempQueue->dequeue(deqEl))
        {
            q->enqueue(deqEl);
        }

        return retQueue;
    }
};
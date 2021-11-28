template <class T>
bool peek(T &item)
{
    Queue<T> tmp;
    T tmpEl;
    int i = 0;
    while (this->dequeue(tmpEl))
    {
        tmp.enqueue(tmpEl);
        i++;
    }
    if (i > 0)
    {
        item = tmpEl;
        while (tmp.dequeue(tmpEl))
        {
            this->enqueue(tmpEl);
        }
        return true;
    }
    
    return false;
}
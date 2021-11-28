template <class T>
bool peek(int &el, int index)
{
    Queue<T> tmp;
    T tmpEl;
    int i = 0;
    bool found = false;
    while(this->dequeue(tmpEl))
    {
        tmp.enqueue(tmpEl)
        if(i == index)
        {
            found = true;
            el = tmpEl;
            break;
        }
        i++;
    }

    while(tmp.dequeue(tmpEl))
    {
        this->enqueue(tmpEl);
    }

    return found;
}
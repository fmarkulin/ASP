template <class T>
bool peek(int &el, int index)
{
    int i = 0;
    Stack<T> temp;
    while (this->pop(el))
    {
        temp.push(el);
        if (i == index)
            break;
        i++;
    }
    T tmpEl;
    while (temp.pop(tmpEl))
    {
        this->push(tmpEl);
    }
    if (i == index)
    {
        return true;
    }
    else
    {
        return false;
    }
}
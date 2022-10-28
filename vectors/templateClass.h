template<typename T>
class Vector
{
private:
    int cs;
    int ms;
    T *arr;
public:
    Vector()
    {
        cs = 0;
        ms = 1;
        arr = new T[ms];
    }
    void push_back(const T data)
    {
        if(cs == ms)
        {
            T *oldarr = arr;
            arr = new T[2*ms];
            ms = 2*ms;
            for(int i=0; i<cs; i++)
            {
                arr[i] = oldarr[i];
            }
            delete [] oldarr;
        }
        arr[cs] = data;
        cs++;
    }
    void pop_back()
    {
        cs--;
    }
    T front()
    {
        return arr[0];
    }
    T back()
    {
        return arr[cs-1];
    }
    bool empty()
    {
        return cs==1;
    }
    int capacity()
    {
        return ms;
    }
    int size()
    {
        return cs;
    }
    T operator[](const int i)
    {
        return arr[i];
    }
};
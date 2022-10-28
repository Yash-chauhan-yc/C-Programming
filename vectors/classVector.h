class Vector
{
private:
    int cs;
    int ms;
    int *arr;
public:
    Vector()
    {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }
    void push_back(const int data)
    {
        if(cs == ms)
        {
            int *oldarr = arr;
            arr = new int[2*ms];
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
    int front()
    {
        return arr[0];
    }
    int back()
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
    int operator[](const int i)
    {
        return arr[i];
    }
};
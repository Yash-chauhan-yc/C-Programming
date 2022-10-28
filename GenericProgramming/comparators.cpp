#include<iostream>
#include<list>
using namespace std;
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while(start!=end)
    {
        if(cmp(*start,key))
        {
            return start;
        }
        start++;
    }
    return end;
}
class Book{
    public:
        string name;
        int price;

        Book(){

        }
        Book(string name, int price)
        {
            this->name = name;
            this->price = price;
        }
};
class BookCompare{
    public : 
        bool operator()(Book A, Book B)
        {
            if(A.name == B.name)
            {
                return true;
            }
        return false;
        }
};
int main()
{
    Book b1("C++", 100);
    Book b2("Java", 110);
    Book b3("python", 130);
     
    list<Book> B;
    B.push_back(b1);
    B.push_back(b2);
    B.push_back(b3);

    Book bookToFind("C++", 100);
    BookCompare cmp;

    auto it = search(B.begin(), B.end(), bookToFind, cmp);
    if(it!=B.end())
    cout << "Book Found";
    else 
    cout << "not found";
    return 0;
}
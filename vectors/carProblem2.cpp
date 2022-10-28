#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Car
{
    public:
        string car_name;
        int x,y;

    Car(){

    }
    Car(string name, int x, int y)
    {
        car_name = name;
        this->x = x;
        this->y= y;
    }
    int distance()
    {
        return x*x + y*y;
    }
};
bool compare(Car A, Car B)
{
    int da = A.distance();
    int db = B.distance();
    if(da == db)
    {
        return A.car_name < B.car_name;
    }
    return da < db;
}
int main()
{
    int n; 
    cin >> n;
    vector<Car> v;
    for(int i=0; i<n; i++)
    {
        int x, y;
        string name;
        cin >> name;
        cin >> x >> y;
        Car c(name, x, y);
        v.push_back(c);
    }

    sort(v.begin(), v.end(), compare);
    for(auto x:v)
    {
        cout << "Car " << x.car_name << " at distance " << x.distance() << "at location : " << x.x << ", " << x.y << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dis const()
    {
        return x * x + y * y;
    }
};
class Compare
{
public:
    bool operator()(const Car A, const Car B)
    {
        return A.dist() < B.dist();
    }
};
void printNearestCars(vector<Car> cars, int k)
{
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);
    for (int i = k; i < cars.size(); i++)
    {
        auto car = cars[i];
        if (car.dist() < max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(car);
        }
    }
    vector<Car> op;
    while (!max_heap.empty())
    {
        op.push_back(max_heap.top());
        // cout << max/_heap.top().id << endl;
        max_heap.pop();
    }
    reverse(op.begin(),op.end());
    for(auto car : op) {
        cout<<car.id<<endl;
    }
    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    string id;
    int x, y;
    vector<Car> cars;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }
    printNearestCars(cars, k);
    return 0;
}
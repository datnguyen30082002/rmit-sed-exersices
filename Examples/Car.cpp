#include <iostream>
using namespace std;
class car {
    public:
        int speed = 100; //default value is 100
        int add_speed(int num);
};

int car::add_speed(int num) {
    speed += num;
    return speed;
}

int main() {
    car my_car; // Create an object of Car
    
    cout << "my_car's new speed: " << my_car.add_speed(200);

    return 0;
}

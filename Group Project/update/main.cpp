#include "Header.h"
#include "House.h"
#include "User.h"

int main()
{
    vector<User*> users = {
        new (std::nothrow) User("user1", "User 1", "0823248508", 500),
        new (std::nothrow) User("user2", "User 2", "0855764200", 500),
        new (std::nothrow) User("user3", "User 3", "0955764201", 500) };

    showUsersInfo(users, true);

    vector<House*> houses = {
        new (std::nothrow) House("HCM", "Nice"),
        new (std::nothrow) House("Ha Noi", "Good"),
        new (std::nothrow) House("Hue", "Beautiful") };

    // showHouseInfo(houses, false);



	return 0;
}
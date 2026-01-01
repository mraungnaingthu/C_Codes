//
// Created by Aung Naing Thu on 12/28/2025.
//

#include <iostream>

using namespace std;

class mobilePhone
{
    private:
    string password;

    public:
    string name;
    double price;
    mobilePhone(string name, double price)
    {
        this->name = name;
        this->price = price;
    }

    void setPassword(string newPassword)
    {
        ;if (newPassword.length() >= 8)
        {
            this->password = newPassword;
        }
        else
        {
            cout << "Please set the password at least 8 digits!" << endl;
        }
    }
    string getPassword()
    {
        return password;
    }

    void display()
    {
        cout << name << " " << price << " " << password << endl;
    }
};

int main()
{
    mobilePhone mobile("Redmi", 900000);
    mobile.setPassword("Welcome@123");
    mobile.display();



    return 0;
}
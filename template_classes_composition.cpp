##custome.h file
#include<iostream>
using namespace std;
#include<string>
template<class T>
class Customer 
{
    private:
        T name;
    public:
        Customer (){}
        Customer(T name) {
            this->name=name;
            //this->address=address;
        }
        T getName(){
            return this->name;

        }

};

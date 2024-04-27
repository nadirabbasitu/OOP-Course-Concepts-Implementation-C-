//customer.h file
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

//order.h file
template<class U>
class Order 
{
    private:
        Customer<U> customer; // composition
    public:
        Order(){}
        void placeOrder(Customer<U> customer){
            this->customer = customer;   
        }
        void displayOrderDetails(){
        cout << "Customer: " << customer.getName() <<endl;
        }
};
//main.cpp file

int main() {
    // Create customer
    Customer<string> customer("Ateeq Ahmed");
    Order<string> order;
    order.placeOrder(customer);
    order.displayOrderDetails();
    return 0;
}



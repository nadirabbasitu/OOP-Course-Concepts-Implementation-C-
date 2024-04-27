//customer.h file
#include<iostream>
#include<vector>
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
class Order {
private:
    std::vector<Customer<U>*> customers; // vector of pointers to customers
public:
    Order() {}
    void placeOrder(Customer<U>* customerPtr) {
        customers.push_back(customerPtr);   
    }
    void displayOrderDetails() {
        for (const auto& customerPtr : customers) {
            cout << "Customer: " << customerPtr->getName() << endl;
        }
    }
};

//main.cpp file

int main() {
    // Create customers
    Customer<string>* customer1 = new Customer<string>("Ateeq Ahmed");
    Customer<string>* customer2 = new Customer<string>("John Doe");

    // Create an order
    Order<string> order;

    // Place orders
    order.placeOrder(customer1);
    order.placeOrder(customer2);

    // Display order details
    order.displayOrderDetails();

    // Don't forget to deallocate memory
    delete customer1;
    delete customer2;

    return 0;
}



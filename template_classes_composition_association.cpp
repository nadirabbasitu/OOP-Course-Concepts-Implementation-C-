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

//product.h file
template <class X,class Y>
class Product 
{
    private:
        X name;
        Y price;
    public:
        Product(){};
        Product(X name,Y price){
            this->name=name;
            this->price=price;
        }
        X getName(){
            return this->name;
        }
        Y getPrice(){
            return this->price;
        }

};

//shopping_cart.h
template<class P,class Q>
class ShoppingCart 
{
    private:
        vector<Product<P,Q>> items; //composition
    public:
        ShoppingCart(){}
        void addItem(Product<P,Q> product){
            items.push_back(product);
        }
        vector<Product<P,Q>> getItems(){
            return items;
        }

};

//order.h file
template<class U,class N>
class Order 
{
    private:
        vector<Product<U,N>> items; //composition
        Customer<U> customer; // composition
    public:
        Order(){}
        void placeOrder(Customer<U> customer, vector<Product<U,N>> items){
            this->customer = customer;
            this->items = items;   
        }
        void displayOrderDetails(){
        cout << "Customer: " << customer.getName() <<endl;
        cout<<"Customer Ordered Products:"<<endl;
        for (auto& item : this->items) 
    {
        cout << "Product Name:  " << item.getName();
        cout << " ->Product Price:  " << item.getPrice() << endl; // Printing the value of the first element of each pair

    }
        }
};

//main.cpp file

int main() {
    // Create customer
    // Can input customer name for dynamic/generic code
    Customer<string> customer("Ateeq Ahmed");
    // Can input product details for dynamic/generic code
    Product<string, double> p1("Laptop", 1000.0);
    Product<string, double> p2("Smartphone", 800.0);
    // Create shopping cart
    ShoppingCart<string, double> cart;

    // Add products to the shopping cart
    cart.addItem(p1);
    cart.addItem(p2);

    Order<string, double> order;
    order.placeOrder(customer, cart.getItems());
    order.displayOrderDetails();
    return 0;
}

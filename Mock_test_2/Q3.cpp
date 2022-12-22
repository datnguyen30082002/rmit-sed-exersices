#include <iostream>
#include <string>
#include <vector>
using namespace std;

const float DISCOUNT_RATE = 0.05;

class Product
{
private:
    string name;
    int price;

public:
    Product(string name = "", int price = 0) : name(name), price(price) {}

    void setProductName(string name)
    {
        this->name = name;
    }

    string getProductName()
    {
        return this->name;
    }

    void setProductPrice(int price)
    {
        this->price = price;
    }

    int getProductPrice()
    {
        return this->price;
    }

    void showProductInfo()
    {
        cout << "----Name: " << name << ", Unit: " << price << endl;
    }

    bool operator==(Product &product)
    {
        if (this->name == product.name && this->price == product.price)
            return true;
        return false;
    }

    friend class Order;
    friend class Account;
};

class Shop
{
private:
    string name;
    vector<Product> products;

public:
    Shop(string name = "", vector<Product> products = {}) : name(name), products(products) {}

    void setShopName(string name)
    {
        this->name = name;
    }

    string getShopName()
    {
        return this->name;
    }

    void setProducts(vector<Product> productOfShop)
    {
        this->products = productOfShop;
    }

    vector<Product> getProducts()
    {
        return this->products;
    }

    void showShopInfo()
    {
        cout << endl
             << "Shop's name: " << name;
    }

    void showShopInfoIncludeProducts()
    {
        cout << "> Shop's name: " << name << endl;
        for (auto pro : products)
        {
            pro.showProductInfo();
        }
    }
};

class Order
{
private:
    int orderId;
    vector<Product> orders;
    float totalExpense;

public:
    Order(int orderId = 0, vector<Product> orders = {}, float totalExpense = 0) : orderId(orderId), orders(orders), totalExpense(totalExpense){};

    void setOrderId(int orderId)
    {
        this->orderId = orderId;
    }

    int getOrderId()
    {
        return this->orderId;
    }

    void setOrders(vector<Product> orders)
    {
        this->orders = orders;
    }

    vector<Product> getOrders()
    {
        return this->orders;
    }

    void setOrderExpense(float totalExpense)
    {
        this->totalExpense = totalExpense;
    }

    int getOrderExpense()
    {
        return this->totalExpense;
    }

    void showOrderInfo()
    {
        cout << "Order's ID: " << orderId << endl;
        cout << "------ Order ----------" << endl;
        for (auto order : orders)
        {
            cout << "Product's name: " << order.getProductName() << ", price: " << order.getProductPrice() << endl;
        }
        cout << "\t Total expense: " << totalExpense << endl;
    }

    friend class Account;
};

class Account
{
private:
    string name;
    vector<Order> orders;
    bool accountType = false;

public:
    Account(string name = "", vector<Order> orders = {}, bool accountType = false) : name(name), orders(orders), accountType(accountType) {}

    void setAccountName(string name)
    {
        this->name = name;
    }

    string getAccountName()
    {
        return this->name;
    }

    void setOrder(vector<Order> orders)
    {
        this->orders = orders;
    }

    vector<Order> getOrder()
    {
        return this->orders;
    }

    void buyProduct(vector<Product> products)
    {
        int totalPrice = 0;
        int payPrice = 0;

        for (auto product : products)
        {
            totalPrice += product.getProductPrice();
        }

        payPrice = (accountType == true) ? totalPrice - totalPrice * DISCOUNT_RATE : totalPrice;

        this->orders.push_back(Order(orders.size() + 1, products, payPrice));
    }

    void returnProduct(int orderId, vector<Product> products)
    {
        cout << "------ return ----------" << endl;
        for (int i = 0; i < this->orders.size(); i++) // Scan the order
        {
            if (orderId == this->orders[i].orderId) // Check order ID
            {
                for (int j = 0; j < this->orders[i].orders.size(); j++)
                {
                    if (products[0] == this->orders[i].orders[j])
                    if (this->orders[i].orders[j] == this->orders[j].orders[j])
                    {
                        if (accountType == true)
                        {
                            int discountPrice = this->orders[i].orders[j].getProductPrice() - (this->orders[i].orders[j].getProductPrice() * DISCOUNT_RATE);
                            this->orders[i].totalExpense -= discountPrice;
                        }
                        else
                        {
                            this->orders[i].totalExpense -= this->orders[i].orders[j].getProductPrice();
                        }

                        this->orders[i].orders.erase(this->orders[i].orders.begin() + j);
                    }
                }
            }
        }

        cout << "\n Here is the result after removing products \n";

        for (auto order : this->orders) // Scan the order
        {
            if (orderId == order.getOrderId()) // Check order ID
            {
                order.showOrderInfo();
            }
        }
    }

    void showAccountInfo()
    {
        cout << "Account's name: " << name << endl;
        cout << "------ Order ----------" << endl;
        for (auto order : orders)
        {
            order.showOrderInfo();
        }
    }
};

int main()
{
    // Initialize products
    Product product1("product 1", 100);
    Product product2("product 2", 200);
    Product product3("product 3", 100);
    Product product4("product 4", 200);
    Product product5("product 5", 100);
    Product product6("product 6", 200);
    Product product7("product 7", 100);
    Product product8("product 8", 200);
    Product product9("product 9", 100);
    Product product10("product 10", 200);
    Product product11("product 11", 100);
    Product product12("product 12", 200);

    // // Initialize shops
    // vector<Product> productsOfShop1 = {product1, product2, product3, product4, product5};
    // Shop shop1("Shop 1", productsOfShop1);
    // shop1.showShopInfoIncludeProducts();

    // Initialize accounts
    vector<Product> list1 = {product1, product2, product3};
    Account acc1("acc 1", {}, true);
    //acc1.buyProduct({product1, product2, product3});
    //acc1.buyProduct({product2, product3, product4});
    // acc1.buyProduct({product6, product7, product8});
    // acc1.showAccountInfo();
    // acc1.returnProduct(1, {product2});

    Account acc2("acc 2", {}, false);
    acc2.buyProduct({ product8, product9, product10 });
    acc2.showAccountInfo();
    acc2.returnProduct(1, { product8 });
}

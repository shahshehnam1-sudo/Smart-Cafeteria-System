#include <iostream>
#include <string>
using namespace std;

class MenuItem
{
private:
    int id;
    string name;
    double price;

public:
    MenuItem(int i, string n, double p)
    {
        id = i;
        name = n;
        price = p;
    }

    void display()
    {
        cout << id << ". " << name << " - Rs." << price << endl;
    }

    double getPrice()
    {
        return price;
    }

    string getName()
    {
        return name;
    }
};

class Order
{
private:
    string itemName;
    int quantity;
    double total;

public:
    Order(string n, int q, double p)
    {
        itemName = n;
        quantity = q;
        total = q * p;
    }

    double getTotal()
    {
        return total;
    }

    void showOrder()
    {
        cout << itemName << " x " << quantity << " = Rs." << total << endl;
    }
};

class Billing
{
public:
    static void generateBill(Order orders[], int count)
    {
        double grandTotal = 0;

        cout << "\n----- Receipt -----\n";

        for(int i = 0; i < count; i++)
        {
            orders[i].showOrder();
            grandTotal += orders[i].getTotal();
        }

        if(grandTotal > 1000)
        {
            cout << "Discount Applied: 10%\n";
            grandTotal = grandTotal - (grandTotal * 0.10);
        }

        cout << "Final Bill: Rs." << grandTotal << endl;
    }
};

int main()
{
    MenuItem menu[4] = {
        MenuItem(1, "Burger", 250),
        MenuItem(2, "Pizza", 500),
        MenuItem(3, "Fries", 150),
        MenuItem(4, "Drink", 100)
    };

    cout << "===== Cafeteria Menu =====\n";
    for(int i = 0; i < 4; i++)
    {
        menu[i].display();
    }

    int n;
    cout << "\nHow many items do you want to order? ";
    cin >> n;

    Order orders[10] = {
        Order("",0,0),Order("",0,0),Order("",0,0),Order("",0,0),Order("",0,0),
        Order("",0,0),Order("",0,0),Order("",0,0),Order("",0,0),Order("",0,0)
    };

    for(int i = 0; i < n; i++)
    {
        int choice, qty;

        cout << "\nEnter item number: ";
        cin >> choice;

        cout << "Enter quantity: ";
        cin >> qty;

        orders[i] = Order(
            menu[choice-1].getName(),
            qty,
            menu[choice-1].getPrice()
        );
    }

    Billing::generateBill(orders, n);

    return 0;
}
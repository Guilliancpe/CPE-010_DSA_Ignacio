#include <iostream>
#include <string>

class GroceryItemList
{
private:
    std::string Name;
    double Amount;
    int Total;

public:
   

    virtual ~GroceryItemList() {}


    GroceryItemList(const GroceryItemList &other)
    {
        Name = other.Name;
        Amount = other.Amount;
        Total = other.Total;
    }

    GroceryItemList &operator=(const GroceryItemList &other)
    {
        if (this != &other)
        {
            this->Name = other.Name;
            this->Amount = other.Amount;
            this->Total = other.Total;
        }
        return *this;
    }
    
     GroceryItemList(std::string n = "", double a = 0, int t = 0)
    {
        Name = n;
        Amount = a;
        Total = t;
    }

    virtual std::string getC() = 0;

 
    double calculateSum() const
    {
        return Amount * Total;
    }

 
    void display()
    {
        std::cout << "Type: " << getC() << std::endl;
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Price: PHP " << Amount << std::endl;
        std::cout << "Total Quantity: " << Total << std::endl;
        std::cout << "Item Total: PHP " << calculateSum() << std::endl;
    }
};



double TotalAmount(GroceryItemList *list[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        if (list[i] != nullptr)
        {
            total += list[i]->calculateSum();
        }
    }

    return total;
}


class Vegetable : public GroceryItemList
{
public:
    Vegetable(std::string n = " ", double a = 0.0, int t = 0)
        : GroceryItemList(n, a, t) {}

    ~Vegetable() {}

    Vegetable(const Vegetable &other)
        : GroceryItemList(other) {}

    Vegetable &operator=(const Vegetable &other)
    {
        GroceryItemList::operator=(other);
        return *this;
    }

    std::string getC()
    {
        return "Vegetable";
    }
};


class Fruits : public GroceryItemList
{
public:
    Fruits(std::string n = " ", double a = 0.0, int t= 0)
        : GroceryItemList(n, a, t) {}

    ~Fruits() {}

    Fruits(const Fruits &other)
        : GroceryItemList(other) {}

    Fruits &operator=(const Fruits &other)
    {
        GroceryItemList::operator=(other);
        return *this;
    }

    std::string getC()
    {
        return "Fruit";
    }
};


int main()
{
    const int Array_size = 4;

    
    GroceryItemList *GroceryList[Array_size];

    GroceryList[0] = new Fruits("Apple", 10, 7);
    GroceryList[1] = new Fruits("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

 
    std::cout << "JENNA'S GROCERY \n";
    std::cout << "--------------------------\n\n";
    for (int i = 0; i < Array_size; i++)
    {
        GroceryList[i]->display();
        std::cout << "--------------------------\n";
    }


    std::cout << "\nAmount to Pay: PHP "
              << TotalAmount(GroceryList, Array_size)
              << std::endl;


    std::cout << "\nDeleted lettuce\n";

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    std::cout << "Total Amount: PHP "
              << TotalAmount(GroceryList, Array_size)
              << std::endl;

    for (int i = 0; i < Array_size; i++)
    {
        delete GroceryList[i];
        GroceryList[i] = nullptr;
    }

    return 0;
}

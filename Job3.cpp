#include <iostream>


struct Product
{
    unsigned int id{};
    std::string name{};
    double price{};

    Product(unsigned int id, std::string name, double price) : id(id), name(name), price(price)
    {}

    Product operator = (const Product& p1)
    {
        if (&p1 == this)
            return *this;
        return Product(this->id = p1.id, this->name = p1.name, this->price = p1.price);
    }

    Product operator + (double price)
    {
        return Product(this->id, this->name, this->price+price);
    }

    Product operator - (double price)
    {
        return Product(this->id, this->name, this->price - price);
    }

    bool operator < (const Product& p1)
    {
        return this->price < p1.price;
    }

    bool operator <= (const Product& p1)
    {
        return this->price <= p1.price;
    }

    bool operator > (const Product& p1)
    {
        return this->price > p1.price;
    }

    bool operator >= (const Product& p1)
    {
        return this->price >= p1.price;
    }

    bool operator == (const Product& p1)
    {
        if (this->price == p1.price)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введите товар: \n";
    std::cout << "ID товара: ";
    unsigned int id;
    std::cin >> id;
    std::cout << "Наименование товара: ";
    std::string str;
    std::cin >> str;
    std::cout << "Цена товара: ";
    double price;
    std::cin >> price;
    Product product(id, str, price);
    Product product2(id, str, price);
    std::cout << "Введите надбавку к цене: ";
    std::cin >> price;
    std::cout << "Тесты:\n";
    product2 = product - price;
    std::cout << "Цена - Надбавка = " << product2.price << std::endl;
    product2 = product + price;
    std::cout << "Цена + Надбавка = " << product2.price << std::endl;
    std::cout << "Цена(без надбавкой) < Цены(с надбавкой) = " << (product < product2) << std::endl;
    std::cout << "Цена(без надбавкой) > Цены(с надбавкой) = " << (product > product2) << std::endl;
    std::cout << "Цена(без надбавкой) = Цены(с надбавкой) = " << (product == product2) << std::endl;
}


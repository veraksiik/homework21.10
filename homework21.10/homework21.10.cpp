#include <iostream>
#include <string>
#include <vector>

class Plant {
protected:
    std::string name_;
    std::string size_; 
    int height_; 

public:
    Plant(std::string name, std::string size, int height)
        : name_(name), size_(size), height_(height) {}

    virtual ~Plant() {} 

    virtual void display() const {
        std::cout << name_ << " (Size: " << size_ << ", Height: " << height_ << " cm)" << std::endl;
    }
};

class Bush : public Plant {
private:
    int fruitQuantity_; 

public:
    Bush(std::string name, int height, int fruitQuantity)
        : Plant(name, "small", height), fruitQuantity_(fruitQuantity) {}

    std::vector<std::string> harvest() {
        std::vector<std::string> berries;
        for (int i = 0; i < fruitQuantity_; i++) {
            berries.push_back(name_ + " Berry " + std::to_string(i + 1));
        }
        return berries;
    }

    void display() const override {
        Plant::display();
        std::cout << "Fruit Quantity: " << fruitQuantity_ << std::endl;
    }
};

class Tree : public Plant {
private:
    int fruitQuantity_; 

public:
    Tree(std::string name, int height, int fruitQuantity)
        : Plant(name, "big", height), fruitQuantity_(fruitQuantity) {}

    std::vector<std::string> harvest() {
        std::vector<std::string> fruits;
        for (int i = 0; i < fruitQuantity_; i++) {
            fruits.push_back(name_ + " Fruit " + std::to_string(i + 1));
        }
        return fruits;
    }

    void display() const override {
        Plant::display();
        std::cout << "Fruit Quantity: " << fruitQuantity_ << std::endl;
    }
};

class Fruit {
protected:
    std::string name_;
    double weight_;

public:
    Fruit(std::string name, double weight) : name_(name), weight_(weight) {}

    virtual ~Fruit() {}

    virtual void display() const {
        std::cout << name_ << " (Weight: " << weight_ << " grams)" << std::endl;
    }
};

class Berry : public Fruit {
public:
    Berry(std::string name, double weight) : Fruit(name, weight) {}

    void display() const override {
        std::cout << "Berry: ";
        Fruit::display();
    }
};

class Cone : public Fruit {
public:
    Cone(std::string name, double weight) : Fruit(name, weight) {}

    void display() const override {
        std::cout << "Cone: ";
        Fruit::display();
    }
};

int main() {
    Bush blueberryBush("Blueberry bush", 100, 5);
    Tree appleTree("Apple tree", 250, 10);

    std::cout << "Bush info:" << std::endl;
    blueberryBush.display();
    std::cout << "Harvested berries:" << std::endl;

    std::vector<std::string> harvestedBerries = blueberryBush.harvest();
    for (const auto& berry : harvestedBerries) {
        std::cout << berry << std::endl;
    }

    std::cout << "\nTree info:" << std::endl;
    appleTree.display();
    std::cout << "Harvested fruits:" << std::endl;

    std::vector<std::string> harvestedFruits = appleTree.harvest();
    for (const auto& fruit : harvestedFruits) {
        std::cout << fruit << std::endl;
    }


    system("pause");
    return 0;
}


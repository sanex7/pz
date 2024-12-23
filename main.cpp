#include <iostream>
#include <cmath>
#include <cstdio>
#include <c:/Users/Admin/VSCODE/pz/pz/string.h>

//Task 1
class Shape {
protected:
    double side_length;

public:
    Shape(double side) : side_length(side) {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Square : virtual public Shape {
public:
    Square(double side) : Shape(side) {}

    double area() const override {
        return side_length * side_length;
    }

    double perimeter() const override {
        return 4 * side_length;
    }
};

class Circle : virtual public Shape {
protected:
    double radius;

public:
    Circle(double r) : Shape(r * 2), radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

class InscribedCircle : public Square, public Circle {
public:
    InscribedCircle(double side)
        : Shape(side), Square(side), Circle(side / 2) {}

    void description() const {
        std::cout << "A circle inscribed in a square with side length " << side_length
            << ". Radius of the circle: " << radius << ".\n";
    }
};

//Task 2
class Vehicle {
protected:
    std::string vehicle_type;

public:
    Vehicle() : vehicle_type("Vehicle") {}

    virtual std::string description() const {
        return "General Vehicle Description.";
    }
};

class Wheels : virtual public Vehicle {
protected:
    int number_of_wheels;

public:
    Wheels(int wheels) : number_of_wheels(wheels) {}

    std::string description() const override {
        char buffer[50];
        sprintf(buffer, "Number of wheels: %d.", number_of_wheels);
        return std::string(buffer);
    }
};

class Engine : virtual public Vehicle {
protected:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    std::string description() const override {
        char buffer[50];
        sprintf(buffer, "Engine horsepower: %d hp.", horsepower);
        return std::string(buffer);
    }
};

class Doors : virtual public Vehicle {
protected:
    int number_of_doors;

public:
    Doors(int doors) : number_of_doors(doors) {}

    std::string description() const override {
        char buffer[50];
        sprintf(buffer, "Number of doors: %d.", number_of_doors);
        return std::string(buffer);
    }
};

class Car : public Wheels, public Engine, public Doors {
public:
    Car(int wheels, int hp, int doors)
        : Vehicle(), Wheels(wheels), Engine(hp), Doors(doors) {
        vehicle_type = "Car";
    }

    void full_description() const {
        std::cout << "Car Description:\n";
        std::cout << Wheels::description() << "\n";
        std::cout << Engine::description() << "\n";
        std::cout << Doors::description() << "\n";
    }
};

int main() {
    //Task 1
    std::cout << "Task 1: InscribedCircle\n";
    InscribedCircle shape(8);
    shape.description();
    std::cout << "Square area: " << shape.Square::area() << "\n";
    std::cout << "Circle area: " << shape.Circle::area() << "\n\n";

    //Task 2
    std::cout << "Task 2: Car\n";
    Car car(4, 150, 4);
    car.full_description();

    return 0;
}
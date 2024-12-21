// Task 1
#include <iostream>
#include <cmath>
#include <C:\Users\Admin\VSCODE\pz\pz\string.h>

class Square {
protected:
    double side_length;

public:
    Square(double side) : side_length(side) {}

    double area() const {
        return side_length * side_length;
    }

    double perimeter() const {
        return 4 * side_length;
    }
};

class Circle {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const {
        return 3.14 * radius * radius;
    }

    double circumference() const {
        return 2 * 3.14 * radius;
    }
};

class InscribedCircle : public Square, public Circle {
public:
    InscribedCircle(double side) : Square(side), Circle(side / 2) {}

    void description() const {
        std::cout << "A circle inscribed in a square with side length " << side_length
            << ". Radius of the circle: " << radius << ".\n";
    }
};

// Task 2: Car
class Wheels {
protected:
    int number_of_wheels;

public:
    Wheels(int wheels) : number_of_wheels(wheels) {}

    String<> description() const {
        String<> result(50);
        result = "Number of wheels: ";
        char buffer[10];
        sprintf(buffer, "%d", number_of_wheels);
        result += String<>(buffer);
        result += ".";
        return result;
    }
};

class Engine {
protected:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    String<> description() const {
        String<> result(50);
        result = "Engine horsepower: ";
        char buffer[10];
        sprintf(buffer, "%d", horsepower);
        result += String<>(buffer);
        result += " hp.";
        return result;
    }
};

class Doors {
protected:
    int number_of_doors;

public:
    Doors(int doors) : number_of_doors(doors) {}

    String<> description() const {
        String<> result(50);
        result = "Number of doors: ";
        char buffer[10];
        sprintf(buffer, "%d", number_of_doors);
        result += String<>(buffer);
        result += ".";
        return result;
    }
};

class Car : public Wheels, public Engine, public Doors {
public:
    Car(int wheels, int hp, int doors)
        : Wheels(wheels), Engine(hp), Doors(doors) {}

    void full_description() const {
        std::cout << "Car:\n"
            << Wheels::description() << "\n"
            << Engine::description() << "\n"
            << Doors::description() << "\n";
    }
};

int main() {
    // Task 1
    InscribedCircle shape(8);
    shape.description();
    std::cout << "Square area: " << shape.Square::area() << "\n";
    std::cout << "Circle area: " << shape.Circle::area() << "\n";

    // Task 2
    Car car(4, 150, 4);
    car.full_description();

    return 0;
}
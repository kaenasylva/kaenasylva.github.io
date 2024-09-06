#include <iostream>
#include <cmath>

/**
 * This program uses a class hierarchy, defined by abstract class Shape,
 * and concrete classes pertaining to various shapes (i.e. Circle, Sphere
 * Cylinder, Square, Cube, Triangle and Tetrahedron).
 *
 * This program takes a user input (numbered one through six) to pick a
 * shape, then takes another input (side, radius or height) depending
 * on the previous input, and calculates area, surface area, and/or volume.
 *
 * @author     Sylva, Kaenaokalani
 * @assignment ICS 212 Assignment 24
 * @date       5 December 2023
 */

#define NUM 7
#define MY_PI 3.14

using namespace std;

class Shape {
  public:
    /** Returns the name of the class. */
    virtual const char* name() const = 0;
    /** Prints the area or surface area, and volume of the object. */
    virtual void printDetails() const = 0;
    /**
     * Prompts the user to enter a radius, side, and/or height
     * of the object and set the appropriate data member(s).
     */
    virtual void inputData() = 0;
    /** Calculates and returns the area or surface area of the object. */
    virtual double area() const = 0;
    /** Calculates and returns the volume of the object. */
    virtual double volume() const {
      return 0.0;
    }     
};   

class Circle : public Shape {
  public:
    // Parameter syntax "datatype variable = value" will give
    // a default value for the variable if one is not supplied as an argument.
    // This constructor can be called with no arguments or one argument
    // Example: shapeArray[0] = new Circle(); 
    // Example: Circle circle1 = new Circle(10);
    Circle (double radiusParam = 1) {
      radius = radiusParam;
    }
    
    const char* name() const {
      return "Circle";
    }
  
    void printDetails() const {
      cout << "The " << name() << "'s area = " << area() << endl;
    } 
    
    void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
    }
    
    double area() const {
      return MY_PI * radius * radius;
    }
   
  protected:    
    double radius;
};


/** Add the remaining classes here. */
// Sphere
class Sphere : public Circle {
public:
  Sphere(double r = 0.0): Circle(r) {
    radius = r;
  }

  const char* name() const {
    return "Sphere";
  }
  
  void printDetails() const {
    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;
  }

  void inputData() {
    cout << "Enter the " << name() << "'s radius: ";
    cin >> radius;
  }

  double area() const {
    return 4 * MY_PI * radius * radius;
  }

  double volume() const {
    return (4 * MY_PI * radius * radius * radius) / 3;
  }

protected:
};
// Cylinder
class Cylinder : public Circle {
public:
  Cylinder(double r = 0.0, double h = 0.0) : Circle(r) {
    radius = r;
    height = h;
  }

  const char* name() const {
    return "Cylinder";
  }

  void printDetails() const {
    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;
  }

  void inputData() {
    cout << "Enter the " << name() << "'s radius: ";
    cin >> radius;
    cout << "Enter the " << name() << "'s height: ";
    cin >> height;
  }

  double area() const {
    return (2 * MY_PI * radius * height) + (2 * MY_PI * radius * radius);
  }

  double volume() const {
    return MY_PI * radius * radius * height;
  }

protected:
  double height;
};
// Square
class Square : public Shape {
public:
  Square(double s = 0.0) {
    side = s;
  }

  const char* name() const {
    return "Square";
  }

  void printDetails() const{
    cout << "The " << name() << "'s area = " << area() << endl;
  }

  void inputData() {
    cout << "Enter the " << name() << "'s side: ";
    cin >> side;
  }

  double area() const {
    return side * side;
  }

protected:
  double side;
};
// Cube
class Cube : public Square {
public:
  Cube(double s = 0.0) : Square(s) {
    side = s;
  }
  
  const char* name() const{
    return "Cube";
  }

  void printDetails() const{
    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;
  }

  void inputData(){
    cout << "Enter the " << name() << "'s side: ";
    cin >> side;
  }

  double area() const {
    return 6 * side * side;
  }

  double volume() const {
    return side * side * side;
  }

protected:
};
// Triangle
class Triangle : public Shape {
public:
  Triangle(double s = 0.0) {
    side = s;
  }

  const char* name() const {
    return "Triangle";
  }

  void printDetails() const{
    cout << "The " << name() << "'s area = " << area() << endl;
  }

  void inputData() {
    cout << "Enter the " << name() << "'s side: ";
    cin >> side;
  }

  double area() const {
    return (side * side) * sqrt(3) / 4;
  }

protected:
  double side;
};
// Tetrahedron
class Tetrahedron : public Triangle {
public:
  Tetrahedron(double s = 0.0) : Triangle(s) {
    side = s;
  }

  const char* name() const {
    return "Tetrahedron";
  }

  void printDetails() const {
    cout << "The " << name() << "'s surface area = " << area() << endl;
    cout << "The " << name() << "'s volume = " << volume() << endl;
  }

  void inputData() {
    cout << "Enter the " << name() << "'s side: ";
    cin >> side;
  }

  double area() const {
    return (side * side) * sqrt(3);
  }

  double volume() const {
    return (side * side * side) * sqrt(2) / 12;
  }

protected:
};

int displayMenu(Shape *[]);

int main() {
   
  Shape *shapeArray[NUM];
  shapeArray[0] = new Circle();

 // Uncomment the line below when you have completed its corresponding class for that shape.
 // The shape will be added to the array and the corresponding menu option will be shown.
  shapeArray[1] = new Sphere();
  shapeArray[2] = new Cylinder();
  shapeArray[3] = new Square();
  shapeArray[4] = new Cube();
  shapeArray[5] = new Triangle();
  shapeArray[6] = new Tetrahedron();

  int choice = displayMenu(shapeArray);
  while (choice >= 0 && choice <= 6) {
    shapeArray[choice]->inputData();
    shapeArray[choice]->printDetails();
    cout << endl;
    choice = displayMenu(shapeArray);
  }
  return 0;
}

/**
 * Displays the menu for which shape to perform calculations.
 *
 * @param shapeArrayParam array of shapes that this program supports
 * @return the choice from the user
 */
int displayMenu(Shape *shapeArrayParam[]) {
  int choice = 0;
  cout << "Select an object from the menu (enter 7 to quit)." << endl;
  for (int i = 0; i < NUM; i++) {
    cout << '\t' << i << ". " << shapeArrayParam[i]->name() << endl;
  }
  cin >> choice;
  return choice;
}

/*
Example outputs:
Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
0
Enter the Circle's radius: 10
The Circle's area = 314

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
1
Enter the Sphere's radius: 20
The Sphere's surface area = 5024
The Sphere's volume = 33493.3

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
2
Enter the Cylinder's radius: 30
Enter the Cylinder's height: 40
The Cylinder's surface area = 13188
The Cylinder's volume = 113040

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
3
Enter the Square's side: 50
The Square's area = 2500

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
4
Enter the Cube's side: 60
The Cube's surface area = 21600
The Cube's volume = 216000

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
5
Enter the Triangle's side: 70
The Triangle's area = 2121.76

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
6
Enter the Tetrahedron's side: 80
The Tetrahedron's surface area = 11085.1
The Tetrahedron's volume = 60339.8

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
7
*/








---
layout: project
type: project
image: img/3dshapes.jpg
title: "Shape Class Hierarchy"
date: 2023-12-05
published: true
labels:
  - Class Hierarchy
  - C++
summary: "A code I developed for ICS 212 that calculates the area, surface area, and/or volume of a shape using a class hierarchy."
---

The goal of this project was to create a program that calculates the area, surface area, and volume (if applicable) of a shape chosen by a user. The code displays a list of shapes to choose from - Sphere, Cylinder, Square, Cube, Triangle, and Tetrahedron - and takes an input based on the previous choice - Side, Radius, or Height - and calculates the area, surface area, and/or volume of the desired shape.

I built this code during the 2023-24 school year for my ICS 212 class. This code was built upon a previous assignment, adding the options to calculate the dimensions of 3D shapes including a sphere, cylinder, cube, and tetrahedron. This project focused on object inheritance, where the 3D objects inherited traits from the 2D objects such as the radius or the length of a side.

Here is some code from the project that demonstrates inherited traits:

```cpp
// sphere inherits the radius of circle
class Sphere : public Circle {
public:
  Sphere(double r = 0.0): Circle(r) {
    radius = r;
  }
}
// cylinder inherits the radius of circle
class Cylinder : public Circle {
public:
  Cylinder(double r = 0.0, double h = 0.0) : Circle(r) {
    radius = r;
    height = h;
  }
}
// cube inherits the side length of square
class Cube : public Square {
public:
  Cube(double s = 0.0) : Square(s) {
    side = s;
  }
}
// tetrahedron inherits the side length of triangle
class Tetrahedron : public Triangle {
public:
  Tetrahedron(double s = 0.0) : Triangle(s) {
    side = s;
  }
}

```

This project developed my understanding of class hierarchies and the process of inheritance across different objects. It also furthered my understanding of C++ and taught me how to handle objects, which has translated to the other coding languages I am familiar with.

You can access the rest of the code [here](https://github.com/kaenasylva/kaenasylva.github.io/blob/main/projects/shape-class-hierarchy.cpp).

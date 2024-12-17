---
layout: project
type: project
image: img/calculator-button.jpg
title: "Complex Numbers Calculator"
date: 2023-11-21
published: false
labels:
  - Complex Numbers
  - Calculator
  - C++
summary: "A code I developed for ICS 212 that calculates and correctly formats complex numbers."
---

The goal of this project was to create a class called "Complex" that is capable of calculating and correctly formatting complex numbers based on a user input. It utilized various member functions and overloaded operators in C++.

I built this code during the 2023-24 school year for my ICS 212 class. This code originated with a previous assignment that was designed to calculate complex numbers. The original program could calculate complex numbers based on pre-determined inputs to a function. The current version of the code differs from the former in that it can take user inputs and implements overloaded operators to create complex objects with cin and cout.

Here is some code that exemplifies the overloaded operators:

```cpp
// Overloads input stream
friend istream &operator>>(istream &in, Complex &complexParam){
    in >> complexParam.real >> complexParam.imaginary;
    return in;
}
// Overloads output stream
friend ostream &operator<<(ostream &out, Complex &complexParam){
    out << complexParam.real << " + " << complexParam.imaginary << "i";
    return out;
}
```

This project taught me to understand how to overload operators, work with calculations involving imaginary numbers, and furthered my understanding in C++.

You can find the full code [here](https://github.com/kaenasylva/kaenasylva.github.io/blob/main/projects/complex-numbers-calculator.cpp).

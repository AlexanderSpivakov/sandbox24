#include<iostream>
#include<math.h>
#include"quad_eq.hpp"

void SolveQuadEq(){
    std::cout << "Program solving quadratic equations in the from: ax^2 + bx + c = 0\n" << "Enter the coefficents a,b,c:\n";
    double a, b, c;
    std::cin >> a >> b >> c;

    const double d = sqrt(b*b - 4*a*c);
    a *= 2;
    b = -b;
    if (d > 0){
	double x1 = (b + d)/a;
	double x2 = (b - d)/a;
	std::cout << "Roots of equation: x1 = " << x1 << " x2 = " << x2 << "\n";
    }
	else if (d == 0){
	    double x = b/a;
	    std::cout << "Roots of equation: x = " << x << "\n";
	}
	    else std::cout << "No solutions for this equatin\n";
}
#include <iostream>

#include "quad_eq.hpp"

int main()
{
	std::cout << "Hello, World!\n";

	double a = 0., b = 0., c = 0.;
	
	std::cout << "Programme for solving quadratic equations in the form: ax^2 + bx + c = 0\n"
		<< "Enter the coefficients a, b and c: ";
	std::cin >> a >> b >> c;

	std::pair<double, double> roots = SolveQuadEq(a, b, c);
	
	if (roots.first == INFINITY)
		std::cout << "No solution";
	else
		std::cout << "Roots of equation: x1 = " << roots.first << " x2 = " << roots.second << "\n";
} 
#include <math.h>
#include <iostream>

#include "quad_eq.hpp"

void SolveQuadEq()
{
	std::cout << "Programme for solving quadratic equations in the form: ax^2 + bx + c = 0\n"
				 << "Enter the coefficients a, b and c: ";

	double a = 0., b = 0., c = 0.;

	std::cin >> a >> b >> c;

	//Дискриминант
	double d = (b * b) - (4 * a * c);

	if (d > 0)
	{
		double x1 = (b * -1) + sqrt(d) / (2 * a);
		double x2 = (b * -1) - sqrt(d) / (2 * a);

		std::cout << "Roots of equation: x1 = " << x1 << " | x2 = " << x2;
	}
	else if (d == 0)
	{
		double x = (b * -1) / (2 * a);

		std::cout << "Roots of equation: x1 = x2 = " << x;
	}
	else
	{
		std::cout << "No solutions for this equation.\n";
	}
}
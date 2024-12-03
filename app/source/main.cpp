#include <iostream>
#include <array>
#include "quad_eq.hpp"

#ifdef _WIN32
	#include <Windows.h>
	#undef max
	HINSTANCE hdll = LoadLibrary("QuadEqLib");
	#define GET_FUNC(handle, function) GetProcAddress(handle, function)
	#define CLOSE_LIBRARY(handle)	   FreeLibrary(handle)
#else
	#include <dlfcn.h>
	void* hdll = dlopen("QuadEqLib", RTLD_NOW);
	#define GET_FUNC(handle, function) dlsym(handle, function)
	#define CLOSE_LIBRARY(handle)	   dlclose(handle)
#endif

EQStatus(*LibSolveFunc) (std::array<double, 3> arr);
std::array<double, 3> GetInput();
void PrintResult(EQStatus);

int main()
{
	if (!hdll)
		return -1;
	LibSolveFunc = (EQStatus(*) (std::array<double, 3> arr)) GET_FUNC(hdll, "SolveQuadEq");
	
	std::cout << "Hello, World!\n";
	std::array<double, 3> input = GetInput();
	EQStatus equationStatus = LibSolveFunc(input);
	PrintResult(equationStatus);

	CLOSE_LIBRARY(hdll);
} 

std::array<double, 3> GetInput()
{
	std::cout << "Programme for solving quadratic equations in the form: ax^2 + bx + c = 0\n"
			  << "Enter the coefficients a, b and c: ";

	std::array<double, 3> input = { 0, 0, 0 };
	std::cin >> input[0] >> input[1] >> input[2];
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "ERROR. Enter numbers: ";
		std::cin >> input[0] >> input[1] >> input[2];
	}
	return input;
}

void PrintResult(EQStatus equationStatus)
{
	switch (equationStatus.solState)
	{
	case 1:
		std::cout << "Any solution\n";
		break;
	case 2:
		std::cout << "Solutions: x1 = " << equationStatus.solution[0] << " x2 = "
			<< equationStatus.solution[1] << "\n";
		break;
	case 3:
		std::cout << "Solutions: x1 = " << equationStatus.solution[0] << " x2 = "
			<< equationStatus.solution[1] << "\n";
		break;
	default:
		std::cout << "Equation has no solutions\n";
		break;
	}
}

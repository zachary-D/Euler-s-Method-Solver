#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

double xTarget;		//The value being approximated

double stepSize;	//The size of each step taken in the approximation
double totalSteps;	//The total number of steps taken to reach the approximation xTarget

std::vector<double> y;	//The y values approximated
std::vector<double> x;	//The x values that correspond to the y values

double getNum(std::string prompt)
{
	std::string input;
	double output;
	std::stringstream convert;

	do
	{
		if (convert.fail())
		{
			cout << "Im sorry, I don't understand \"" << input << "\".  Please try again" << endl;
			convert = std::stringstream();
			convert.clear();
		}

		cout << prompt << ":";
		std::getline(cin, input);
			
		convert << input;
		convert >> output;
		
	} while (convert.fail() == true);
	return output;
}

int main()
{
	//Get values from the user
	xTarget = getNum("X being approximated");

	x.push_back(getNum("Initial x value"));
	y.push_back(getNum("Initial y value"));

	do
	{
		stepSize = getNum("Step size");
		if (stepSize <= 0) cout << "I'm sorry, Step size must be greater than 0." << endl;
	} while (stepSize <= 0);
	totalSteps = xTarget / stepSize;
	 
	//Calculate approximate solution
	for (int iter = 0; iter < totalSteps; iter++)
	{
		y.push_back(y[iter] + stepSize * exp(-y[iter]));
		x.push_back(y[iter] + stepSize);
	}

	//Display solution
	cout << "Approximation for y(" << xTarget << ") = " << y[y.size() - 1] << endl << endl;

	cout << "Press enter to display full steps" << endl;
	std::getline(cin, std::string());

	cout << setw(10) << "x" << "|" << setw(10) << "y" << endl;
	for (int iter = 0; iter < y.size(); iter++)
	{
		cout << setw(10) << x[iter] << "|" << setw(10) << y[iter] << endl;
	}

	//Keep the window open
	std::getline(cin, std::string());

	return 0;
}
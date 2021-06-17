#include <iostream>
#include "include/MonteCarlo.h"
#include "include/Vanilla.h"
#include "include/Random.h"

int main()
{

    double Expiry = 2;
	double Strike = 200;
	double Spot = 300;
	double Vol = 0.2;
	double r = 0.45;
	unsigned long NumberOfPaths = 5000;
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPaths);

	std::cout <<"\nthe call price is " << result << "\n";
    return 0;
}

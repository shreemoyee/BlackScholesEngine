#include "../include/MonteCarlo.h"
#include <cmath>
#include "../include/Array.h"
#include "../include/Normals.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberOfPaths)
{

    double Expiry = TheOption.GetExpiry();

	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot = Spot*exp(r*Expiry +itoCorrection);
	double thisSpot;
	double runningSum=0;

	for (unsigned long i=0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp( rootVariance*thisGaussian);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		runningSum += thisPayOff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;
}

void SimpleMonteCarlo6(const VanillaOption& TheOption,
						 double Spot,
						 const Parameters& Vol,
						 const Parameters& r,
                         unsigned long NumberOfPaths,
                         RandomBase& generator)
{
    generator.ResetDimensionality(1);

    double Expiry = TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0,Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;
	double movedSpot = Spot*exp(r.Integral(0,Expiry) +itoCorrection);

	double thisSpot;
    double discounting = exp(-r.Integral(0,Expiry));

    MJArray VariateArray(1);

	for (unsigned long i=0; i < NumberOfPaths; i++)
	{
        generator.GetGaussians(VariateArray);
		thisSpot = movedSpot*exp( rootVariance*VariateArray[0]);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
	}

    return;
}

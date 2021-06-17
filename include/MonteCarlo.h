
#ifndef __MONTE_CARLO_H__
#define __MONTE_CARLO_H__

#include "Vanilla.h"
#include "Parameters.h"
#include "Random.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberOfPaths);

void SimpleMonteCarlo6(const VanillaOption& TheOption,
						 double Spot,
						 const Parameters& Vol,
						 const Parameters& r,
                         unsigned long NumberOfPaths,
						 RandomBase& generator);

#endif

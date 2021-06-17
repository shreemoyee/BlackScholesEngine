#ifndef __NORMALS_H__
#define __NORMALS_H__

double GetOneGaussianBySummation();
double GetOneGaussianByBoxMuller();
double NormalDensity(double x);
double CumulativeNormal(double x);
double InverseCumulativeNormal(double u);

#endif

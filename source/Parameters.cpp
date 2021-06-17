#include "../include/Parameters.h"

Parameters::Parameters(const ParametersInner& innerObject)
{
   InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original)
{
   InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original)
{
   if (this != &original)
   {
      delete InnerObjectPtr;
      InnerObjectPtr = original.InnerObjectPtr->clone();
   }
   return *this;
}

Parameters::~Parameters()
{
   delete InnerObjectPtr;
}

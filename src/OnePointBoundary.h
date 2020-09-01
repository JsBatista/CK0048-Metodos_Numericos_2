#pragma once
#include "Answer.h"

class OnePointBoundary
{

	public:
		OnePointBoundary();		
        void eulerExplicitProblem1(int iterations, double v0, double y0, double k, double m, double deltaT, double t0);
		void eulerImplicitProblem1(int iterations, double v0, double y0, double k, double m, double deltaT, double t0);

        
};
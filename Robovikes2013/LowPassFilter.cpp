#include "LowPassFilter.h"

LowPassFilter::LowPassFilter(Joystick* joystickInput, const int axisNum)
:mAxisNum(axisNum),
 mJoystickInput(joystickInput), 
 prevSample(0)
{
	
}

double LowPassFilter::Calculate(const double rc)
{
	double alpha = 1.0/(rc+1.0);
	double currentSample = mJoystickInput->GetRawAxis(mAxisNum);
	double output = alpha * currentSample + (1.0-alpha) * prevSample;
//	printf("Calc: alpha:%g, sample: %g, prevSample: %g, output: %g\n", alpha, currentSample,prevSample, output);	
	prevSample = output;
	return output;
}


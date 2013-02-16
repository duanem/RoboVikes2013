#ifndef LOW_PASS_FILTER_H_
#define LOW_PASS_FILTER_H_

#include "Joystick.h"

class LowPassFilter
{
public:
	LowPassFilter(Joystick* joystickInput, const int axisNum);
	double Calculate(const double rc);
private:
	const int mAxisNum;
	Joystick* mJoystickInput;
	double prevSample;
	
};


#endif

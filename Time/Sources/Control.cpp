#include "Control.h"

Controls::Controls()
{
	w = a = s = d = space = rmb = lmb = false;
	xRotation = 0.0;
	yRotation = 0.0;
	lastX = 0.0;
	lastY = 0.0;
}

void Controls::interpretKey(int keycode, int action)
{
	switch (keycode)
	{
	case 25:
	case 17:
		w = action != 0;
		break;
	case 38:
	case 30:
		a = action != 0;
		break;
	case 39:
	case 31:
		s = action != 0;
		break;
	case 40:
	case 32:
		d = action != 0;
		break;
	case 65:
	case 57:
		space = action != 0;
		break;
	default:
		break;
	}
}

void Controls::interpretMouseButton(int button, int action)
{
	if (button == 0 && action == 1)
		lmb = true;
	if (button == 1 && action == 1)
		rmb = true;
	
}

void Controls::interpretMouseMove(double x, double y)
{	
	xRotation += (x-lastX) / 600.0;
	float potentialY = yRotation + (-y + lastY) / 700.0;
	yRotation = potentialY < -1.5708 || potentialY > 1.5708 ? yRotation : potentialY;
	lastX = x;
	lastY = y;
}
/*
 * SSC32.h
 *  
 * Lynxmotion Serial Servo Controller 32 Library for the Arduino
 * - Frames are used to organize all of the positions of the servos
 * - Sends the position and time commands through Serial
 * - Servos can be disabled and enabled easily
 *
 * Released by RobotGrrl on April 4th, 2010
 * www.RobotGrrl.com
 * Code is under the GNU GPLv3 License
 *
 */

#ifndef SSC32_h
#define SSC32_h

#include <Streaming.h>

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

const int numberOfPorts = 32;

class SSC32 {

public:

	SSC32(bool blah);
	void initServoModes();
	void servoMode(int servoNum, bool on);
	bool getServoMode(int servoNum);
	void setFrame(int theFrame[], int moveTime, int delayTime);
	
	
private:
	
	bool SSCPORT[numberOfPorts+1];

};

#endif
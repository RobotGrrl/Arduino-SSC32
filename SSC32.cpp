/*
 * SSC32.cpp
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

#include "WProgram.h"
#include <Streaming.h>
#include "SSC32.h"

// For some reason Arduino likes this better when there 
// is a parameter in the constructor... Weird!
SSC32::SSC32(bool blah) {
	initServoModes();
}

// Initialize all the servos
void SSC32::initServoModes() {
	for(int i=0; i<numberOfPorts; i++) {
		SSCPORT[i] = false;
	} 
}

// Set the servo mode to on or off
void SSC32::servoMode(int servoNum, bool on) {
	SSCPORT[servoNum] = on;
}

// See if the servo is enabled or not
bool SSC32::getServoMode(int servoNum) {
	return SSCPORT[servoNum];
}

// Move the servos according to the frame
void SSC32::setFrame(int theFrame[], int moveTime, int delayTime) {
	
	int frameIndex = 0;
	bool debug = true;
	
	// Look through all the ports
	for(int i=0; i<numberOfPorts; i++) {
		
		// If the port is enabled
		if(getServoMode(i) == true) {
			
			// Send the data through Serial
			Serial << "#" << i << "P" << theFrame[frameIndex];
			if(debug) Serial << "#" << i << "P" << theFrame[frameIndex];
			
			// Go to the next position in the frame
			frameIndex++; 
		}
	}
	
	// Print out the time and send it
	Serial << "T" << moveTime << endl;
	if(debug) Serial << "T" << moveTime << endl;
	
	// Delay for both the movement time and the delay time
	delay(moveTime + delayTime);
	
}


#include "RockridgePX.h"

RockridgePX::RockridgePX(char *buffer) {
	if (buffer[0] == 'P' && buffer[1] == 'X') { // It is a PX record
		length = (unsigned int) buffer[2];
		version = buffer[3];
		posixFileMode = BothEndianInt(&(buffer[4]));
		nbrLinks = BothEndianInt(&buffer[12]);
		userID = BothEndianInt(&buffer[20]);
		groupID = BothEndianInt(&buffer[28]);
		serialNumber = BothEndianInt(&buffer[36]);
	} else {
		// Throw an exception...
	}
}
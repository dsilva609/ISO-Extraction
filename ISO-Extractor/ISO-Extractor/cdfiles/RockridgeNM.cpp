#include "RockridgeNM.h"

RockridgeNM::RockridgeNM(char *buffer) {
	if (buffer[0] != 'N' || buffer[1] != 'M') {
		//throw an exception
	} else {
		filename = "";

		length = (unsigned char) buffer[2];
		version = buffer[3];
		flags = buffer[4];
		for (int position = 5; position < length; position++) {
			filename = filename + buffer[position];
		}
	}

}

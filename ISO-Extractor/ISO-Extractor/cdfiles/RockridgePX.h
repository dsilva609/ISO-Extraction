#ifndef __ROCKRIDGEPX_H__
#define __ROCKRIDGEPX_H__
#include "BothEndianInt.h"

class RockridgePX {
protected:
	int length;
	BothEndianInt posixFileMode;
	BothEndianInt nbrLinks;
	BothEndianInt userID;
	BothEndianInt groupID;
	BothEndianInt serialNumber;
	int version;
public:
	RockridgePX(char *buffer="PX\44\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	BothEndianInt getNbrLinks() { return nbrLinks;}
	BothEndianInt getPosixFileMode() {return posixFileMode; }
	int getVersion() { return version; }
	int getLength() { return length; }
	BothEndianInt getUserID() { return userID; }
	BothEndianInt getSerialNumber() { return serialNumber; }
	BothEndianInt getGroupID() { return groupID; }
};

#endif

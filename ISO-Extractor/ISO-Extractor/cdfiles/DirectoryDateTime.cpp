#include "DirectoryDateTime.h"

DirectoryDateTime::DirectoryDateTime(char *bytes) {
	year = 1900 + bytes[0];
	month = bytes[1];
	day = bytes[2];
	hour = bytes[3];
	minute = bytes[4];
	second = bytes[5];
	greenwichOffset = bytes[6];
}

char *DirectoryDateTime::getBytes() {
	char *byte;
	byte = new char[7];

	byte[0] = year - 1900;
	byte[1] = month;
	byte[2] = day;
	byte[3] = hour;
	byte[4] = minute;
	byte[5] = second;
	byte[6] = greenwichOffset;
	return byte;
}
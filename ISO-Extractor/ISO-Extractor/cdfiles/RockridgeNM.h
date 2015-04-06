#ifndef __ROCKRIDGENM_H__
#define __ROCKRIDGENM_H__
#include <string>
using namespace std;


class RockridgeNM {
protected:
	string filename;
	char flags;
	int version;
	int length;
public:
	RockridgeNM(char *buffer="NM\6\1\0a");
	string getFilename() { return filename; }
	char getFlags() {return flags; }
	int getVersion() { return version; }
	int getLength() { return length; }
};

#endif

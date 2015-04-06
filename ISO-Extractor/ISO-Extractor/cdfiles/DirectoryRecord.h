#ifndef __DIRECTORYRECORD_H__
#define __DIRECTORYRECORD_H__
#include <cstdlib>
#include "DirectoryDateTime.h"
#include "BothEndianInt.h"
#include "BothEndianShort.h"
#include <string>
using namespace std;

class DirectoryRecord {
protected:
	int dirRecordLen, extAttributeRecordLen;
	BothEndianInt location, dataLength;
	DirectoryDateTime recordingDateTime;
	int fileFlags, fileUnitSize, interleaveGapSize, fileIDLength;
	BothEndianShort volumeSequenceNbr;
	string fileID;
public:
	DirectoryRecord(char * bytes = NULL);

	int getDirRecordLen() { return dirRecordLen; }
	int getExtAttributeRecordLen() { return extAttributeRecordLen; }
	BothEndianInt getLocation() {return location; }
	BothEndianInt getDataLength() { return dataLength; }
	BothEndianShort getVolumeSequenceNbr() { return volumeSequenceNbr; }
	DirectoryDateTime getRecordingDateTime() { return recordingDateTime; }
	int getFileFlags() { return fileFlags; }
	int getFileUnitSize() { return fileUnitSize; }
	int getInterleaveGapSize() { return interleaveGapSize; }
	int getFileIDLength() { return fileIDLength; }
	string getFileID(){ return fileID; }
};

#endif

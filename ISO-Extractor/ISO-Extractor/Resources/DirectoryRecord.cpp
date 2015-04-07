#include "DirectoryRecord.h"
#include <cstdlib>

DirectoryRecord::DirectoryRecord(char *bytes) {
	if (bytes == NULL) {
		
	} else {
		dirRecordLen = bytes[0];
		extAttributeRecordLen = bytes[1];
		location=BothEndianInt(&bytes[2]);
		dataLength = BothEndianInt(&bytes[10]);
		recordingDateTime = DirectoryDateTime(&bytes[18]);
		fileFlags = bytes[25];
		fileUnitSize = bytes[26];
		interleaveGapSize = bytes[27];
		volumeSequenceNbr = BothEndianShort(&bytes[28]);
		fileIDLength = bytes[32];
		fileID = bytes[33];
	}
}
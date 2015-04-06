#include "PrimaryVolumeDescriptor.h"
#include <cstring>
using namespace std;

PrimaryVolumeDescriptor::PrimaryVolumeDescriptor(char * sector) {
	char tempCString[1024];
	if (sector != NULL) {
		volumeDescriptorType = sector[0];
		standardIdentifier = "";
		standardIdentifier = standardIdentifier + sector[1] + sector[2] + sector[3] + sector[4] + sector[5];
		volumeDescriptorVersion = sector[6];

		strncpy(tempCString, &sector[8], 32);
		tempCString[32] = 0;
		systemID = string(tempCString);

		strncpy(tempCString, &sector[40], 32);
		tempCString[32] = 0;
		volumeID = string(tempCString);

		volumeSpaceSize = BothEndianInt(&sector[80]);
		volumeSetSize = BothEndianShort(&sector[120]);
		logicalBlockSize = BothEndianShort(&sector[128]);
		pathTableSize = BothEndianInt(&sector[132]);
		locationLPathTable = BothEndianShort(&sector[140]);
		locationOptionalLPathTable = BothEndianShort(&sector[144]);
		locationMPathTable = BothEndianShort(&sector[148]);
		locationOptionalMPathTable = BothEndianShort(&sector[152]);
		rootDirectory = DirectoryRecord(&sector[156]);

		strncpy(tempCString, &sector[190], 128);
		tempCString[128] = 0;
		volumeSetID= string(tempCString);

		strncpy(tempCString, &sector[318], 128);
		tempCString[128] = 0;
		publisherID= string(tempCString);

		strncpy(tempCString, &sector[446], 128);
		tempCString[128] = 0;
		dataPreparerID = string(tempCString);

		strncpy(tempCString, &sector[574], 128);
		tempCString[128] = 0;
		applicationID = string (tempCString);

		strncpy(tempCString, &sector[702], 37);
		tempCString[37] = 0;
		copyrightFileID = string(tempCString);

		strncpy (tempCString, &sector[739], 37);
		tempCString[37] = 0;
		abstractFileID = string (tempCString);

		strncpy (tempCString, &sector[776], 37);
		tempCString[37] = 0;
		bibliographicFileID = string(tempCString);
		volumeCreation = *(new DescriptorDateTime(&sector[813]));
		volumeModification = *(new DescriptorDateTime(&sector[830]));
		volumeExpiration = *(new DescriptorDateTime(&sector[847]));
		volumeEffective  = *(new DescriptorDateTime(&sector[864]));
		fileStructureVersion = sector[881];
		memcpy(applicationArea, &sector[883], 512);
	} else {

	}
}

	char * PrimaryVolumeDescriptor::getApplicationArea() {
		char * result = new char[512];

		memcpy(result, applicationArea, 512);
		return result;
	}

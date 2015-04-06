#ifndef __PRIMARYVOLUMEDESCRIPTOR_H__
#define __PRIMARYVOLUMEDESCRIPTOR_H__
/*
 * This class implements the Primary Volume Descriptor for a CD volume.
 * It follows the format given in ISO 9660 Section 8.4.  It uses a number
 * of subtypes to deal with other pieces.  
 *
 * This code is not fully tested yet and should be considered buggy.
 *
 */
#include "BothEndianShort.h"
#include "BothEndianInt.h"
#include <string>
#include "DirectoryRecord.h"
#include "DescriptorDateTime.h"
using namespace std;

class PrimaryVolumeDescriptor {
protected:
	short volumeDescriptorType;
	string  standardIdentifier;
	short volumeDescriptorVersion;
	string systemID;
	string volumeID;
	BothEndianInt volumeSpaceSize, pathTableSize;
	BothEndianShort volumeSetSize, volumeSequenceNumber, 
		logicalBlockSize, locationLPathTable, 
		locationOptionalLPathTable, locationMPathTable, 
		locationOptionalMPathTable;
	DirectoryRecord rootDirectory;
	string volumeSetID, publisherID, dataPreparerID, 
		applicationID, copyrightFileID, abstractFileID, 
		bibliographicFileID;
	DescriptorDateTime volumeCreation, volumeModification, 
		volumeExpiration, volumeEffective;
	short fileStructureVersion;
	char applicationArea[512];
public:
	PrimaryVolumeDescriptor (char * sector=NULL);

	// access Methods ....

	string getVolumeSetID() { return volumeSetID; }
	string getPublisherID() { return publisherID; }
	string getDataPreparerID() { return dataPreparerID; }
	string getApplicationID() { return applicationID; }
	string getCopyrightFileID() { return copyrightFileID; }
	string getAbstractFileID() { return abstractFileID; }
	string getBibliographicFileID() { return bibliographicFileID; }
	char *getApplicationArea() ;
	DirectoryRecord getRootDirectory() { return rootDirectory; }
	string getStandardIdentifier() { return standardIdentifier; }
	string getSystemID() { return systemID; }
	string getVolumeID() { return volumeID; }
	BothEndianInt getVolumeSpaceSize() { return volumeSpaceSize; }
	BothEndianInt getPathTableSize() { return pathTableSize; }
	BothEndianShort getVolumeSetSize() { return  volumeSetSize; }
	BothEndianShort getVolumeSequenceNumber() { return volumeSequenceNumber; }
	BothEndianShort getLogicalBlockSize() {return logicalBlockSize; }
	BothEndianShort getLocationLPathTable() { return locationLPathTable; }
	BothEndianShort getOptionalLocationLPathTable() { return locationOptionalLPathTable; }
	BothEndianShort getLocationMPathTable() { return locationMPathTable; }
	BothEndianShort getOptionalLocationMPathTable() { return locationOptionalMPathTable; }
};

#endif

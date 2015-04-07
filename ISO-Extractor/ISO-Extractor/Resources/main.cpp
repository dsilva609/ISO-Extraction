#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "BothEndianInt.h"
#include "BothEndianShort.h"
#include "PrimaryVolumeDescriptor.h"
using namespace std;

int main(int argCount, char *argValues[])
{
	BothEndianInt testValue1("\x78\x56\x34\x12\x12\x34\x56\x78");
	BothEndianShort testValue2("\x43\x21\x21\x43"); \
		PrimaryVolumeDescriptor *pdesc;
	/*
	 * quick test of the BothEndian classes....
	 */
	cout << testValue1.getValue() << endl;

	testValue1.setValue(4660);
	cout << testValue1.getValue() << endl;

	char *bytePattern = testValue1.getBytes();
	for (int i = 0; i < 8; i++)
	{
		cout << hex << setw(2) << (int)bytePattern[i] << " ";
	}
	cout << endl << dec;
	cout << endl;

	cout << testValue2.getValue() << endl;
	testValue2.setValue(4660);
	cout << testValue1.getValue() << endl;

	char *shortbytePattern = testValue2.getBytes();
	for (int i = 0; i < 4; i++)
	{
		cout << hex << setw(2) << (int)shortbytePattern[i] << " ";
	}
	cout << endl << dec;
	cout << endl;
	/*
	 * test the primary Volume Descriptor structure.  Need an ISO
	 * image to do this correctly...
	 */
	ifstream isoImage;
	isoImage.open("test.iso", ios_base::in | ios_base::binary);
	// isoImage.open("simple.iso", ios_base::in | ios_base::binary);
	if (isoImage.is_open())
	{
		char sector[2048];
		isoImage.seekg(16 * 2048, ios_base::beg);
		isoImage.read(sector, 2048);
		if (isoImage.gcount() != 2048)
		{
			// Short Read -- OOPs!
		}
		pdesc = new PrimaryVolumeDescriptor(sector);
		int rootDirectoryLocation = pdesc->getRootDirectory().getLocation().getValue();
		isoImage.seekg(rootDirectoryLocation * 2048, ios_base::beg);
		isoImage.read(sector, 2048);

		isoImage.close();
	}
	return EXIT_SUCCESS;
}
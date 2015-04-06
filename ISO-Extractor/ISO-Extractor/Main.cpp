#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "hello world" << endl;

	fstream iso;
	string lineIn;

	iso.open("test.iso", ios_base::in | ios_base::binary);

	if (iso.good())
	{
		/*while (iso.good())
		{
		cout << "reading..." << endl;
		getline(iso, lineIn);
		cout << lineIn << endl;
		}*/

		char sector[2048];
		iso.seekg(16 * 2048, ios_base::beg);
		iso.read(sector, 2048);
		cout << sector << endl;

		//		iso.seekg(16 * 2048);
		iso.read(sector, 2048);
		cout << sector << endl;

		iso.read(sector, 2048);
		cout << sector << endl;
		iso.read(sector, 2048);
		cout << sector << endl;
		if (iso.gcount() != 2048)
		{
			// Short Read -- OOPs!
		}
		//pdesc = new PrimaryVolumeDescriptor(sector);
		//int rootDirectoryLocation = pdesc->getRootDirectory().getLocation().getValue();
		//iso.seekg(rootDirectoryLocation * 2048, ios_base::beg);
		iso.read(sector, 2048);
	}
	else
		cout << "could not open file" << endl;

	iso.close();

	return EXIT_SUCCESS;
}
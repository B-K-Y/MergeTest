#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct XYZData
{
	string header;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	
};

int main()
{
	fstream f1, f2, fo;
	XYZData data1, data2;

	f1.open("File1.xyz", ios::in);
	f2.open("File2.xyz", ios::in);
	fo.open("File3.xyz", ios::out);

	if (!f1.is_open())
	{
		cout << "Datei 1 konnte nicht geoeffnet werden!\n";
		return -1;
	}
	if (!f2.is_open())
	{
		cout << "Datei 2 konnte nicht geoeffnet werden!\n";
		return -1;
	}
	if (!fo.is_open())
	{
		cout << "Datei 3 konnte nicht geoeffnet werden!\n";
		return -1;
	}

	getline(f1, data1.header);
	fo << data1.header << endl << endl;

	while (f1.eof() != true)
	{
		f1 >> data1.x;
		f1 >> data1.y;
		f1 >> data1.z;
		fo << data1.x << " " << data1.y << " " << data1.z << endl;
	}
	fo << endl;
	
	getline(f2, data2.header);
	fo << data2.header << endl << endl;

	while (f2.eof() != true)
	{
		f2 >> data2.x;
		f2 >> data2.y;
		f2 >> data2.z;
		fo << data1.x << " " << data1.y << " " << data1.z << endl;
	}

	return 0;
}
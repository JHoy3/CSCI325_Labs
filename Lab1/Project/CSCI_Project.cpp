#include <iostream>
//Next 2 are needed for file reading.
#include <fstream>
#include <string>
#include <sstream>
// just to make things easier
using namespace std;

struct Node {

};

int main()
{
	ifstream inputFile("testdata.txt");
	if (!inputFile) {
		cout << "File not found" << endl;
	}

	string line;

    while (getline(inputFile, line)) {

        stringstream ss(line);

        string ISBN;
        string title;
        getline(ss, ISBN, ',');
        getline(ss, title, ',');

        cout << ISBN << endl;
        cout << title << endl;
    }

    inputFile.close();
}
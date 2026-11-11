#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main () {

    unordered_map<int, string> students;

    // //insert 
    // cout << "Please enter 5 student IDs and names: " << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     int id; string name;
    //     cout << "ID #" << i+1 << ": "; cin >> id;
    //     cout << "Name # " << i+1 << ": "; cin >> name;

    //     students[id] = name;
    // }

    //find

    //list

    char c = '\0';
    while (c != 'Q')
    {
        cout << "Enter your operation insert(i) find(f) display (d) quit(q): "; cin >> c;
        c = toupper(c);

        if(c == 'I')
        {
            int id;
            string name;
            cout << "Please offer an ID: "; cin >> id;
            cout << "Please offer a Name: "; cin >> name;
            students[id] = name;

        }
        else if (c == 'F')
        {
            int id;
            cout << "PLease enter a studen id: "; cin >> id;
            auto results = students.find(id);
            if (results != students.end()) {
                cout << "Found: " << results->second << endl;
            } else {
                cout << "Not found" << endl;
            }
        }
        else if (c == 'D') {
            for (auto student : students) {
                cout << student.first << " : " << student.second << endl;
            }
        }
    }

}
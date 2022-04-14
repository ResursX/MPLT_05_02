#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ifstream finp;

    finp.open("C:\\Users\\USER\\Downloads\\data_no_error.bin", ios::binary);

    unsigned char a;

    finp.seekg(0, ios::end);

    cout << finp.tellg() << endl;

    finp.seekg(0, ios::beg);

    ofstream fout;

    fout.open("result.txt", ios::app);

    fout << "------------ " << "data_no_error.bin" << " ------------" << endl;

    //fout << hex;

    while (finp.read((char*)&a, sizeof(char)))
    {
        if (a == 0xAA)
        {
            fout << setw(4) << endl << (int)a << endl;

            continue;
        }

        fout << setw(4) << (int)a;
    }

    fout.close();
    finp.close();
}
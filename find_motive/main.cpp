#include <iostream>
#include <iosfwd>
#include <fstream>

using namespace std;
int main(int argc , char *argv[])
{
    ifstream file(argv[1]);
    if(!file.is_open())
    {
        cout << "The file *" << argv[1] << "* could not be opened" << endl;
        return 1;
    }
    string line;
    int count = 0;
    while(file >> line)
    {
        if(line.find(argv[2]) != string::npos)
        {
            count++;
        }
    }
        
    cout << "The file *" << argv[1] << "* contains *"<< count << "* words containing the motive *" << argv[2] << "*"<< endl;
    return 0;
}

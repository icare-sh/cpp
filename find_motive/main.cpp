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
    while(getline(file,line))
    {
        int i = 0;
        while(i < line.length())
        {
            int cpt = line.find(argv[2],i);
            if (cpt == string::npos)
                break;
            count++;
            i = cpt + 1;
        }
    }
    cout << "The file *" << argv[1] << "* contains *"<< count << "* words containing the motive *" << argv[2] << "*"<< endl;
    return 0;
}

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream file;
    file.open(argv[1]);
    if (file.fail()) {
        std::cout << "The file " << argv[1] << " could not be opened.\n";
        return 1;
    }
    std::string w;
    int count = 0;
    while(file >> w)
    {
        if(w.find(argv[2]) != std::string::npos)
            count++;
    }
    std::cout << "The file " << argv[1] << " contains " << count << " words containing the motive "<< argv[2] <<"\n";
    return 0;
}

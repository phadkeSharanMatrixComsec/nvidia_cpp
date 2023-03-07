#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    #if defined(__linux__) 
    system("nvidia-smi --query-gpu=name --format=csv,noheader > nvidia.txt");

    #elif __APPLE__
    system("ioreg -l | grep model > nvidia.txt");

    #elif WIN32
    system("wmic path win32_VideoController get name > nvidia.txt");

    #else
    cout <<"some other OS!" <<endl;
    #endif

    fstream file;
    file.open("nvidia.txt", ios::in);
    string name = "";

    while(1)
    {
        char temp;
        file >>temp;

        if(file.eof())
            break;

        name += temp;
    }
    

    cout <<"Nvidia GPU Name : " <<name <<endl;

}
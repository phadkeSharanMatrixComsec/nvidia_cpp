#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    cout <<"GPU Model ";
    #if defined(__linux__) 
    system("nvidia-smi --query-gpu=name --format=csv,noheader");

    #elif __APPLE__
    system("ioreg -l | grep model > nvidia.txt");

    #elif WIN32
    system("wmic path win32_VideoController get name > nvidia.txt");

    #else
    cout <<"some other OS!" <<endl;
    #endif

    getchar();

}
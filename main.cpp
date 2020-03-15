#include"mergeSort.h"
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
//int main()
{
    vector<long> supplyVector;
    const char * inputFilePath = argv[1];
    int linesRead = InputInterface::ReadDataIntoVector(inputFilePath, supplyVector);
    if(linesRead)
    {
        cout << "Total Lines Read : " << linesRead << endl;
        unsigned long long int totalInversionCounts = 0;
        Sort::SortData(supplyVector, totalInversionCounts);
        cout << "Total Inversions Present Are:  " << endl;
        cout << totalInversionCounts << endl;
    }
    return 0;
}
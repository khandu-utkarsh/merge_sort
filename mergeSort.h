#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Sort
{
    public:
    Sort(vector<long> &inputVector);
    //Copy Constructor
    Sort(const Sort &obj);

    protected:
    Sort();

    public:
    //Sub Routines
    //This will be returning inversion counts
    static bool SortData(vector<long> &inputData, unsigned long long int &toalInversionsPresent);
    bool MergeSort(int firstIndex, int lastIndex,  unsigned long long int &totalInversionCount);
    bool Merge(int firstIndex, int midIndex, int lastIndex, unsigned long long int &inversionCount);
    const std::vector<long> & GetSortedVector();


    private:
    vector<long> & p_vectorToSort;
    vector<long> p_sortedVector;  //Have to create spaces for the size of the input
};

class InputInterface
{
    public:
    static int ReadDataIntoVector(const char * filePath, std::vector<long> &dataVector);
};
#include"mergeSort.h"
#include<assert.h>
#include<fstream>
#include<string>
Sort::Sort(vector<long> &inputVector) :
        p_vectorToSort(inputVector)
{
    p_sortedVector.reserve(p_vectorToSort.size());
    for(auto &currValue : p_vectorToSort)
        p_sortedVector.push_back(0);
}

//Copy Constructor
Sort::Sort(const Sort &obj) :
        p_vectorToSort(obj.p_vectorToSort)
{
    p_sortedVector = obj.p_sortedVector;
}

bool Sort::SortData(vector<long> &inputData, unsigned long long int &toalInversionsPresent)
{
    int firstIndex = inputData.begin() - inputData.begin();
    int lastIndex =  std::prev(inputData.end()) - inputData.begin();

    Sort sortingObject(inputData);
    bool retValue = sortingObject.MergeSort(firstIndex, lastIndex, toalInversionsPresent);
    vector<long> sortedVector = sortingObject.GetSortedVector();
    return retValue;
}



bool Sort::Merge(int firstIndex, int midIndex, int lastIndex, unsigned long long int &inversionCount)
{
    //First Array will be basically between firstIndex and midIndex - 1;
    //Last Array will be basically between midIndex and lastIndex;
    unsigned long long int currInversionCount = 0;
    int leftCurrIndex = firstIndex;
    int rightCurrIndex = midIndex;
    for(int currIndex = firstIndex; currIndex <= lastIndex; ++currIndex)
    {
        if(leftCurrIndex >= midIndex)
        {
            long rightValue = p_vectorToSort[rightCurrIndex];
            p_sortedVector[currIndex] = rightValue;
            rightCurrIndex++;
        }
        else if(rightCurrIndex > lastIndex)
        {
            long leftValue = p_vectorToSort[leftCurrIndex];
            p_sortedVector[currIndex] = leftValue;
            leftCurrIndex++;
        }
        else
        {
            long leftValue = p_vectorToSort[leftCurrIndex];
            long rightValue = p_vectorToSort[rightCurrIndex];
            if(leftValue <= rightValue)
            {
                p_sortedVector[currIndex] = leftValue;
                currInversionCount += 0;
                leftCurrIndex++;
            }
            else
            {
                p_sortedVector[currIndex] = rightValue;
                int countLeftInFirstArray = midIndex - leftCurrIndex;
                if(countLeftInFirstArray < 0)
                {
                    assert(0);
                    return false;
                } 
                currInversionCount += countLeftInFirstArray;
                rightCurrIndex++;
            }            /* code */
        }
    }
    inversionCount = currInversionCount;
    //Have to update the contents of supplied vector     
    for(int currIndex = firstIndex; currIndex <= lastIndex; ++currIndex)
    {
        p_vectorToSort[currIndex] = p_sortedVector[currIndex];
    }
    return true;
}

bool Sort::MergeSort(int firstIndex, int lastIndex, unsigned long long int &totalInversionCount)
{
    int currSize = lastIndex - firstIndex + 1;
    
    if(currSize == 0)
    {
        assert(0);
        return false;
    }
    if(currSize  == 1)
    {
        return true;
    }
    else
    {
        int midIndex = (firstIndex + lastIndex)/2 + 1;
        bool firstHalfSorted = MergeSort(firstIndex, midIndex - 1, totalInversionCount);
        bool secondHalfSorted = MergeSort(midIndex, lastIndex, totalInversionCount);
        if(firstHalfSorted == false || secondHalfSorted == false)
        {
            assert(0);
        }
        unsigned long long int currLevelInsertionCount = 0;
        bool mergingSuccess = Merge(firstIndex, midIndex, lastIndex, currLevelInsertionCount);
        totalInversionCount += currLevelInsertionCount;
    }
    return true;
}

const std::vector<long> & Sort::GetSortedVector()
{
    return p_sortedVector;
}

int InputInterface::ReadDataIntoVector(const char * filePath, std::vector<long> &dataVector)
{
    std::ifstream readStream(filePath, std::ifstream::in);
    int totalLinesPresent = 0;
    if(readStream.is_open())
    {
        string line;
        while(getline(readStream, line))
        {
            long currData = std::stol(line);
            dataVector.push_back(currData);
            totalLinesPresent++;
        }
    }
    return totalLinesPresent;
}
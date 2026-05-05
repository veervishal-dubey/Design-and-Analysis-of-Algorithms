#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

int findMobile(vector<int>array, vector<int> direction)
{
    int mobileIndex=-1; 
    for (int i=0; i<array.size();i++)
    {
        if (i>0 && direction[i]==-1 && array[i]>array[i-1])
        {    if (mobileIndex==-1||array[i]>array[mobileIndex])
                mobileIndex=i;
        }
       else if (i<array.size()-1 && direction[i]==1 && array[i]>array[i+1])
        {
            if(mobileIndex==-1 || array[i]>array[mobileIndex])
                mobileIndex=i;
    
        }
    }     
    return mobileIndex;
}

void printPermuatation(vector <int> array)
{
    for (int i=0; i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<"\n";
}

void generatePermuation(vector <int> &array, vector<int> &direction)
{
    printPermuatation(array);
    while (true)
    {
        int largest=findMobile(array, direction);
        if (largest==-1)
            break;
        int largestNum=array[largest];
        int swapIdx=largest+direction[largest];
        swap(array[largest], array[swapIdx]);
        swap(direction[largest],direction[swapIdx]);
        for (int i=0; i<array.size();i++)
        {
            if (array[i]>largestNum)
                direction[i]=-1*direction[i];
        }
        printPermuatation(array);
    }
}

int main()
{
    vector<int>nums;
    vector<int>direction;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    for (int i=0; i<n;i++)
    {
        nums.push_back(i+1);
        direction.push_back(-1);
    }
    generatePermuation(nums, direction);
}

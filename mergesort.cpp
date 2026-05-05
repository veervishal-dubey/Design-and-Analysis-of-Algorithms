#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> merge(vector<int>leftSorted, vector<int>rightSorted)
{
    vector<int> Sorted;
    int i=0, j=0, m=leftSorted.size(), n=rightSorted.size();
    while (i<m && j<n)
    {
        if(leftSorted[i]<=rightSorted[j])
        {
            Sorted.push_back(leftSorted[i]);
            i++;
        }
        else
        {
            Sorted.push_back(rightSorted[j]);
            j++;
        }
        
    }
    
    while (i<m)
    {
        Sorted.push_back(leftSorted[i]);
        i++;
    }
    while (j<n)
    {
        Sorted.push_back(rightSorted[j]);
        j++;
    }
    return Sorted;
}

void mergeSort(vector <int> &array)
{
    int arraysize=array.size();
    if (arraysize<=1)
        return;
    else
    {
        int mid=arraysize/2;
        vector<int> leftSide(array.begin(), array.begin()+mid);
        vector<int> rightSide(array.begin()+mid, array.end());
        mergeSort(leftSide);
        mergeSort(rightSide);
        array=merge(leftSide, rightSide);
    }
}
int main()
{
    vector <int> array; 
    int n,element; 
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for (int i=0; i<n;i++)
    {
        cin>>element;
        array.push_back(element);
    }
    mergeSort(array);
    cout<<"Sorted Array: ";
    for (int i=0; i<n;i++)
        cout<<array[i]<<" ";
    return 0;
}

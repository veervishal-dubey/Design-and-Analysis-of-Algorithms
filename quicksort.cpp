#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &array, int left, int right)
{
    int i=left-1; 
    int pivot=array[right];
    for (int j=left; j<right;j++)
    {
        if (array[j]<pivot)
        {
            i++;
            swap(array[i],array[j]);
        }
    }
    swap (array[i+1],array[right]);
    return i+1;
}

void quickSort(vector <int> &array, int left, int right)
{
    if (left<right)
    {
        int parting=partition(array, left, right);
        quickSort(array, left, parting-1);
        quickSort(array, parting+1, right);
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
    quickSort(array, 0, n-1);
    cout<<"Sorted Array: ";
    for (int i=0; i<n;i++)
        cout<<array[i]<<" ";
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;


int find_index(int *arr,int num,int min, int max)
{
    int mid = (min + max)/2;

    if(min == max && num !=arr[mid]) return -1;

    if(num> arr[mid] ) return find_index(arr, num, mid+1, max);
    else if(num<arr[mid]) return find_index(arr,num,min,mid-1);
    return mid;
}

int main()
{
    int arr[10]={15,25,30,65,21,12,31,54,29,47};
    int num;

    cout << "array: ";
    for(int i=0; i<10; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl << "Find index of: ";

    cin >> num;
    sort(arr,arr+10);

    cout << "New array: ";
    for(int i=0; i<10; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;

    cout << "The position: " <<find_index(arr,num,0,10);
}
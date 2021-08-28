#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int purgeDuplicates(int arr[], int n){
    int no_duplicates[n];
    int j=0;
    for (int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1])
            no_duplicates[j++] = arr[i];
    }
    no_duplicates[j++] = arr[n-1];
    for (int i=0; i<j; i++)
        arr[i] = no_duplicates[i];
    return j;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int ARRAY_SIZE = 10;
    int VALUE_RANGE = 8;
    int arr_insertion_sort[ARRAY_SIZE];
    for(int i=0 ; i<ARRAY_SIZE; i++){
        int random_element = rand()%VALUE_RANGE+1;
        arr_insertion_sort[i] = random_element;
    }

    cout << "Insertion Sort" << endl;
    printArray(arr_insertion_sort, ARRAY_SIZE);
    const clock_t begin_time = clock();
    insertionSort(arr_insertion_sort, ARRAY_SIZE);
    std::cout << "Finish InsertionSort:" << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
    printArray(arr_insertion_sort, ARRAY_SIZE);
    int NEW_SIZE = purgeDuplicates(arr_insertion_sort,ARRAY_SIZE);
    cout << "No duplicates sorted array: " << endl;
    printArray(arr_insertion_sort,NEW_SIZE);
    return 0;
}

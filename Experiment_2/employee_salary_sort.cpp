#include <iostream>
using namespace std;

class Employee
{
public:
    void merge(int arr[], int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        int k = 0;

        int temp[100];

        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= high)
            temp[k++] = arr[j++];

        for (i = low, k = 0; i <= high; i++, k++)
            arr[i] = temp[k];
    }

    void mergeSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;

            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);

            merge(arr, low, mid, high);
        }
    }

    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void display(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    Employee employee;
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    int *salary = new int[n];

    cout << "Enter employee salaries:" << endl;

    for (int i = 0; i < n; i++)
        cin >> salary[i];

    int *quickArray = new int[n];
    int *mergeArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        quickArray[i] = salary[i];
        mergeArray[i] = salary[i];
    }

    employee.quickSort(quickArray, 0, n - 1);
    employee.mergeSort(mergeArray, 0, n - 1);

    cout << "\nSorted Salaries using Quick Sort: ";
    employee.display(quickArray, n);

    cout << "Sorted Salaries using Merge Sort: ";
    employee.display(mergeArray, n);

    delete[] salary;
    delete[] quickArray;
    delete[] mergeArray;

    return 0;
}
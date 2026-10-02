#include <iostream>
using namespace std;

class Hospital
{
public:
    int binarySearch(int arr[], int low, int high, int key)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);

        return binarySearch(arr, mid + 1, high, key);
    }
};

int main()
{
    Hospital hospital;
    int n, key;

    cout << "Enter number of patients: ";
    cin >> n;

    int *patientID = new int[n];

    cout << "Enter Patient IDs in sorted order:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> patientID[i];
    }

    cout << "Enter Patient ID to search: ";
    cin >> key;

    int result = hospital.binarySearch(patientID, 0, n - 1, key);

    if (result != -1)
        cout << "Patient ID " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "Patient ID " << key << " not found." << endl;

    delete[] patientID;

    return 0;
}
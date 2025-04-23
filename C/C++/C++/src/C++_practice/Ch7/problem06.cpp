#include <iostream>

int Fill_array(double* arr, int size) {
    using namespace std;
    
    int cnt = 0;
    cout << "Enter the number of arr filled:\n";
    double n;
    for (int i = 0; i < size; i++) {
        cin >> n;
        arr[i] = n;
    }
    return cnt;
}

void Show_array(double* arr, int size) {
    using namespace std;
    
    cout << "Value of the array\n";
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i != size - 1)
            cout << arr[i] << ", ";
        else 
            cout << arr[i] << "]";
        if (i % 5 == 4) {
            cout << endl;
        }
    }
}

void Reverse_array(double* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        double temp = arr[i];
        arr[i] = arr[size -1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    using namespace std;

    double arr[5];

    Fill_array(arr, 5);
    Show_array(arr, 5);
    Reverse_array(arr, 5);
    Show_array(arr, 5);
    
    Reverse_array(arr, 5);
    double temp = arr[0];
    arr[0] = arr[4];
    arr[4] = temp;
    Show_array(arr, 5);

    return 0; 
}
       

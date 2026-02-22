#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int n = 100000;
    vector<int> datos(n);
    for(int i=0; i<n; i++) datos[i] = rand() % 10000;

    auto inicio = high_resolution_clock::now();
    mergeSort(datos, 0, n - 1);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "MergeSort con " << n << " elementos tardo: " << duracion.count() << " ms" << endl;

    return 0;
}
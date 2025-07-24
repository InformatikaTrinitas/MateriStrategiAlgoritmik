#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mencetak array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

// Fungsi untuk menggabungkan dua subarray
void merge(int array[], int l, int mid, int h) {
    int i, j, k;
    int n1 = mid - l + 1; // panjang subarray kiri
    int n2 = h - mid;     // panjang subarray kanan

    // Buat array sementara
    int left[n1], right[n2];

    // Salin data ke array sementara
    for (i = 0; i < n1; i++) {
        left[i] = array[l + i];
    }

    for (j = 0; j < n2; j++) {
        right[j] = array[mid + 1 + j];
    }

    i = 0; // indeks pertama subarray kiri
    j = 0; // indeks pertama subarray kanan
    k = l; // indeks awal dari array gabungan

    // Gabungkan array kiri dan kanan
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    // Salin sisa elemen dari left[], jika ada
    while (i < n1) {
        array[k++] = left[i++];
    }

    // Salin sisa elemen dari right[], jika ada
    while (j < n2) {
        array[k++] = right[j++];
    }
}

// Fungsi rekursif untuk Merge Sort
void mergesort(int array[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;

        // Urutkan kedua bagian
        mergesort(array, l, mid);
        mergesort(array, mid + 1, h);

        // Gabungkan hasilnya
        merge(array, l, mid, h);
    }
}

int main() {
    int array[7] = {10, 3, 12, 32, 7, 20, 4};

    mergesort(array, 0, 6);

    printf("Array setelah diurutkan:\n");
    print_array(array, 7);

    return 0;
}

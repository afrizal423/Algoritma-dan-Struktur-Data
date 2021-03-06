[**KEMBALI**](../README.md)

# Algoritma

**File ini berisi materi:**

> Klik salah satu untuk menuju ke pembahasan

1. [Mengimplementasikan Algoritma Pencarian Beruntun (*Sequential Search*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Algoritma.md#1-mengimplementasikan-algoritma-pencarian-beruntun-sequential-search)
2. [Mengimplementasikan Algoritma Pencarian Bagi-Dua (*Binary Search*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Algoritma.md#2-mengimplementasikan-algoritma-pencarian-bagi-dua-binary-search)
3. [Mengimplementasikan Algoritma Pengurutan Gelembung (*Bubble Sort*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Algoritma.md#3-mengimplementasikan-algoritma-pengurutan-gelembung-bubble-sort)
4. [Mengimplementasikan Algoritma Pengurutan Seleksi (*Selection Sort*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Algoritma.md#4-mengimplementasikan-algoritma-pengurutan-seleksi-selection-sort)
5. [Mengimplementasikan Algoritma Pengurutan Sisipan (*Insertion Sort*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Algoritma.md#5-mengimplementasikan-algoritma-pengurutan-sisipan-insertion-sort)
6. [Mengimplementasikan Algoritma Pengurutan Shell (*Shell Sort*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Algoritma.md#6-mengimplementasikan-algoritma-pengurutan-shell-shell-sort)

![alt text](../Images/algo.jpg)

---

## 1. Mengimplementasikan Algoritma Pencarian Beruntun (*Sequential Search*)

**Kasus**

Kita ingin melakukan pencarian data di dalam suatu *array*, kita bisa menggunakan algoritma pencarian beruntun (*sequential search*).

**Solusi**

Di dalam bahasa C, algoritma pencarian berutun dapat diimplementasikan menggunakan fungsi berikut:

```c
bool sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            ++pos;
    }

    return found;
}
```

Contoh penggunaan dari fungsi di atas dapat dilihat pada kode program di bawah ini:

- **Contoh_1.c** [Link to File](../src/Algoritma/Contoh_1.c)

```c
#include <stdio.h>
#include <stdbool.h>

bool sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            ++pos;
    }

    return found;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int data[5] = {300, 200, 500, 400, 100};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen dari array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nNilai 200 %s\n", sequential_search(data, size, 200) ? "ditemukan" : "tidak ditemukan");
    printf("Nilai 400 %s\n", sequential_search(data, size, 400) ? "ditemukan" : "tidak ditemukan");
    printf("Nilai 700 %s\n", sequential_search(data, size, 700) ? "ditemukan" : "tidak ditemukan");
    printf("Nilai 900 %s\n", sequential_search(data, size, 900) ? "ditemukan" : "tidak ditemukan");

    return 0;
}
```

Hasil Program:

```
Isi array: [300, 200, 500, 400, 100]

Nilai 200 ditemukan
Nilai 400 ditemukan
Nilai 700 tidak ditemukan
Nilai 900 tidak ditemukan
```

**Penjelasan**

Dengan menggunakan metode pencarian beruntun (*sequential search*) atau yang juga disebut dengan pencarian lurus (*linear search*), nilai yang dicari dibandingkan dengan nilai dari setiap elemen *array* data, mulai dari elemen pertama sampai nilai yang dicari ditemukan atau sampai elemen terakhir.

Pada contoh kode program di atas, fungsi `sequential_search()` akan mengembalikan nilai `true` jika nilai yang dicari ditemukan di dalam *array* data dan `false` jika tidak ditemukan. Pada beberapa kasus, terkadang kita ingin mengetahui indeks dari nilai yang ditemukan, bukan hanya sekedar informasi `true` atau `false` saja. Untuk memenuhi kebutuhan seperti ini, kita dapat memodifikasi kode di atas menjadi seperti berikut:

- **Contoh_2.c** [Link to File](../src/Algoritma/Contoh_2.c)

```c
#include <stdio.h>
#include <stdbool.h>

int sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            ++pos;
    }

    return found ? pos : -1;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int data[5] = {300, 200, 500, 400, 100};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen dari array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nNilai 200: %d\n", sequential_search(data, size, 200));
    printf("Nilai 400: %d\n", sequential_search(data, size, 400));
    printf("Nilai 700: %d\n", sequential_search(data, size, 700));
    printf("Nilai 900: %d\n", sequential_search(data, size, 900));

    return 0;
}
```

Hasil program:

```
Isi array: [300, 200, 500, 400, 100]

Nilai 200: 1
Nilai 400: 3
Nilai 700: -1
Nilai 900: -1
```

Nilai -1 yang terdapat pada hasil di atas digunakan untuk mendandakan bahwa nilai yang dicari tidak ditemukan di dalam *array* data.

Dua kode program yang di atas sebenarnya dapat diterapkan untuk *array* yang datanya terurut maupun tidak terurut. Akan tetapi untuk kasus *array* yang datanya terurut kita dapat melakukan penghematan proses pencarian, yaitu dengan menghentikan pencarian ketika nilai yang kita cari lebih kecil dari salah satu nilai *array* pada posisi tertentu (ini pada *array* terurut) atau dengan kata lain mencegah proses agar tidak melanjutkan pencarian sampai akhir data (tidak perlu dicari sampai akhir jika data yang diinginkan sudah ketemu), pada kasus ini, untuk data yang berjumlah kecil tidak akan terasa lama prosesnya, tapi untuk data yang berjumlah sangat besar akan baru terasa lama prosesnya. Untuk mengimplementasikan hal ini kita dapat menggunakan kode berikut:

- **Contoh_3.c** [Link to File](../src/Algoritma/Contoh_3.c)

```c
#include <stdio.h>
#include <stdbool.h>

int sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false, stop = false;

    while (pos < size && !found && !stop) {
        if (array[pos] == value)
            found = true;
        else
            if (array[pos] > value)
                stop = true;
            else
                ++pos;
    }

    return found ? pos : -1;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int data[5] = {100, 200, 300, 400, 500};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen dari array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nNilai 100: %d\n", sequential_search(data, size, 100));
    printf("Nilai 250: %d\n", sequential_search(data, size, 250));
    printf("Nilai 300: %d\n", sequential_search(data, size, 300));
    printf("Nilai 700: %d\n", sequential_search(data, size, 700));

    return 0;
}
```

Hasil program:

```
Isi array: [100, 200, 300, 400, 500]

Nilai 100: 0
Nilai 250: -1
Nilai 300: 2
Nilai 700: -1
```

Ketika mencari nilai 250, proses perbandingan hanya dilakukan 2 kali, yaitu perbandingan nilai antara 250 dengan elemen pertama & elemen kedua di dalam *array* data. Pada saat indeks pengulangan (variabel `pos`) mencapai 2, proses pengulangan akan dihentikan. Hal ini disebabkan karena nilai elemen pada indeks ke-2 (nilai 300) lebih besar dari nilai yang dicari (nilai 250). Hal ini tentu akan menghemat proses pencarian.

---

## 2. Mengimplementasikan Algoritma Pencarian Bagi-Dua (*Binary Search*)

**Kasus**

Kita ingin melakukan pencarian data di dalam suatu *array* menggunakan algoritma pencarian bagi-dua (*Binary Search*).

**Solusi**

Di dalam bahasa C, algoritma pencarian bagi-dua diimplementasikan menggunakan fungsi berikut:

```c
int binary_search(int array[], int first, int last, int value) {
    int middle;
    bool found = false;

    while (first <= last && !found) {
        middle = (first + last) / 2;

        if (array[middle] == value)
            found = true;
        else
            if (value < array[middle])
                last = middle - 1;
            else
                first = middle + 1;
    }

    return found ? middle : -1;
}
```

Contoh kode program di bawah ini menunjukkan penggunaan fungsi di atas:

- **Contoh_4.c** [Link to File](../src/Algoritma/Contoh_4.c)

```c
#include <stdio.h>
#include <stdbool.h>

int binary_search(int array[], int first, int last, int value) {
    int middle;
    bool found = false;

    while (first <= last && !found) {
        middle = (first + last) / 2;

        if (array[middle] == value)
            found = true;
        else
            if (value < array[middle])
                last = middle - 1;
            else
                first = middle + 1;
    }

    return found ? middle : -1;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

main(int argc, char const *argv[]) {
    int data[5] = {100, 200, 300, 400, 500};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nIndeks dari nilai 200: %d\n", binary_search(data, 0, 4, 200));
    printf("Indeks dari nilai 400: %d\n", binary_search(data, 0, 4, 400));
    printf("Indeks dari nilai 700: %d\n", binary_search(data, 0, 4, 700));
    printf("Indeks dari nilai 900: %d\n", binary_search(data, 0, 4, 900));

    return 0;
}
```

Hasil program:

```
Isi array: [100, 200, 300, 400, 500]

Indeks dari nilai 200: 1
Indeks dari nilai 400: 3
Indeks dari nilai 700: -1
Indeks dari nilai 900: -1
```

**Penjelasan**

Metode pencarian bagi-dua harus diterapkan untuk *array* yang datanya sudah berada dalam keadaan terurut. Maka, sebelum digunakan di dalam proses pencarian, kita perlu memastikan bahwa data di *array* telah terurut. Proses pengurutan dapat dilakukan dengan mendefinisikan fungsi lain (jika perlu).

Cara kerja algoritma pencarian bagi-dua adalah dengan membagi elemen-elemen *array* menjadi 2 bagian secara berulang. Jika elemen tengah (`array[middle]`) sama dengan nilai yang dicari (`value`), maka proses pencarian dihentikan dan nilai `middle` (indeks dari elemen tengah) dinyatakan sebagai hasil. Jika nilai yang dicari lebih kecil dari elemen tengah, maka proses pencarian dilakukan pada *array* sebelah kiri. Jika lebih besar, maka proses pencarian dilakukan pada bagian *array* sebelah kanan; dengan asumsi bahwa elemen-elemen *array* terurut secara menaik (*ascending*)

Algoritma pencarian bagi-dua juga dapat diimplementasikan menggunakan fungsi rekursi, seperti kode di bawah ini:

```c
int binary_search(int array[], int first, int last, int value) {
    if (last < first)
        return -1;

    int middle = (first + last) / 2;

    if (value < array[middle])
        return binary_search(array, first, middle - 1, value);
    else if (value > array[middle])
        return binary_search(array, middle + 1, last, value);
    else
        return middle;
}
```

Contoh penerapannya dapat dilihat pada kode di bawah ini:

- **Contoh_5.c** [Link to File](../src/Algoritma/Contoh_5.c)

```c
#include <stdio.h>
#include <stdbool.h>

int binary_search(int array[], int first, int last, int value) {
    if (last < first)
        return -1;

    int middle = (first + last) / 2;

    if (value < array[middle])
        return binary_search(array, first, middle - 1, value);
    else if (value > array[middle])
        return binary_search(array, middle + 1, last, value);
    else
        return middle;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

main(int argc, char const *argv[]) {
    int data[5] = {100, 200, 300, 400, 500};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nIndeks dari nilai 200: %d\n", binary_search(data, 0, 4, 200));
    printf("Indeks dari nilai 400: %d\n", binary_search(data, 0, 4, 400));
    printf("Indeks dari nilai 700: %d\n", binary_search(data, 0, 4, 700));
    printf("Indeks dari nilai 900: %d\n", binary_search(data, 0, 4, 900));

    return 0;
}
```

Hasil program:

```
Isi array: [100, 200, 300, 400, 500]

Indeks dari nilai 200: 1
Indeks dari nilai 400: 3
Indeks dari nilai 700: -1
Indeks dari nilai 900: -1
```

---

## 3. Mengimplementasikan Algoritma Pengurutan Gelembung (*Bubble Sort*)

**Kasus**

Kita ingin melakukan pengurutan data di dalam suatu *array* menggunakan algoritma pengurutan gelembung (*bubble sort*)

**Solusi**

Dalam bahasa C, algoritma pengurutan gelembung dapat diimplementasikan menggunakan fungsi berikut:

```c
void bubble_sort(int *array, int size) {
    int temp;

    for (int i = 0; i < size - 1; ++i)
        for (int j = size - 1; j > i; --j)
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
}
```

Contoh penggunaan fungsi `bubble_sort()` di atas dapat dilihat pada kode program di bawah ini:

- **Contoh_6.c** [Link to File](../src/Algoritma/Contoh_6.c)

```c
#include <stdio.h>

void bubble_sort(int *array, size_t size) {
    int temp;

    for (int i = 0; i < size - 1; ++i)
        for (int j = size - 1; j > i; --j)
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

main(int argc, char const *argv[]) {
    int data[8] = {9, 7, 10, 8, 12, 11, 14, 13};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    bubble_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [9, 7, 10, 8, 12, 11, 14, 13]
Setelah diurutkan: [7, 8, 9, 10, 11, 12, 13, 14]
```

**Penjelasan**

Dalam proses pengurutan data menggunakan algoritma gelembung, n elemen data akan diurutkan melalui n-1 langkah (direpresentasikan menggunakan variabel `i`). Dalam setiap langkah, program akan membandingkan elemen ke-`j` dengan elemen ke-(`j-1`) secara berulang mulai dari elemen terakhir sampai elemen ke-(`i+1`). Jika `array[j]` lebih kecil dari `array[j-1]` maka kedua elemen tersebut akan ditukar menggunakan kode berikut:

```c
temp = array[j];
array[j] = array[j - 1];
array[j - 1] = temp;
```

![alt text](../Images/swap_integers_without_additional_variable.jpg)

Elemen yang sudah terurut pada langkah pertama akan diisolasi dan tidak akan dilibatkan dalam proses perbandingan elemen di langkah kedua. Elemen yang sudah terurut pada langkah kedua tidak akan dilibatkan dalam proses perbandingan di langkah ketiga, dan seterusnya.

Untuk memudahkan dalam memahami cara kerja algoritma pengurutan gelembung kita dapat mengubah kode program sebelumnya menjadi seperti berikut:

- **Contoh_7.c** [Link to File](../src/Algoritma/Contoh_7.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int *array, size_t size) {
    int temp;

    for (int i = 0; i < size - 1; ++i) {
        printf("Langkah ke-%d: ", i + 1);

        for (int j = size - 1; j > i; --j)
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        
        print_array(array, size);
    }
}

main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    bubble_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [12, 10, 6, 11, 5, 4, 7, 9, 8]

Langkah ke-1: [4, 12, 10, 6, 11, 5, 7, 8, 9]
Langkah ke-2: [4, 5, 12, 10, 6, 11, 7, 8, 9]
Langkah ke-3: [4, 5, 6, 12, 10, 7, 11, 8, 9]
Langkah ke-4: [4, 5, 6, 7, 12, 10, 8, 11, 9]
Langkah ke-5: [4, 5, 6, 7, 8, 12, 10, 9, 11]
Langkah ke-6: [4, 5, 6, 7, 8, 9, 12, 10, 11]
Langkah ke-7: [4, 5, 6, 7, 8, 9, 10, 12, 11]
Langkah ke-8: [4, 5, 6, 7, 8, 9, 10, 11, 12]

Setelah diurutkan: [4, 5, 6, 7, 8, 9, 10, 11, 12]
```

Pada contoh program di atas kita mengurutkan data yang elemennya berjumlah 9. Oleh karena itu, diperlukan 8 langkah untuk mengurutkan data tersebut. Posisi elemen pada setiap langkah dapat kita lihat pada hasil yang ditampilkan di atas.

Metode yang digunakan di atas adalah dengan menempatkan elemen terkecil di posisi paling kiri. Setelah itu elemen tersebut diisolasi atau diikat dan tidak dilibatkan pada proses berikutnya. Dalam metode tersebut, elemen-elemen kiri merupakan elemen-elemen yang sudah terurut. Kita juga dapat menggunakan metode lain untuk mengimplementasikan algoritma pengurutan gelembung, yaitu dengan menempatkan elemen terbesar di posisi paling kanan dan elemen tersebut tidak dilibatkan pada proses berikutnya. Dengan cara seperti ini, elemen-elemen kanan akan menjadi elemen-elemen yang pertama kali diurutkan. Kode di bawah ini akan menunjukan konsep tersebut:

```c
void bubble_sort(int *array, size_t size) {
    int temp;

    for (int i = size - 1; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}
```

Jika ingin melihat posisi elemen-elemen pada setiap langkah, kita dapat mengubah kode di atas menjadi seperti berikut:

- **Contoh_8.c** [Link to File](../src/Algoritma/Contoh_8.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int *array, size_t size) {
    int temp, step = 1;

    for (int i = size - 1; i > 0; --i) {
        printf("Langkah ke-%d: ", step);

        for (int j = 0; j < i; ++j)
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        
        print_array(array, size);
        ++step;
    }
}

main(int argc, char const *argv[]) {
    int data[7] = {14, 13, 12, 11, 10, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    bubble_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [14, 13, 12, 11, 10, 9, 8]

Langkah ke-1: [13, 12, 11, 10, 9, 8, 14]
Langkah ke-2: [12, 11, 10, 9, 8, 13, 14]
Langkah ke-3: [11, 10, 9, 8, 12, 13, 14]
Langkah ke-4: [10, 9, 8, 11, 12, 13, 14]
Langkah ke-5: [9, 8, 10, 11, 12, 13, 14]
Langkah ke-6: [8, 9, 10, 11, 12, 13, 14]

Setelah diurutkan: [8, 9, 10, 11, 12, 13, 14]
```

Seperti yang kita lihat pada hasil di atas, kali ini nilai terbesar yang akan diproses terlebih dahulu untuk ditempatkan pada posisi paling kanan. Dalam contoh di atas, pada langkah pertama program akan menempatkan nilai 14 pada posisi paling kanan. Pada langkah kedua, nilai 14 tidak dilibatkan lagi, sehingga nilai terbesarnya menjadi 13. Nilai 13 tersebut kemudian ditempatkan di sebelah kiri nilai 14. Pada langkah ketiga, nilai 13 juga tidak dilibatkan lagi dalam proses pengurutan. Demikian seterusnya semua elemen berada pada posisi yang tepat.

---

## 4. Mengimplementasikan Algoritma Pengurutan Seleksi (*Selection Sort*)

**Kasus**

Kita ingin melakukan pengurutan data di dalam suatu *array* dengan menggunakan algoritma pengurutan seleksi (*selection sort*)

**Solusi**

Algoritma pengurutan seleksi dapat diimplementasikan dengan menggunakan fungsi berikut:

```c
void selection_sort(int *array, int size) {
    int minposition, temp;

    for (int i = 0; i < size - 1; ++i) {
        minposition = size - 1;

        for (int j = size - 2; j > i - 1; --j)
            if (array[j] < array[minposition])
                minposition = j;

        temp = array[i];
        array[i] = array[minposition];
        array[minposition] = temp;
    }
}

```

Contoh penggunaan fungsi `selection_sort()` di atas dapat dilihat pada kode program di bawah ini:

- **Contoh_9.c** [Link to File](../src/Algoritma/Contoh_9.c)

```c
#include <stdio.h>

void selection_sort(int *array, int size) {
    int minposition, temp;

    for (int i = 0; i < size - 1; ++i) {
        minposition = size - 1;

        for (int j = size - 2; j > i - 1; --j)
            if (array[j] < array[minposition])
                minposition = j;

        temp = array[i];
        array[i] = array[minposition];
        array[minposition] = temp;
    }
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

main(int argc, char const *argv[]) {
    int data[8] = {9, 7, 10, 8, 12, 11, 14 , 13};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    selection_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil Program:

```
Sebelum diurutkan: [9, 7, 10, 8, 12, 11, 14, 13]
Setelah diurutkan: [7, 8, 9, 10, 11, 12, 13, 14]
```

**Penjelasan**

Pada algoritma pengurutan seleksi, kita mencari posisi dari elemen terkecil. Proses pencarian itu sendiri dilakukan dari elemen terakhir atau paling kanan sampai elemen pertama atau paling kiri. Setelah ditemukannya posisi dari elemen terkecil, elemen pada posisi tersebut ditukar dengan elemen paling kiri. Selanjutnya, elemen tersebut akan diisolasi dan tidak dilibatkan pada proses berikutnya. Proses ini akan diulang sampai semua elemen di dalam *array* terurut. Jumlah langkah yang dibutuhkan pada algoritma pengurutan seleksi sama dengan jumlah langkah pada algoritma pengurutan gelembung, yaitu n-1, dengan n adalah jumlah elemen yang terdapat di dalam *array*. Perbedaannya, proses pertukaran elemen pada setiap langkah di dalam algoritma pengurutan seleksi hanya dilakukan sekali.

Untuk mengetahui posisi elemen pada setiap langkah, kita dapat mengubah kode program di atas menjadi seperti berikut:

- **Contoh_10.c** [Link to File](../src/Algoritma/Contoh_10.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void selection_sort(int *array, int size) {
    int minposition, temp;

    for (int i = 0; i < size - 1; ++i) {
        printf("Langkah ke-%d: ", i + 1);

        minposition = size - 1;

        for (int j = size - 2; j > i - 1; --j)
            if (array[j] < array[minposition])
                minposition = j;

        temp = array[i];
        array[i] = array[minposition];
        array[minposition] = temp;

        print_array(array, size);
    }
}

main(int argc, char const *argv[]) {
    int data[8] = {9, 7, 10, 8, 12, 11, 14 , 13};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    selection_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil Program:

```
Sebelum diurutkan: [9, 7, 10, 8, 12, 11, 14, 13]

Langkah ke-1: [7, 9, 10, 8, 12, 11, 14, 13]
Langkah ke-2: [7, 8, 10, 9, 12, 11, 14, 13]
Langkah ke-3: [7, 8, 9, 10, 12, 11, 14, 13]
Langkah ke-4: [7, 8, 9, 10, 12, 11, 14, 13]
Langkah ke-5: [7, 8, 9, 10, 11, 12, 14, 13]
Langkah ke-6: [7, 8, 9, 10, 11, 12, 14, 13]
Langkah ke-7: [7, 8, 9, 10, 11, 12, 13, 14]

Setelah diurutkan: [7, 8, 9, 10, 11, 12, 13, 14]
```

Metode lain yang dapat digunakan untuk mengimplementasikan algoritma pengurutan seleksi adalah dengan mencari posisi dari elemen terbesar. Selanjutnya, elemen terbesar tersebut ditempatkan pada posisi paling kanan. Untuk melakukan hal ini, kita dapat menggunakan kode berikut:

```c
void selection_sort(int *array, int size) {
    int maxposition, temp;

    for (int i = size - 1; i > 0; --i) {
        maxposition = 0;

        for (int j = 1; j < i + 1; ++j)
            if (array[j] > array[maxposition])
                maxposition = j;

        temp = array[i];
        array[i] = array[maxposition];
        array[maxposition] = temp;
    }
}
```

Contoh penggunaan dari fungsi di atas adalah sebagai berikut:

- **Contoh_11.c** [Link to File](../src/Algoritma/Contoh_11.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void selection_sort(int *array, int size) {
    int maxposition, temp, step = 1;

    for (int i = size - 1; i > 0; --i) {
        printf("Langkah ke-%d: ", step);

        maxposition = 0;

        for (int j = 1; j < i + 1; ++j)
            if (array[j] > array[maxposition])
                maxposition = j;

        temp = array[i];
        array[i] = array[maxposition];
        array[maxposition] = temp;

        print_array(array, size);
        ++step;
    }
}

main(int argc, char const *argv[]) {
    int data[8] = {9, 7, 10, 8, 12, 11, 14 , 13};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    selection_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

---

## 5. Mengimplementasikan Algoritma Pengurutan Sisipan (*Insertion Sort*)

**Kasus**

Kita ingin melakukan pengurutan data di dalam suatu *array* dengan menggunakan algoritma pengurutan sisipan (*insertion sort*)

**Solusi**

Di dalam bahasa C, algoritma pengurutan sisipan dapat diimplementasikan menggunakan fungsi berikut:

```c
void insertion_sort(int *array, size_t size) {
    int currentvalue, position;

    for (int i = 1; i < size; ++i) {
        currentvalue = array[i];
        position = i;

        
        while (position > 0 && array[position - 1] > currentvalue) {
            array[position] = array[position - 1];
            --position;
        }
        
        array[position] = currentvalue;
    }
}
```

Contoh penggunaannya dapat dilihat pada kode program di bawah ini:

- **Contoh_12.c** [Link to File](../src/Algoritma/Contoh_12.c)

```c
#include <stdio.h>

void insertion_sort(int *array, size_t size) {
    int currentvalue, position;

    for (int i = 1; i < size; ++i) {
        currentvalue = array[i];
        position = i;

        while (position > 0 && array[position - 1] > currentvalue) {
            array[position] = array[position - 1];
            --position;
        }
        
        array[position] = currentvalue;
    }
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    insertion_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [12, 10, 6, 11, 5, 4, 7, 9, 8]
Setelah diurutkan: [4, 5, 6, 7, 8, 9, 10, 11, 12]
```

**Penjelasan**

Pada algoritma pengurutan sisipan, program akan menyisipkan suatu elemen *array* pada posisi yang sesuai. Posisi tersebut dicari dengan cara membandingkan suatu elemen dengan elemen-elemen sebelumnya. Pada algoritma ini, mula-mula elemen pertama dianggap telah berada pada posisi yang tepat. Selanjutnya, elemen kedua akan dibandingkan dengan elemen pertama. Jika elemen pertama lebih besar dari elemen kedua, maka elemen pertama akan digeser menjadi elemen kedua dan elemen kedua sebelumnya akan disisipkan pada posisi pertama. Setelah itu, elemen ketiga akan dibandingkan dengan elemen kedua dan pertama. Jika elemen kedua lebih besar dari elemen ketiga, maka elemen kedua akan digeser ke kanan. Selanjutnya, elemen ketiga akan dibandingkan lagi dengan elemen pertama. Jika elemen pertama lebih besar dari elemen ketiga, maka elemen pertama juga akan digeser ke kanan dan elemen ketiga akan disisipkan pada posisi pertama. Jika elemen pertama lebih kecil dari elemen ketiga, maka elemen ketiga akan disisipkan pada posisi kedua. Demikian seterusnya sampai semua elemen di dalam *array* diproses.

Untuk lebih mudah dalam memahami proses di dalam algoritma pengurutan sisipan, kita dapat mengubah kode program di atas menjadi seperti berikut:

- **Contoh_13.c** [Link to File](../src/Algoritma/Contoh_13.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void insertion_sort(int *array, size_t size) {
    int currentvalue, position;

    for (int i = 1; i < size; ++i) {
        currentvalue = array[i];
        position = i;
        printf("Menyisipkan nilai %d\t: ", currentvalue);
        
        while (position > 0 && array[position - 1] > currentvalue) {
            array[position] = array[position - 1];
            --position;
        }
        
        array[position] = currentvalue;
        print_array(array, size);
    }
}

int main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    insertion_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan       : [12, 10, 6, 11, 5, 4, 7, 9, 8]

Menyisipkan nilai 10    : [10, 12, 6, 11, 5, 4, 7, 9, 8]
Menyisipkan nilai 6     : [6, 10, 12, 11, 5, 4, 7, 9, 8]
Menyisipkan nilai 11    : [6, 10, 11, 12, 5, 4, 7, 9, 8]
Menyisipkan nilai 5     : [5, 6, 10, 11, 12, 4, 7, 9, 8]
Menyisipkan nilai 4     : [4, 5, 6, 10, 11, 12, 7, 9, 8]
Menyisipkan nilai 7     : [4, 5, 6, 7, 10, 11, 12, 9, 8]
Menyisipkan nilai 9     : [4, 5, 6, 7, 9, 10, 11, 12, 8]
Menyisipkan nilai 8     : [4, 5, 6, 7, 8, 9, 10, 11, 12]

Setelah diurutkan       : [4, 5, 6, 7, 8, 9, 10, 11, 12]
```

---

## 6. Mengimplementasikan Algoritma Pengurutan Shell (*Shell Sort*)

**Kasus**

Kita ingin melakukan pengurutan data di dalam suatu *array* dengan menggunakan algoritma pengurutan *Shell* (*shell sort*)

**Solusi**

Algoritma pengurutan *Shell* dapat diimplementasikan dengan menggunakan dua fungsi berikut:

```c
void insertion_sort(int *array, size_t size, int start, int step) {
    int currentvalue, position;

    for (int i = start + step; i < size; i += step) {
        currentvalue = array[i];
        position = i;
        
        while (position >= step && array[position - step] > currentvalue) {
            array[position] = array[position - step];
            position -= step;
        }

        array[position] = currentvalue;
    }
}

void shell_sort(int *array, size_t size) {
    int step = size / 2;

    while (step > 0) {
        for (int i = 0; i < step; ++i)
            insertion_sort(array, size, i, step);

        step /= 2;
    }
}
```

Contoh penggunaan fungsi 'shell_sort()' dapat dilihat pada kode program di bawah ini:

- **Contoh_14.c** [Link to File](../src/Algoritma/Contoh_14.c)

```c
#include <stdio.h>

void insertion_sort(int *array, size_t size, int start, int step) {
    int currentvalue, position;

    for (int i = start + step; i < size; i += step) {
        currentvalue = array[i];
        position = i;
        
        while (position >= step && array[position - step] > currentvalue) {
            array[position] = array[position - step];
            position -= step;
        }

        array[position] = currentvalue;
    }
}

void shell_sort(int *array, size_t size) {
    int step = size / 2;

    while (step > 0) {
        for (int i = 0; i < step; ++i)
            insertion_sort(array, size, i, step);

        step /= 2;
    }
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    shell_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [12, 10, 6, 11, 5, 4, 7, 9, 8]
Setelah diurutkan: [4, 5, 6, 7, 8, 9, 10, 11, 12]
```

**Penjelasan**

Algoritma pengurutan *Shell* merupakan bentuk penyederhanaan dari algoritma pengurutan sisipan. Dengan demikian, pada dasarnya pengurutan *Shell* juga menggunakan algoritma pengurutan sisipan. Namun, dalam algoritma pengurutan *Shell*, elemen-elemen *array* dibagi menjadi beberapa *sub_array*. Selanjutnya, setiap *sub_array* tersebut diurutkan menggunakan algoritma sisipan. Hal ini bertujuan untuk mengurangi banyaknya proses pergeseran elemen yang terjadi di dalam algoritma pengurutan sisipan.

![alt text](../Images/sort_array.jpg)

---

> Raharjo, Budi. 2016. Kumpulan Solusi Pemrograman C. Bandung: INFORMATIKA.

#include <iostream>
#include <vector>

template <typename T>
void debug(const T& o);

template <typename T>
void printStructure(const std::vector<T>& A);

template <typename T>
void csere(T& x, T& y);

template <typename T>
void bubbleSort(std::vector<T> A);

template <typename T>
void insertSort(std::vector<T> A);

template <typename T>
int maxker(std::vector<T> A, int n);

template <typename T>
void maxKivSort(std::vector<T> A);

template <typename T>
void doTheMerge(std::vector<T>& A, std::vector<T>& B, int k, int u, int v);

template <typename T>
void merge1(std::vector<T>& A, std::vector<T>& B, int u, int v);

template <typename T>
void mergeSort(std::vector<T>& A);

template <typename T>
int cut(std::vector<T>& A, int p, int r);

template <typename T>
void quickSort(std::vector<T>& A, int p, int r);

int main() {
    std::vector<int> A = {8,2,3,11,4,5,9,7,1,6,10};
    //std::vector<int> t = {3, 8, 7, 4, 6, 1, 9, 0, 2, 5};
    //std::cout << "Bubble sort" << std::endl;
    //bubbleSort(t);
    //std::cout << "Insertion sort" << std::endl;
    //insertSort(t);
    //std::cout << "Bubble sort" << std::endl;
    //maxKivSort(t);
    //std::cout << "Merge sort" << std::endl;
    //mergeSort(A);
    std::cout << "Quick sort" << std::endl;
    quickSort(A, 0, A.size());

    return 0;
}

template <typename T>
void debug(const T& o) {
    std::cout << o << std::endl;
}

template <typename T>
void printStructure(const std::vector<T>& A) {
    for(int i = 0; i < A.size(); ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void csere(T& x, T& y){
    T z(x);
    x = y;
    y = z;
}

template <typename T>
void bubbleSort(std::vector<T> A){
    int j = A.size()-1;
    while(j >= 2){
        int i = 0;
        while(i <= j-1){
            if(A[i] <= A[i+1]){
                csere(A[i], A[i+1]);
            }
            ++i;
        }
        --j;
        printStructure(A);
    }
}

template <typename T>
void insertSort(std::vector<T> A){
    int j = 0;
    while(j < A.size()-1){
        T w = A[j+1];
        int i = j;
        while(i >= 0 && A[i] > w){
            A[i+1] = A[i];
            --i;
        }
        A[i+1] = w;
        ++j;
        printStructure(A);
    }
}

template <typename T>
int maxker(std::vector<T> A, int n){
    int ind = 0;
    T max = A[ind];
    for(int i = 1; i < n; ++i){
        if(A[i] > max){
            max = A[i];
            ind = i;
        }
    }
    return ind;
}

template <typename T>
void maxKivSort(std::vector<T> A){
    int j = A.size()-1;
    while(j > 0){
        int ind = maxker(A, j);
        csere(A[ind], A[j]);
        --j;
        printStructure(A);
    }
}

template <typename T>
void doTheMerge(std::vector<T>& A, std::vector<T>& B, int k, int u, int v){
    for(int i = u; i < k; ++i){
        B[i - u] = A [i];
    }
    int m = u;
    int i = k + 1;
    int j = 0;
    int vb = k - u;
    while(i <= v && j <= vb){
        if(A[i] < B[j]){
            A[m] = A[i];
            ++i;
        }else{
            A[m] = B[j];
            ++j;
        }
        ++m;
    }
    while(j <= vb){
        A[m] = B[j];
        ++m;
        ++j;
    }
    printStructure(A);
}

template <typename T>
void merge1(std::vector<T>& A, std::vector<T>& B, int u, int v){
    if(u < v){
        int k = (int)((u + v - 1)/2);
        debug(k);
        merge1(A, B, u, k);
        merge1(A, B, k + 1, v);
        //doTheMerge(A, B, k, u, v);
    }
}

template <typename T>
void mergeSort(std::vector<T>& A){
    int newSize = (A.size() / 2) - 1;
    std::vector<T> B(newSize, T());
    merge1(A, B, 0, A.size());
}

template <typename T>
int cut(std::vector<T>& A, int p, int r){
    T x = A[r];
    int i = p;
    while(i < r && A[i] < x){ ++i; }
    if(i < r){
        int j = i+1;
        while(j < r){
            if(A[j] < x){
                csere(A[i], A[j]);
                ++i;
            }
            ++j;
        }
        A[r] = A[i];
        A[i] = x;
    }
    return i;
}

template <typename T>
void quickSort(std::vector<T>& A, int p, int r){
    if(p < r){
        int q = cut(A, p, r);
        printStructure(A);
        quickSort(A, p, q-1);
        p = q+1;

    }
}
#include <iostream>
#include <vector>

template <typename T>
void printStructure(T A[], int n){
    for(int i = 0; i < n; ++i){
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
void bubbleOrder(T A[], int n){
    int j = n-1;
    while(j >= 2){
        int i = 0;
        while(i <= j-1){
            if(A[i] <= A[i+1]){
                csere(A[i], A[i+1]);
            }
            ++i;
        }
        --j;
        printStructure(A, n);
    }
}

template <typename T>
void insertOrder(T A[], int n){
    int j = 0;
    while(j < n-1){
        T w = A[j+1];
        int i = j;
        while(i >= 0 && A[i] > w){
            A[i+1] = A[i];
            --i;
        }
        A[i+1] = w;
        ++j;
        printStructure(A, n);
    }
}

template <typename T>
int maxker(T A[], int n){
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
void maxKivOrder(T A[], int n){
    int j = n-1;
    while(j > 0){
        int ind = maxker(A, j);
        csere(A[ind], A[j]);
        --j;
        printStructure(A, n);
    }
}


int main() {
    int t[10] = {3, 8, 7, 4, 6, 1, 9, 0, 2, 5};
    //bubbleOrder(t, 10);
    //insertOrder(t, 10);
    maxKivOrder(t, 10);
    return 0;
}
#include<iostream>
#include <vector>
using namespace std ;

//swap function
void swap(int* a, int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

//bubble sort
void bubbleSort(int* arr, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
        }
    }
}

//bubble sort optimized
void bubbleSort_opt(int* arr, int n){
    bool flag ;
    for(int i = 0; i < n; i++){
        flag = false ;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]) ;
                flag = true ;
            }
        }
        if(flag == false) return ;
    }
}

//selection sort
void selectionSort(int* arr, int n){
    for(int i = 0; i < n; i++){
        int minIndex = i ;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j ;
            }
        }
        if( i != minIndex ){ 
            swap(arr[i],arr[minIndex]) ;
        }
    }
}

//selection sort optimized
void selectionSort_opt(int* arr, int n){
    bool flag ;
    for(int i = 0; i < n-1; i++){
        int minIndex = i ;
        flag = true ;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j ;
            }
            if(arr[j-1] > arr[j]){
                flag = false ;
            }
        }
        if(flag) return ;

        if( i != minIndex ){ 
            swap(arr[i], arr[minIndex]);
        }
    }
}
//selection sort
void selectionSort(int* arr, int n){
    for(int i = 0; i < n; i++){
        int minIndex = i ;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j ;
            }
        }
        if( i != minIndex ){ 
            swap(arr[i],arr[minIndex]) ;
        }
    }
}

//selection sort optimized
void selectionSort_opt(int* arr, int n){
    bool flag ;
    for(int i = 0; i < n-1; i++){
        int minIndex = i ;
        flag = true ;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j ;
            }
            if(arr[j-1] > arr[j]){
                flag = false ;
            }
        }
        if(flag) return ;

        if( i != minIndex ){ 
            swap(arr[i], arr[minIndex]);
        }
    }
}

//insertion sort
void insertionSort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i] ;
        int j = i - 1 ;
        while( j > -1 && temp < arr[j]){
            arr[j + 1] = arr[j] ;
            arr[j] = temp ;
            j-- ;
        }
    }
}

//merge sort
void merge(int arr[], int leftIndex, int midIndex, int rightIndex) {
    int leftArrSize = midIndex - leftIndex + 1 ;
    int rightArrSize = rightIndex - midIndex ;
    
    int leftArr[leftArrSize] ;
    int rightArr[rightArrSize] ;

    for( int i = 0; i < leftArrSize; i++){
        leftArr[i] = arr[leftIndex + i] ;
    }
    for(int i = 0; i < rightArrSize; i++){
        rightArr[i] = arr[midIndex + 1 + i] ;
    }
    int index = leftIndex ;
    int i = 0; 
    int j = 0;
    while( i < leftArrSize && j < rightArrSize){
        if( leftArr[i] <= rightArr[j]){
            arr[index] = leftArr[i] ;
            index++ ;
            i++ ;
        }
        else{
            arr[index] = rightArr[j] ;
            index++ ;
            j++ ;
        }
        
    }
    while(i < leftArrSize){
        arr[index] = leftArr[i] ;
        index++ ;
        i++ ;
    }
    while(j < rightArrSize){
        arr[index] = rightArr[j] ;
        index ++ ;
        j++ ;
    }
}

void mergeSort(int* arr, int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return ;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2 ;
    mergeSort(arr, leftIndex, midIndex) ;
    mergeSort(arr, midIndex+1, rightIndex) ;
    merge(arr, leftIndex, midIndex, rightIndex) ;
}
//printlist function
void printList(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
}

//lomuto partition
int lpartition(int* arr, int l, int h){
    int pivot = arr[h] ;
    int i = l - 1 ;
    for(int j = l; j < h ; j++){
        if(arr[j] < pivot){
            i++ ;
            swap(arr[i], arr[j]) ;
        }
    }
    swap(arr[i+1], arr[h]) ;
    return (i + 1) ;
}
//hoare's partition
int hpartition(int* arr, int l, int h){
    int pivot = arr[l] ;
    int i = l - 1 ;
    int j = h + 1 ;
    while(true){
        do{
            i++ ;
        }while(arr[i] < pivot) ;
        do{
            j-- ;
        }while(arr[j] > pivot) ;
        if( i >= j )return j ;
        swap(arr[i], arr[j]) ;
    }
}

//pivot- first element
int pivot(int* arr, int l, int h){
    int piv = arr[l] ;
    int i = l ;
    for(int j = l+1; j <= h; j++){
        if(arr[j] < piv){
            i++ ;
            swap(arr[j], arr[i]) ;
        }
    }
    swap(arr[i], arr[l]) ;
    return (i) ;
}

void quickSort(int* arr, int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return ;
    int pivotIndex  = pivot(arr, leftIndex, rightIndex) ;
    quickSort(arr, leftIndex, pivotIndex - 1) ;
    quickSort(arr, pivotIndex + 1, rightIndex) ; 

}


int main() {
    int arr[] = {1, 3, 5, 2, 4} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    printList(arr, size) ;
    cout << endl ;
    quickSort(arr, 0, 4) ;
    printList(arr, size) ;
    return 0 ;
}
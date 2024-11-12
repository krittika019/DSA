
#include<iostream>
using namespace std ;

//linear search with iterative

int LinearSearchiter(int* arr, int size, int key){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == key){
            return i ;
        }
    }
    return -1 ;
}

// linear search with recursion

int LinearSearchRec(int* arr, int key, int low, int high){
    if(arr[low] == key){
        return low ;
    }
    else if(low < high) return LinearSearchRec(arr, key, low+1, high) ;
        
    else return -1 ;
}

// Binary Search with iterative
int BinarySearchIter(int* arr, int low, int high, int key){
    while(low <= high){
        int mid = (low + high)/2 ;
        if(arr[mid] == key){
            return mid ;
        }
        else if(arr[mid] < key ){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return -1 ;
}
//binary search with recursion
int binarySearchRecur(int* arr, int low, int high, int key){
    if(low <= high){
        int mid = (low + high) / 2 ;
        if(arr[mid] == key) return mid ;

        else if (arr[mid] < key) return binarySearchRecur(arr, mid + 1, high, key) ;

        else return binarySearchRecur(arr, low, mid-1, key) ;
    }
    return -1 ;

}
// fibonacci Search
int min(int a, int b){
    if( a > b )return b ;
    return a ;
}
int fibonacci_search(int* arr, int n, int key){
    int curr = -1;
    int num2 = 0;
    int num1 = 1;
    int temp = num2 + num1;
    while (temp < n) {
        num2 = num1;
        num1 = temp;
        temp = num2 + num1;
    }
    while (temp > 1) {
        int i = min(curr + num2, n - 1);
        if (arr[i] < key) {
            temp = num1;
            num1 = num2;
            num2 = temp - num1;
            curr = i;
        } else if (arr[i] > key) {
            temp = num2;
            num1 = num1 - num2;
            num2 = temp - num1;
        } else
            return i;
    }
    if (num1 && arr[curr + 1] == key)
        return curr + 1;
    return -1;
}
int main(){
    int arr[] = {1,3,5,7,9} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
    int key ;
    cout << "enter a key : " ;
    cin >> key ;
    while(1){
        cout << "1. Linear Search with iterative" << endl ;
        cout << "2. Linear Search with recursion" << endl ;
        cout << "3. Binary Search with iterative" << endl ;
        cout << "4. Binary Search with recursion" << endl ;
        cout << "5. exit the program" << endl ;
        int num ;
        cout << "enter number to choose one of the above function : " ;
        cin >> num ;
        int result ;
        switch(num){
            case 1 :
                result = LinearSearchiter(arr, size, key) ;
                break ;
            case 2 :
                result = LinearSearchRec(arr, key, 0, size) ;
                break ;
            case 3 :
                result = BinarySearchIter(arr, 0, size-1, key) ;
                break ;
            case 4 :
                result = binarySearchRecur(arr, 0, size-1, key) ;
                break ;
            case 5 :
                return 0 ;
            default :
                cout << "not an option" << endl ;
                return 0 ;
        }

        cout << "number" << key << "at index : " << result << endl ;
    }

}

// use switch case to choose any one out of four
// characters for every func
// in binary search convert while to for loop
// in linear for to while
// find the time complexity for recursive , iterative 
//
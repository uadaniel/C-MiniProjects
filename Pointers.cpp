#include <iostream>
using namespace std;
/*Write a C++ function named apply_all that expects two arrays of integers and their sizes and
dynamically allocates a new array of integers whose size is the product of the 2 array sizes
The function should loop through the second array and multiplies each element across each element of array 1 and store the
product in the newly created array.
The function should return a pointer to the newly allocated array.
You can also write a print function that expects a pointer to an array of integers and its size and display the
elements in the array.
For example,
Below is the output from the following code which would be in main:
int array1[] {1,2,3,4,5};
int array2[] {10,20,30};
cout << "Array 1: " ;
print(array1,5);
cout << "Array 2: " ;
print(array2,3);
int *results = apply_all(array1, 5, array2, 3);
cout << "Result: " ;
print(results,15);
Output
---------------------
Array 1: [ 1 2 3 4 5 ]
Array 2: [ 10 20 30 ]
Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
 */
void print(int[], int);
int *apply_all(int[], int, int[], int);
int main(){
    std::cout<<"Section 12 Challenge"<<std::endl;
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    cout << "Array 1: " ;
    print(array1,5);
    cout << "Array 2: " ;
    print(array2,3);
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
    delete[] results;//delete results would delete only the memory zone from address results(first one) instead of all consecutive memory zones
    cout<<"How results vector looks after delete the memory zone:"<<endl<<"!Take in mind that a program that dereferences a pointer after the object is deleted can have unpredictable results or crash."<<endl;
    try{    
        print(results,15);
    }
    catch(...){//catch any exception
        cout<<"An error occured when tried to display(dereference) an unallocated memory zone..."<<endl;
    }
    return 0;
}
void print(int inArray[], int dim){
    for(int i=0;i<dim;i++){
        cout<<inArray[i]<<' '; //echivalent cu cout<<*(inArray+i)<<' ';
    }
    cout<<endl;
}
int *apply_all(int inArray[], int dim, int inArray2[], int dim2){
    int *productArray{nullptr};
    productArray = new int[dim*dim2];
    int c=0;
    while(c<dim*dim2){
        for(int j=0;j<dim2;j++){
            for(int i=0;i<dim;i++){
                *(productArray+c) = inArray2[j]*inArray[i];
                c++;
            }
        }
    }
    return productArray;
}
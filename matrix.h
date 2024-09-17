#ifndef martix
#define martix
struct matrix;
union datatype;
void* matrix(int rows, int cols);
void* getEle(int row, int col);
void* reszie(int rows, int cols);
void* subset();
void* add(int arr, int arr2);
void* subtract(int arr, int arr2);
void* multiply(int arr, int arr2);
void* deepcopy(int arr);
void* equal(int arr, int arr2);
void* rotate(int arr);
void* print();
#endif

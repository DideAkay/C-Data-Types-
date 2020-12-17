#ifndef SOURCE_H_
#define SOURCE_H_

#define INIT_CAPACITY 2
#define ARRAY_SIZE 100
#define SET_SIZE 81

typedef struct dynamic_array
{
    int* array;
    int size ;
    int capacity; 
}dynamic_array_t;

dynamic_array_t* createArray(); 
dynamic_array_t* array_add(dynamic_array_t* _array, int _value);
dynamic_array_t* array_double (dynamic_array_t* _array);

int array_find_element(dynamic_array_t* _array, int _value);
int array_find_element2(int* _array, int _value);

double findSearchTime(dynamic_array_t* _array);
double findSearchTime2(int* _array, int range);

dynamic_array_t* array_remove_by_index(dynamic_array_t* _array, int _index);
int* array_remove_by_index2(int* _array, int _index,int array_range);

#endif
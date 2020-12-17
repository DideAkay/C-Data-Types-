#include "source.h"
#include<stdlib.h> 
#include<stdio.h>
#include <time.h>
#include <string.h>

//dynamically creates a dynamic array of size INIT_CAPACITY
dynamic_array_t* createArray()
{
	dynamic_array_t *temp = (dynamic_array_t*)malloc(sizeof(dynamic_array_t ));

    if (temp==NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 0;
    }
    
	temp->size = 0;
	temp->capacity =INIT_CAPACITY;
    temp->array = (int*)malloc(sizeof(int)*INIT_CAPACITY);

    if (temp->array==NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 0;
    }

    return temp;
} 

//dynamically adds to a dynamic array 
dynamic_array_t* array_add(dynamic_array_t* _array, int _value){    
    if (_array->size >= _array->capacity)
    {
        array_double(_array);
    }

    _array->array[_array->size++] = _value;
    return _array;   

}

dynamic_array_t* array_double (dynamic_array_t* _array){

    int *temp = (int*)malloc(sizeof(int)*_array->capacity*2);

    if (temp==NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 0;
    }

    for (int i = 0; i < _array->size; i++)
    {
        temp[i] = _array->array[i];
    }
    
    free(_array->array);
    _array->array = temp;
    _array->capacity = _array->capacity * 2;

    return _array;

}    

int array_find_element(dynamic_array_t* _array, int _value){    
    for (int i = 0; i < _array->size; i++)
    {
            if (_array->array[i]==_value)
            {
               // printf("found the element at index %d \n", i);
                return i;                
            }
            
    }  
    // "-1" indicates "not found"
    return -1;
}

int array_find_element2(int* _array, int _value){    
    for (int i = 0; i < 100; i++)
    {
            if (_array[i]==_value)
            {
               // printf("found the element at index %d \n", i);
                return i;                
            }            
    }  

    return -1;
}

//for dynamic arrays
dynamic_array_t* array_remove_by_index(dynamic_array_t* _array, int _index){

    if (_index>_array->size||_index==0)
    {
       fprintf(stderr, "index out of range or element not found\n");
        return NULL;
    }
    
    int temp = _array->array[_index];
    
    //removing by writing over that element
    for (int i = 0; i < _array->size; i++)
    {
        _array->array[i-1]= _array->array[i];
    }

    _array->size=_array->size-1;
    return _array;
    
}

//for normal arrays
int* array_remove_by_index2(int* _array, int _index,int array_range){

    if (_index>array_range||_index==0)
    {
       // fprintf(stderr, "index out of range or element not found\n");
        return NULL;
    }
    
    //int temp = _array[_index];
    _array[_index]=-1;

    return _array;
    
}

//for dynamic arrays
double findSearchTime(dynamic_array_t* _array){
        	
    clock_t start;
    clock_t end;

    //Avr. time to find and element in an dynamic array
    double average=0;
    for (int i = 0; i < 100; i++)
    {
        start = clock();
    
        int index = array_find_element(_array,i);
      

        
        array_remove_by_index(_array ,index); 
          end=clock();
        average+= (double)(end- start);
        
    }  
    printf("total time for 100 searches in an dynamic array: %f \n", average);  
    return (average/100);

}

//for normal arrays
double findSearchTime2(int* _array, int range){
        	
    clock_t start;
    clock_t end;

    //Avr. time to find and element
    double average=0;
    for (int i = 0; i < 100; i++)
    {
        start = clock();
        
       
        int index = array_find_element2(_array,i);
       
        array_remove_by_index2(_array,index ,range);  
        end=clock();
        average+= (double)(end- start);
    }  
    printf("total time for 100 searches in a normal array: %f \n", average);  
    return (average/100);

}


#include "source.h"
#include<stdlib.h> 
#include<stdio.h>
#include <string.h>

void main(void){


    dynamic_array_t* array1 = createArray();
    int array2[ARRAY_SIZE];
    
    int i = 0;

    while(array1->size<ARRAY_SIZE)
    {
        int random_value = rand()%100;

        if (array_find_element(array1,random_value)==-1){
             array1 =array_add(array1, random_value); 
             array2[i]=random_value;
             i++;            
        }       
    }

    printf("SearchTime of dynamic array %f \n",findSearchTime(array1)); //dynamic array avr time = 0.01

    printf("SearchTime of normal array %f \n",findSearchTime2(array2,ARRAY_SIZE));//normal array avr time = 0.02

}
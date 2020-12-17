#include "source.h"
#include<stdlib.h> 
#include<stdio.h>
#include <string.h>

void main(void){

    int parentList[SET_SIZE];
    int rankList[SET_SIZE];

    for (int i = 0; i < 81; i++)
    {
        makeSet(parentList,rankList,i);
    }

//some highways in Turkey are given, the program will create disjoint sets from connected cities of Turkey

// O-5 İstanbul-İzmir Highway
union_sets(parentList,rankList,34,35);

// O-31 İzmir-Aydın-Denizli-Burdur Highway
union_sets(parentList,rankList,35,9);
union_sets(parentList,rankList,35,20);
union_sets(parentList,rankList,35,15);

// O-51 Adana-Mersin Highway
union_sets(parentList,rankList,1,33);

// O-52 Adana-Gaziantep-Şanlıurfa Highway
union_sets(parentList,rankList,01,27);
union_sets(parentList,rankList,01,63);

// O-4 İstanbul-İzmit-Bolu-Ankara Highway
union_sets(parentList,rankList,34,41);
union_sets(parentList,rankList,34,14);
union_sets(parentList,rankList,34,6);

// O-3 İstanbul-Edirne Highway
union_sets(parentList,rankList,34,22);

// O-7 İstanbul-Kocaeli-Sakarya
union_sets(parentList,rankList,34,41);
union_sets(parentList,rankList,34,54);

// O-21 Ankara-Niğde-Adana
union_sets(parentList,rankList,6,51);
union_sets(parentList,rankList,6,1);

// O-22 Bursa-Eskişehir
union_sets(parentList,rankList,16,26);

//--------------Listing Graphs as Disjoint Sets------------//
printf("\n ---GRAPHS---\n");
for (int i = 0; i < 81; i++){

    if(find_root(parentList,i)==i){

        printf("\n{%d",i);

        for (int j = 0; j < 81; j++){
            
            if(isReachable(parentList,i,j)&&(i!=j)) printf(", %d,",j);
        }
        printf("}\n");
    }
}      

}  
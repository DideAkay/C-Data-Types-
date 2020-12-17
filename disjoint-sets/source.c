#include "source.h"
#include<stdlib.h> 
#include<stdio.h>
#include <time.h>
#include <string.h>


void makeSet(int* parent,int* rank ,int i){
    parent[i]=i;
    rank[i]=0;
}

int find_root(int* parent, int i){
    while (i != parent[i])
    {
        i = parent[i];
        
    }
    return i;
}

void union_sets(int* parent, int* rank, int value_1, int value_2){
    int id_1 = find_root(parent,value_1);
    
    if (id_1==0)
    {
        
        makeSet(parent,rank,id_1);
        id_1=id_1;
    }
    
    int id_2 = find_root(parent,value_2);
    
    if (id_2==0)
    {
    
        makeSet(parent,rank,id_2);
        id_2=id_2;
    }
    if (id_1==id_2)
    {
        return;
    }

    if(rank[id_1]>rank[id_2]){
        parent[id_2] = id_1;
    }

    else
    {
        parent[id_1] = id_2;

        if (rank[id_1]==rank[id_2]){
            rank[id_2]=rank[id_2]+1;            
        }          
    } 
}

int find_rank(int* parent,int* rank, int i){
    int rank1 = 0;
    while (i != parent[i])
    {
        i = parent[i];
        rank1++;  
    }
    return rank1;
}

int isReachable(int* parent, int value_1,  int value_2){
    if (find_root(parent, value_1)==find_root(parent, value_2))
    {
        return 1;        
    }
    return 0;
}

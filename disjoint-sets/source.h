#ifndef SOURCE_H_
#define SOURCE_H_

#define SET_SIZE 81

void makeSet(int* parent,int* rank,  int i);
int find_root(int* parent, int i);
void union_sets(int* parent, int* rank, int value_1, int value_2);
int find_rank(int* parent,int* rank, int i);
int isReachable(int* parent, int value_1,  int value_2);

#endif
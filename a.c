#define OK 1
#define ERROR 0
#define NODES 8
#include<stdio.h>
#include<malloc.h>

typedef struct _HTNode{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HTree;

void Select_Min(const HTree T,int length,int* e1,int* e2){
    int min1,min2;
    min1 = min2 = 1000000;
    int pos1,pos2;
    pos1 = pos2 = 0;

    for(int i = 1;i < length + 1;i++){
        if(T[i].parent == 0){
            if(T[i].weight < min1){
                min2 = min1;
                pos2 = pos1;
                min1 = T[i].weight;
                pos1 = i;
            }else if(T[i].weight < min2){
                min2 = T[i].weight;
                pos2 = i;
            }
        }
    }
    *e1 = pos1;
    *e2 = pos2;
}

void Creat_Huffman(HTree* T,int n){
    if(n <= 1){
        return;
    }
    int m = 2 * n - 1;

    *T = (HTree)malloc(sizeof(HTNode) * (m + 1));

    for(int i = 1;i < m + 1;++i){
        (*T)[i].lchild = (*T)[i].rchild = (*T)[i].rchild = (*T)[i].lchild = 0;
        (*T)[i].parent = 0;
    }

    for(int i = 1;i < n + 1;i++){
        scanf("%d",&(*T)[i].weight);
    }

    int min1,min2;
    for(int i = n + 1;i < m + 1;++i){
        Select_Min(*T,i - 1,&min1,&min2);

        (*T)[min1].parent = (*T)[min2].parent = i;
        (*T)[i].lchild = min1;
        (*T)[i].rchild = min2;
        (*T)[i].weight = (*T)[min1].weight + (*T)[i].weight;
    }
}

int main(){
    HTree T = NULL;
    Creat_Huffman(&T,NODES);

    for(int i = 1;i < 2* NODES;i++){
        printf("weight = %d\tparent = %d\tlchild = %d\trchild = %d\n",T[i].weight,T[i].parent,T[i].lchild,T[i].rchild);
    }
}
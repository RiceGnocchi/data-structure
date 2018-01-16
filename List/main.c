//
//  main.c
//  List
//
//  Created by 张旭 on 2018/1/15.
//  Copyright © 2018年 brx. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int ElementType;

typedef struct{
    ElementType Data[MAXSIZE];
    //Last表示最后一个元素的位置
    int Last;
}List;

List *MakeEmpty(); //初始化一个空表
ElementType FindKth(int K, List L);//根据位序K，返回相应元素
int Find( ElementType X,List *PtrL);//在线性表L中查找X的第一次出现的位置
void Insert(ElementType X,int i,List *PtrL);//在位序i前插入一个新元素X
void Delete(int i,List *PtrL);//删除指定位序i的元素
int  Length(List L);//返回线性表L的长度n

int main(int argc, const char * argv[]) {

    return 0;
}

//初始化（建立空的顺序表）
List *MakeEmpty(){
    List *PtrL;
    PtrL = (List *)malloc(sizeof(List));
    PtrL->Last = -1;
    return PtrL;
}

//查找（某个元素，并返回该元素所在的位置）
int Find(ElementType X,List *PtrL){
    int i = 0;
    
    //递增i寻找与X相符的值
    while (i <= PtrL->Last && PtrL->Data[i]!=X)
        i++;

    //如果未找到，返回-1；
    if (i > PtrL->Last)
        return -1;
    
    //找到后返回储存位置i；
    else
        return i;
}

//插入
void Insert(ElementType X,int i, List *PtrL){
    int j;
    if (PtrL->Last == MAXSIZE - 1) {
        printf("表满");
        return;
    }
    
    if (i < 1 || i > PtrL->Last+2) {
        printf("位置不和法");
        return;
    }
    
    for (j = PtrL->Last; j>= i-1; j--)
        PtrL->Data[j+1] = PtrL->Data[j]; //将a[i]-a[n]倒序向后移动
    PtrL->Data[i-1] = X;                 //新元素插入
    PtrL->Last++;                        //Last仍指向最后的元素
    return;
}

//删除
void Delete(int i,List *PtrL){
    int j;
    if ( i < 1 || PtrL->Last+1 ) { //检查空表及其合法性
        printf("不存在的%d个元素",i);
        return;
    }
    
    for (j = i; j <= PtrL->Last; j++) {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last--;
    return;
}














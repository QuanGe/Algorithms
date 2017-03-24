//
//  QGSort.hpp
//  Algorithms
//
//  Created by git on 2017/3/23.
//  Copyright © 2017年 QuanGe. All rights reserved.
//

#ifndef QGSort_hpp
#define QGSort_hpp
#include <iostream>
#include <stdio.h>
#include <string>

class QGPerson
{
public:
    const char * name;
    int age;
public:
    QGPerson(const char * name,int age):name(name),age(age)
    {
        //std::cout << this->name <<"----" <<this->age <<"\n";
    }
    ~QGPerson(){};
    
};

class QGSort {
private:
    static void swap(QGPerson * a,QGPerson *b);
    static void maxHeapify(QGPerson * source[],int num,int parent);
    static int  partition(QGPerson * source[],int end,int begin);
    static void merge(QGPerson * source[],int end,int begin,int mid);
public:
    QGSort();
    ~QGSort();
    static void bubbleSort(QGPerson * source[],int num);
    static void simpleSelectionSort(QGPerson * source[],int num);
    static void straihtInsertionSort(QGPerson * source[],int num);
    static void shellSort(QGPerson * source[],int num);
    static void heapSort(QGPerson * source[],int num);
    static void quickSort(QGPerson * source[],int end,int begin);
    static void mergeSort(QGPerson * source[],int end,int begin);

    
    
};
#endif /* QGSort_hpp */

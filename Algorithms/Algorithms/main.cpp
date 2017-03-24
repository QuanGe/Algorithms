//
//  main.cpp
//  Algorithms
//
//  Created by git on 2017/3/23.
//  Copyright © 2017年 QuanGe. All rights reserved.
//

#include <iostream>
#include "QGSort.hpp"

int main(int argc, const char * argv[]) {
    const int num = 8;
    QGPerson *array[num] = {new QGPerson("a",50),
        new QGPerson("b",40),
        new QGPerson("c",30),
        new QGPerson("d",40),
        new QGPerson("e",70),
        new QGPerson("f",60),
        new QGPerson("g",50),
        new QGPerson("h",10)} ;
    
    
    std::cout << "排序之前\n";
    for (int i = 0;i <num;i++)
    {
        std::cout << array[i]->name <<"----" << array[i]->age <<"\n";
    }
    QGSort::quickSort(array, num-1,0);
    //QGSort::heapSort(array, num);
    std::cout << "排序之后\n";
    for (int i = 0;i <num;i++)
    {
        std::cout << array[i]->name <<"----" << array[i]->age <<"\n";
        delete array[i];
    }
    
    
    return 0;
}

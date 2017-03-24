//
//  QGSort.cpp
//  Algorithms
//
//  Created by git on 2017/3/23.
//  Copyright © 2017年 QuanGe. All rights reserved.
//

#include "QGSort.hpp"

#pragma mark 交换数据
void QGSort::swap(QGPerson * a,QGPerson *b) {
    QGPerson tmp = *a;
    *a = *b;
    *b = tmp;
}

#pragma mark 冒泡
void QGSort::bubbleSort(QGPerson * source[],int num)
{
    int i,j;
    bool flag = true;
    for ( i = 0;i<num && flag;++i)
    {
        flag = false;
        for (j = num -2;j>=i;--j)
        {
            if (source[j]->age>source[j+1]->age)
            {
                QGSort::swap(source[j], source[j+1]);
                flag = true;
            }
        }
    }
}
#pragma mark 简单选择
void QGSort::simpleSelectionSort(QGPerson * source[],int num)
{
    int i,j,min;
    for(i = 0 ;i<num-1;++i)
    {
        min = i;
        for (j = i +1;j<num;++j)
        {
            if (source[min]->age > source[j]->age)
            {
                min = j;
            }
        }
        
        if (i != min)
            QGSort::swap(source[i], source[min]);
    }
}

#pragma mark 直接插入
void QGSort::straihtInsertionSort(QGPerson * source[],int num)
{
    int i , j ;
    for (i =1;i<num;++i)
    {
        if(source[i]->age <source[i-1]->age)
        {
            QGPerson * temp = source[i];
            for (j = i-1;j>=0 && source[j]->age >temp->age;j--)
                source[j+1] = source[j];
            source[j+1] = temp;
        }
    }
    
}

#pragma mark 希尔
void QGSort::shellSort(QGPerson * source[],int num)
{
    int i,j;
    for (int increment = num/2;increment>=1;increment /=2)
    {
        for (i = increment;i<num;++i)
        {
            if (source[i]->age < source[i-increment]->age)
            {
                QGPerson * temp = source[i];
                for (j = i-increment;j>=0 && source[j]->age >temp->age;j-=increment)
                    source[j+increment] = source[j];
                source[j+increment] = temp;
            }
        }
    }

}

#pragma mark 堆排序
// 建立最大堆
// 这个过程相当于递归地去调整每一个子树。而叶子节点可以看做只是一个节点的堆，可以不用调整，所以只用调整非叶子节点，当index从0开始的时候，非叶子节点的最大序号是 (num-1)/2。
// Heap is source[0]~source[num-1].
void QGSort::heapSort(QGPerson * source[],int num)
{
    int i;
    for(i = (num-1)/2;i>=0;i--)
    {
        QGSort::maxHeapify(source, num, i);
    }
    
    for(i = num-1;i>0;--i)
    {
        // 把堆顶元素（即堆中最大的元素）和数组最后的元素互换，然后把这个前堆顶元素从堆中“去掉”，再调整一下新的堆。如此循环往复，就把较大的元素依次从数组尾部到头部排序下来了。
        QGSort::swap(source[0], source[i]);
        QGSort::maxHeapify(source, i, 0);
    }
    
}

// 调整以index=parent的元素为根的子树，使这个子树成为最大堆。
void QGSort::maxHeapify(QGPerson * source[],int num,int parent)
{
    // index从0计数，Left则为 2*i+1，Right则为2*i+2
    int left = 2 * parent +1;
    int right = 2 * parent +2;
    int largest = parent;
    if (left < num && source[left]->age > source[parent]->age)
        largest = left;
    else
        largest = parent;
    if (right < num && source[right]->age > source[largest]->age)
        largest = right;
    
    if (largest != parent) {
        QGSort::swap(source[parent], source[largest]);
        maxHeapify(source, num, parent);
    }
}


#pragma mark 快速排序

int QGSort::partition(QGPerson * source[],int end,int begin)
{
    
    int theAge = source[end]->age;
    int i = begin;
    for (int j = begin; j<=end - 1; ++j) {
        if (source[j]->age <= theAge)
        {
            QGSort::swap(source[i], source[j]);
            ++i;
        }
    }
    QGSort::swap(source[i], source[end]);
    return i;
    
}
void QGSort::quickSort(QGPerson * source[],int end,int begin)
{
    if (begin < end) {
        int pivotkey = partition(source, end, begin);
        quickSort(source, pivotkey-1, begin);
        quickSort(source, end, pivotkey+1);
    }
}

#pragma mark 合并排序
void QGSort::merge(QGPerson * source[],int end,int begin,int mid)
{
    int leftNum = mid - begin +1;
    int rightNum = end - mid;
    QGPerson * left[leftNum];
    QGPerson * right[rightNum];
    int i = 0,j = 0;
    for (i = 0; i<leftNum; ++i) {
        left[i] = new QGPerson( source[begin+i]->name,source[begin+i]->age);
    }
    
    for (j=0; j<rightNum; j++) {
        right[j]= new QGPerson( source[mid+1+j] ->name,source[mid+1+j] ->age);
    }
    
    i=j=0;
    int k;
    for(k = begin;k<= end;k++)
    {
        if(i>=leftNum && j<rightNum)
        {
            source[k]->name = right[j]->name;
            source[k]->age = right[j]->age;
            ++j;
        }
        
        if(j>=rightNum && i<leftNum)
        {
            source[k]->name = left[i]->name;
            source[k]->age = left[i]->age;
            ++i;
        }
        
        if(i<leftNum && j<rightNum)
        {
            if(left[i]->age <= right[j]->age)
            {
                source[k]->name = left[i]->name;
                source[k]->age = left[i]->age;
                ++i;
            }
            else
            {
                source[k]->name = right[j]->name;
                source[k]->age = right[j]->age;
                ++j;
                
            }
        }
    }
    for (i = 0; i<leftNum; ++i) {
        delete left[i];
    }
    
    for (j=0; j<rightNum; j++) {
        delete right[j];
    }
    
}

void QGSort::mergeSort(QGPerson * source[],int end,int begin)
{
    if (begin < end)
    {
        int mid = (begin+end)/2;
        QGSort::mergeSort(source,mid,begin);
        QGSort::mergeSort(source,end,mid+1);
        QGSort::merge(source, end, begin, mid);
    }
}

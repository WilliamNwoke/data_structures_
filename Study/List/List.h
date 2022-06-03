//
// Created by Uchenna on 4/29/22.
//

#ifndef SRC_LIST_H
#define SRC_LIST_H

#include <iostream>

class List{
private:
    int m_count;
    int * m_items;

public:
    List();
    ~List();
    int Get(int index);
    void Insert(int index, int value);
    int Search(int val);
    void Remove(int index);
    int Count();
};

#endif //SRC_LIST_H

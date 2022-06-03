//
// Created by Uchenna on 4/29/22.
//

#include "List.h"

int List::Get(int index)
{
    // Check if the index is out of bound
    if(index < 0 || index >m_count)
        return -1;
    return m_items[index];
}

void List::Insert(int index, int value) {
    // check if the index is out of bounds
    if(index < 0 || index > m_count)
        return;
    // Copu the current array
    int * oldArray = m_items;

    // Initialize a new array
    m_items = new int[m_count];

    // Fill the new array with inserted data
//    for (int i = 0, j = 0; i< m_count; ++i)
}
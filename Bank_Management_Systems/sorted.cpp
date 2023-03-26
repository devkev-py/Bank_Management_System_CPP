// Implementation file for sorted.h

#ifndef SORTED_CPP
#define SORTED_CPP


#include "sorted.h"


template <typename ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
}


template <typename ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    length = 0;
}


template <typename ItemType>
bool SortedType<ItemType>::IsFull() const
{
    return (length == MAX_ITEMS);
}


template <typename ItemType>
int SortedType<ItemType>::GetLength() const
{
    return length;
}


template <typename ItemType>
ItemType SortedType<ItemType>::GetItem(ItemType item, bool& found)
{

    int midPoint;
    int first = 0;
    int last = length - 1;

    bool moreToSearch = first <= last;
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        if (item < info[midPoint]) {
            last = midPoint - 1;
            moreToSearch = first <= last;
            break;
        }
        else if (item > info[midPoint]) {
            first = midPoint + 1;
            moreToSearch = first <= last;
            break;
        }
        else if (item == info[midPoint]) {
            found = true;
            item = info[midPoint];
        }
    }
    return item;
}


template <typename ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    int location = 0;

    while (item != info[location])
        location++;
    for (int index = location + 1; index < length; index++)
        info[index - 1] = info[index];
    length--;
}


template <typename ItemType>
void SortedType<ItemType>::PutItem(ItemType item)
{
    bool moreToSearch;
    int location = 0;

    moreToSearch = (location < length);
    while (moreToSearch)
    {
        if (item < info[location]) {
            moreToSearch = false;
        }
        else if (item > info[location]) {
            location++;
            moreToSearch = (location < length);
        }
    }
    for (int index = length; index > location; index--)
        info[index] = info[index - 1];
    info[location] = item;
    length++;
}


template <typename ItemType>
void SortedType<ItemType>::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

template <typename ItemType>
ItemType SortedType<ItemType>::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}

#endif

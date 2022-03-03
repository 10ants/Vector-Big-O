#pragma once
#include <array>
template<typename T>

class Vector
{
    T* mData;
    int mSize;     // Size is how much data. Capacity is how much memory.
    int mCapacity; // For testing purposes, initialize this to 15. Whenever you allocate new memory, double it.
    T mUndefined; // Lots of STL functions say that doing something naughty gets "undefined behavior". It could throw, crash, make you eggs, or return nonsense.
                  // Return this undefined one if anybody ever tries to go out of bounds.
                  // I've also seen this done with a static. I'll do that in List later

public:
    Vector() // O(1)
    {
        mSize = 0;
        mData = nullptr;
        Reserve(15);
        // If you put a new in here, you'd be duplicating the reserve code. Feel free to call non-virtual methods of your own here.
        // (You can't call a virtual method because the whole object isn't finished constructing yet.)
       
    }
    // Big 3
    ~Vector()
    {
        delete[] mData;
    }

    Vector(const Vector& tOther) : Vector()
    { // O(n)
        mSize = tOther.mSize;
        mCapacity = tOther.mCapacity;
        for (int i = 0; i < mSize; i++) // Loop to transfer over the contents of the array
            mData[i] = tOther.mData[i];
        
    }

    Vector& operator=(const Vector& tRHS)
    { // O(n)
        mSize = tRHS.mSize;
        mCapacity = tRHS.mCapacity;
        for (int i = 0; i < mSize; i++) // Loop to transfer over the contents of the array
            mData[i] = tRHS.mData[i];
        
        return *this;
    }

    void PushBack(const T& tItem)
    { // O(1) 
        
        if (mSize == mCapacity) // If array is full double the size with reserve
        {
            Reserve(mCapacity * 2);
        }
        mData[mSize++] = tItem;
    }

    void PopBack()
    { // O(1)
        mSize--;
    }

    T& At(int tWhere)
    { // O(1)
        if (tWhere >= mSize || tWhere < 0) // If they ask for the variable at a position outside of the size of the array
        {
            return mUndefined; 
        }

        return mData[tWhere];
    }

    void Clear()
    { // O(1)
      mSize = 0;
    }

    int Size()
    { // O(1)
        return mSize;
    }

    void Reserve(int tCount)
    {
        if (tCount < mSize)
            return;
       
           
        T* TempArr = new T[tCount];
        for (int i = 0;i < mSize;i++) // copying over data from current array to new temp array
        {
            TempArr[i] = mData[i];
        }
        mCapacity = tCount;
        delete[]mData;
        mData = TempArr;
    }

    int Capacity()
    { // O(1)
        return mCapacity;
    }
};


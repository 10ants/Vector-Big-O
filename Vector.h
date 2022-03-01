#pragma once
template<typename T> 


class Vector
{
T* mData;
int mSize; // Size is how much data.  Capacity is how much memory.
int mCapacity;
T mUndefined;

public:
Vector()// O(1)
{
mSize = 0;
mData = nullptr;
Reserve( 15 ); 
}
	
// Big 3
~Vector()
{
delete[] mData; 
}
	
Vector( const Vector<T>& tOther ) : Vector()// O(n)
{
*this = tOther;	
}
	

Vector& operator =( const Vector<T>& tRHS )// O(n)
{
	
if( &tRHS == this )
return *this;
	
Clear();
	
for( int i = 0; i < tRHS.mSize; i++) 	
PushBack( tRHS.mData[i] );
	
return *this;  
}
	
void PushBack( const T& tItem )// O(1)
{	
if( mSize == mCapacity )
Reserve( 2 * mCapacity );
	
mData[mSize] = tItem;
mSize++;
}
	
void PopBack()// O(1)
{
mSize--;
}
	
T& At( int tWhere )// O(1)
{
if( tWhere < 0 || tWhere >= mSize )
return mUndefined;
	
return mData[tWhere];
}
	
void Clear()// O(1)
{
mSize = 0;
}
	
int Size()// O(1)
{
return mSize;
}
	
void Reserve( int tCount )// O(n)
{
if( tCount <= mCapacity )
return;
	
T* tNewMem = new T[tCount];
	
for( int i = 0; i < mSize; i++ )
tNewMem[i] = mData[i];
	
if( mData )
{
delete[] mData;
mData = tNewMem;
mCapacity = tCount;
}
	
int Capacity()// O(1)
{
return mCapacity;
}
};

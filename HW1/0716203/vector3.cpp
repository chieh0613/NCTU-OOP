#include "vector3.h"
#include<math.h>
#include<iostream>
using namespace std;

vector3::vector3()
{

}


vector3::vector3(float inX, float inY, float inZ)
{
    set(inX,inY,inZ);
}
vector3::vector3(const vector3 &v)
{
    x=v.x;
    y=v.y;
    z=v.z;
}

float &vector3::operator [] (unsigned int index)
{
    if(index==0)
        return x;
    else if(index==1)
        return y;
    else if(index==2)
        return z;

}

const float &vector3::operator [] (unsigned int index) const
{
    if(index==0)
        return x;
    else if(index==1)
        return y;
    else if(index==2)
        return z;

}

vector3 &vector3::operator =  (const vector3 &v)
{
    x=v.x;
    y=v.y;
    z=v.z;
    return *this;
}

vector3 &vector3::operator += (const vector3 &v)
{
    x=x+v.x;
    y=y+v.y;
    z=z+v.z;
    return *this;
}

vector3 &vector3::operator -= (const vector3 &v)
{
    x=x-v.x;
    y=y-v.y;
    z=z-v.z;
    return *this;
}

vector3 &vector3::operator *= (float f)
{
    x=f*x;
    y=f*y;
    z=f*z;
    return *this;
}

vector3 &vector3::operator /= (float f)
{
    x=f/x;
    y=f/y;
    z=f/z;
    return *this;
}

bool operator == (const vector3 &a, const vector3 &b)
{
    if(a.x==b.x&&a.y==b.y&&a.z==b.z)
       return true;
    else
        return false;

}

bool operator != (const vector3 &a, const vector3 &b)
{
    if(a.x==b.x&&a.y==b.y&&a.z==b.z)
       return false;
    else
        return true;
}

vector3 operator - (const vector3 &a)
{
    vector3 temp;
    temp.x=-(a.x);
    temp.y=-(a.y);
    temp.z=-(a.z);
    return temp;
}

vector3 operator + (const vector3 &a, const vector3 &b)
{
    vector3 temp;
    temp.x=a.x+b.x;
    temp.y=a.y+b.y;
    temp.z=a.z+b.z;
    return temp;
}

vector3 operator - (const vector3 &a, const vector3 &b)
{
    vector3 temp;
    temp.x=a.x-b.x;
    temp.y=a.y-b.y;
    temp.z=a.z-b.z;
    return temp;
}

vector3 operator * (const vector3 &v, float f)
{
    vector3 temp;
    temp.x=v.x*f;
    temp.y=v.y*f;
    temp.z=v.z*f;
    return temp;
}

vector3 operator * (float f, const vector3 &v)
{
    vector3 temp;
    temp.x=f*v.x;
    temp.y=f*v.y;
    temp.z=f*v.z;
    return temp;
}

vector3 operator / (const vector3 &v, float f)
{
    vector3 temp;
    temp.x=v.x/f;
    temp.y=v.y/f;
    temp.z=v.z/f;
    return temp;
}

void vector3::set(float xIn, float yIn, float zIn)
{
    x=xIn;
    y=yIn;
    z=zIn;
}

float vector3::length() const
{
    float length=sqrt(x*x+y*y+z*z);
    return length;
}


void vector3::printVector3() const
{
    std::cout<<"("<<x<<", "<<y<<", "<<z<<")";
}




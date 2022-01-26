#include "matrix33.h"
#include<iostream>
using namespace std;
#include "vector3.h"

matrix33::matrix33()
{

}

matrix33::matrix33(vector3 vec1,vector3 vec2,vector3 vec3)
{
    set(vec1,vec2,vec3);
}


matrix33::matrix33(const matrix33 &mat)
{
    vec1=mat.vec1;
    vec2=mat.vec2;
    vec3=mat.vec3;
}

vector3 &matrix33::operator [] (unsigned int index)
{
    if(index==0)
        return vec1;
    else if(index==1)
        return vec2;
    else if(index==2)
        return vec3;

}

const vector3 &matrix33::operator [] (unsigned int index) const
{
    if(index==0)
        return vec1;
    else if(index==1)
        return vec2;
    else if(index==2)
        return vec3;
}

matrix33 &matrix33::operator =  (const matrix33 &mat)
{
    vec1=mat.vec1;
    vec2=mat.vec2;
    vec3=mat.vec3;
    return *this;
}

matrix33 &matrix33::operator += (const matrix33 &mat)
{
    vec1=vec1+mat.vec1;
    vec2=vec2+mat.vec2;
    vec3=vec3+mat.vec3;
    return *this;
}

matrix33 &matrix33::operator -= (const matrix33 &mat)
{
    vec1=vec1-mat.vec1;
    vec2=vec2-mat.vec2;
    vec3=vec3-mat.vec3;
    return *this;
}

matrix33 &matrix33::operator *= (float f)
{
    vec1*=f;
    vec2*=f;
    vec3*=f;
    return *this;
}

matrix33 &matrix33::operator /= (float f)
{
    vec1/=f;
    vec2/=f;
    vec3/=f;
    return *this;
}

bool operator == (const matrix33 &mat1, const matrix33 &mat2)
{
    if(mat1.vec1==mat2.vec1&&mat1.vec2==mat2.vec2&&mat1.vec3==mat2.vec3)
        return true;
    else
        return false;
}

bool operator != (const matrix33 &mat1, const matrix33 &mat2)
{
    if(mat1.vec1==mat2.vec1&&mat1.vec2==mat2.vec2&&mat1.vec3==mat2.vec3)
        return false;
    else
        return true;
}

matrix33 operator - (const matrix33 &mat)
{
    matrix33 temp;
    temp.vec1=-mat.vec1;
    temp.vec2=-mat.vec2;
    temp.vec3=-mat.vec3;
    return temp;
}

matrix33 operator + (const matrix33 &mat1, const matrix33 &mat2)
{
    matrix33 temp;
    temp.vec1=mat1.vec1+mat2.vec1;
    temp.vec2=mat1.vec2+mat2.vec2;
    temp.vec3=mat1.vec3+mat2.vec3;
    return temp;
}

matrix33 operator - (const matrix33 &mat1, const matrix33 &mat2)
{
    matrix33 temp;
    temp.vec1=mat1.vec1-mat2.vec1;
    temp.vec2=mat1.vec2-mat2.vec2;
    temp.vec3=mat1.vec3-mat2.vec3;
    return temp;
}

matrix33 operator * (float f, const matrix33 &mat)
{
    matrix33 temp;
    temp.vec1=f*mat.vec1;
    temp.vec2=f*mat.vec2;
    temp.vec3=f*mat.vec3;
    return temp;
}

matrix33 operator * (const matrix33 &mat, float f)
{
    matrix33 temp;
    temp.vec1=f*mat.vec1;
    temp.vec2=f*mat.vec2;
    temp.vec3=f*mat.vec3;
    return temp;

}

matrix33 operator * (const matrix33 &mat1, const matrix33 &mat2)
{
    matrix33 temp;
    temp[0][0]=mat2[0][0]*mat1[0][0]+mat2[0][1]*mat1[1][0]+mat2[0][2]*mat1[2][0];
    temp[0][1]=mat2[0][0]*mat1[0][1]+mat2[0][1]*mat1[1][1]+mat2[0][2]*mat1[2][1];
    temp[0][2]=mat2[0][0]*mat1[0][2]+mat2[0][1]*mat1[1][2]+mat2[0][2]*mat1[2][2];
    temp[1][0]=mat2[1][0]*mat1[0][0]+mat2[1][1]*mat1[1][0]+mat2[1][2]*mat1[2][0];
    temp[1][1]=mat2[1][0]*mat1[0][1]+mat2[1][1]*mat1[1][1]+mat2[1][2]*mat1[2][1];
    temp[1][2]=mat2[1][0]*mat1[0][2]+mat2[1][1]*mat1[1][2]+mat2[1][2]*mat1[2][2];
    temp[2][0]=mat2[2][0]*mat1[0][0]+mat2[2][1]*mat1[1][0]+mat2[2][2]*mat1[2][0];
    temp[2][1]=mat2[2][0]*mat1[0][1]+mat2[2][1]*mat1[1][1]+mat2[2][2]*mat1[2][1];
    temp[2][2]=mat2[2][0]*mat1[0][2]+mat2[2][1]*mat1[1][2]+mat2[2][2]*mat1[2][2];

    return temp;
}

matrix33 operator / (const matrix33 &mat, float f)
{
    matrix33 temp;
    temp.vec1=mat.vec1/f;
    temp.vec2=mat.vec2/f;
    temp.vec3=mat.vec3/f;
    return temp;
}




void matrix33::set(vector3 vec1In,vector3 vec2In,vector3 vec3In)
{
    vec1=vec1In;
    vec2=vec2In;
    vec3=vec3In;

}

float matrix33::determinant()
{
    matrix33 mat;
    mat.vec1=vec1;
    mat.vec2=vec2;
    mat.vec3=vec3;
    float x=mat[0][0]*mat[1][1]*mat[2][2]+mat[1][0]*mat[2][1]*mat[0][2]+mat[2][0]*mat[1][2]*mat[0][1];
    float y=mat[0][2]*mat[1][1]*mat[2][0]+mat[2][1]*mat[1][2]*mat[0][0]+mat[2][2]*mat[1][0]*mat[0][1];
    return x-y;

}

matrix33 matrix33::invert()
{
    matrix33 mat1,mat2,mat3,mat4,mat;
    mat1.vec1=vec1;
    mat1.vec2=vec2;
    mat1.vec3=vec3;
    float det=mat1.determinant();
    mat2=mat1*mat1;
    float trace1=mat1.vec1.x+mat1.vec2.y+mat1.vec3.z;
    float trace2=mat2.vec1.x+mat2.vec2.y+mat2.vec3.z;
    mat3=trace1*mat1;
    float z=(trace1*trace1-trace2)/2;
    mat4.identity();
    mat4*=z;
    mat=(mat2-mat3+mat4)/det;
    return mat;
}

void matrix33::identity()
{
    vec1.x=1;
    vec1.y=0;
    vec1.z=0;
    vec2.x=0;
    vec2.y=1;
    vec2.z=0;
    vec3.x=0;
    vec3.y=0;
    vec3.z=1;
}



// print matrix using std::cout
void matrix33::printMatrix() const
{
    cout<<vec1.x<<"   "<<vec2.x<<"   "<<vec3.x<<endl;
    cout<<vec1.y<<"   "<<vec2.y<<"   "<<vec3.y<<endl;
    cout<<vec1.z<<"   "<<vec2.z<<"   "<<vec3.z<<endl;
}


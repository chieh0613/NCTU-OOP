#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"
#include<iostream>

class matrix33
{


public:
	vector3 vec1,vec2,vec3;

public:

	matrix33();

	matrix33( vector3 invec1, vector3 invec2, vector3 invec3);

	matrix33(const matrix33 &mat);

public:

	vector3                 &operator [] (unsigned int index);
	const vector3           &operator [] (unsigned int index) const;

	matrix33               &operator =  (const matrix33 &v);
	matrix33               &operator += (const matrix33 &v);
	matrix33               &operator -= (const matrix33 &v);
	matrix33              &operator *= (float f);
	matrix33              &operator /= (float f);
	friend bool           operator == (const matrix33 &a, const matrix33 &b);
	friend bool           operator != (const matrix33 &a, const matrix33 &b);
	friend matrix33       operator - (const matrix33 &a);
	friend matrix33        operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator * (const matrix33 &v, float f);
	friend matrix33        operator * (float f, const matrix33 &v);
	friend matrix33        operator / (const matrix33 &v, float f);
	friend matrix33        operator * (const matrix33 &mat1, const matrix33 &mat2);

 public:

	 void set(vector3 vec1In,vector3 vec2In,vector3 vec3In);

	 float determinant();

	 void printMatrix() const;

	 matrix33 invert();

	 void identity();
};



#endif

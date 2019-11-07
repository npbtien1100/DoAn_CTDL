//
//  Vector.h
//  Matrix1
//
//  Created by Admin on 11/1/19.
//  Copyright © 2019 tvt3. All rights reserved.
//Dot *A=new Dot[16]
#ifndef Vector_h
#define Vector_h
#include<iostream>
#include<vector>
using namespace std;

class Vector
{
	float*data;
	int n;
public:
	Vector();
	Vector(float *a, int _n);
	Vector(const Vector &a);
	Vector& ConghaiVector(const Vector& b);
	Vector& Nhan_alpha(const float &alpha);
	void input();
	void output();
	~Vector();
};

#endif /* Vector_h */
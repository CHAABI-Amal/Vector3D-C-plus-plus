#pragma once
using namespace std;
#include<math.h>
typedef float f; 

class Vector3D
{
private:

public:
	//********** Variables *********//
	float x;
	float y;
	float z;
	//********* Constructore ********//
	Vector3D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3D(float vx, float vy, float vz=0.0)//initializing object with values.
	{
		x = vx;
		y = vy;
		z = vz;
	}
	//********** Copy constructor *********//
	Vector3D(const Vector3D &vec); 
	//************* Functions ****************//
	
	//******* Surcharger operateur ********//
	Vector3D operator+(const Vector3D &vec); // addition
	Vector3D &operator+=(const Vector3D &vec); //assigning new result to the vecteur
	Vector3D operator-(const Vector3D &vec);
	Vector3D &operator-=(const Vector3D &vec);
	Vector3D operator*(f valeur);
	Vector3D &operator*=(f valeur);
	Vector3D operator/(f valeur);
	Vector3D &operator/=(f valeur);
	Vector3D &operator=(const Vector3D &vec);
	
	float dotProduct(const Vector3D &v2);//scalar dotProduct
	
	Vector3D crossProduct(const Vector3D &vec);// crossProduct
	f magnitude();//magnitude of the vector
	Vector3D normalization();
	f square();
	f distance(const Vector3D &vec);
	f show_X();// return x
	f show_Y();// return y
	f show_Z();// return z
	void print(); //display value of vectors
};
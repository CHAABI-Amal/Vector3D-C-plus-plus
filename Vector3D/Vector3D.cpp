//Amal CHAABI 13 Oct 2023
#include<iostream>
#include<math.h>
#include<assert.h>
#include "Vector3D.h"
using namespace std;
typedef float f;

// construtor
Vector3D::Vector3D(const Vector3D &vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

//********** addition *********//
Vector3D Vector3D::operator+(const Vector3D &vec)
{
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

//******* Substraction ********//
Vector3D Vector3D::operator-(const Vector3D &vec)
{
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}
//******* scalar Multiplication ********//
Vector3D Vector3D::operator*(f valeur)
{
	return Vector3D(x * valeur, y * valeur, z * valeur);
}

Vector3D &Vector3D::operator*=(f valeur)
{
	x *= valeur;
	y *= valeur;
	z *= valeur;
	return *this;
}
//******** scalar division *******//
Vector3D Vector3D::operator/(f valeur)
{
	assert(valeur != 0);
	return Vector3D(x/valeur, y/valeur, z/valeur);
}

Vector3D &Vector3D::operator/=(f valeur)
{
	assert(valeur != 0);
	x /= valeur;
	y /= valeur;
	z /= valeur;
	return *this;
}
//*********** egale ************//
Vector3D &Vector3D::operator=(const Vector3D &vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}
//********* Produit scalaire **********//
float Vector3D::dotProduct(const Vector3D &vec)
{
	return (x * vec.x + y * vec.y + z * vec.z);
}
//********** produit croisé **********//
Vector3D Vector3D::crossProduct(const Vector3D &vec)
{
	f i = y * vec.z - z * vec.y;
	f j = z * vec.x - x * vec.z;
	f k = x * vec.y - y * vec.x;
	return Vector3D(i, j, k);
}
//*********** longueur d'un vecteur *****//
f Vector3D::square()
{
	return (pow(x, 2) + pow(y, 2) + pow(z, 2));
}
f Vector3D::magnitude()
{
	return sqrt(square());
}
//********** norme d'un vecteur en 3D *************//
Vector3D Vector3D::normalization()
{
	assert(magnitude() != 0);
	*this /= magnitude();
	return *this;
}
//************** distance ***************//
f Vector3D::distance(const Vector3D &vec)
{
	Vector3D dist = *this - vec;
	return dist.magnitude();
}
//*********** SHOW *********** //
f Vector3D::show_X()
{
	return x;
}
f Vector3D::show_Y()
{
	return y;
}
f Vector3D::show_Z()
{
	return z;
}
void Vector3D::print()
{
	cout << "<" << x << "," << y << "," << z << ">" << endl;
}
// ******** fonction principale ********* //
int main()
{
	Vector3D a = Vector3D(-1, 2, 3);
	Vector3D b = Vector3D(6, 5, -1);
	Vector3D c = a + b;
	cout << "Vecteur a : " << endl;
	a.print();
	cout << "Vecteur b : " << endl;
	b.print();
	cout << "L'addition de ce deux veteurs :" << endl;
	c.print();
	c = a - b;
	cout << "Soustraction de ce deux veteurs :" << endl;
	c.print();
	c = a * 2;
	cout << "Produit de Vecteur a par 2 :" << endl;
	c.print();
	c = a / 2;
	cout << "Division de Vecteur a par 2 :" << endl;
	c.print();
	cout << "Produit scalaire de Vecteurs a et b :" << endl;
	cout<<a.dotProduct(b)<<endl;
	cout << "Produit croise de Vecteurs a et b :" << endl;
	a.crossProduct(b).print();// crossProduct
	cout << "Longueur de Vecteur a :" << endl;
	cout<<a.magnitude()<<endl;//magnitude of the vector
	cout << "La norme de Vecteur a :" << endl;
	a.normalization().print();
	cout << "La distance entre Vecteurs a et b :" << endl;
	cout<<a.distance(b);
	
}

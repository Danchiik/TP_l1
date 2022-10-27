#define _CRT_SECURE_NO_WARNINGS
#include "Mebel.h"

Mebel::Mebel()
{
	printf("Mebel() constructor called\n");
	strcpy(type, "");
	h = 0;
	w = 0;
	d = 0;
	strcpy(color, "");
	strcpy(material, "");
	price = 0;
}

Mebel::Mebel(Mebel& obj)
{
	printf("Mebel(Mebel& obj) constructor called\n");
	strcpy(type, obj.getType());
	h = obj.getH();
	w = obj.getW();
	d = obj.getD();
	strcpy(color, obj.getColor());
	strcpy(material, obj.getMaterial());
	price = obj.getPrice();
}


Mebel::Mebel(char* t, int H, int W, int D, char* c, char* m, int pr): type(t), h(H), w(W), d(D), color(c), material(m), price(pr)
{
	printf("Mebel(char* t, int H, int W, int D, char* c, char* m, int pr) constructor called\n");
}

Mebel::~Mebel()
{
	printf("~Mebel() destructor called\n");
	strcpy(type, "");
	h = 0;
	w = 0;
	d = 0;
	strcpy(color, "");
	strcpy(material, "");
	price = 0;
}



char* Mebel::getType()
{
	return type;
}

int Mebel::getH()
{
	return h;
}

int Mebel::getW()
{
	return w;
}

int Mebel::getD()
{
	return d;
}

char* Mebel::getColor()
{
	return color;
}

char* Mebel::getMaterial()
{
	return material;
}

int Mebel::getPrice()
{
	return price;
}


void Mebel::setType(char* v)
{
	strcpy(type, v);
}

void Mebel::setH(int v)
{
	h = v;
}

void Mebel::setW(int v)
{
	w = v;
}

void Mebel::setD(int v)
{
	d = v;
}

void Mebel::setColor(char* v)
{
	strcpy(color, v);
}

void Mebel::setMaterial(char* v)
{
	strcpy(material, v);
}

void Mebel::setPrice(int v)
{
	price = v;
}



void Mebel::print()
{
	printf("%s\n", type);
	printf("%s\n", color);
	printf("%s\n", material);
	printf("%d\n", h);
	printf("%d\n", w);
	printf("%d\n", d);
}
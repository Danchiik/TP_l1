#define _CRT_SECURE_NO_WARNINGS
#include "Mebel.h"

Mebel::Mebel()
{
	printf("Mebel() constructor called\n");
	setType((char*)"");
	setH(0); 
	setW(0); 
	setD(0); 
	setColor((char*)"");
	setMaterial((char*) "");
	setPrice(0);
}

Mebel::Mebel(Mebel& obj)
{
	printf("Mebel(Mebel& obj) constructor called\n");
	setType(obj.getType());
	setH(obj.getH());
	setW(obj.getW());
	setD(obj.getD());
	setColor(obj.getColor());
	setMaterial(obj.getMaterial());
	setPrice(obj.getPrice());
}


Mebel::Mebel(char* t, int H, int W, int D, char* c, char* m, int pr): type(t), h(H), w(W), d(D), color(c), material(m), price(pr)
{
	printf("Mebel(char* t, int H, int W, int D, char* c, char* m, int pr) constructor called\n");
}

Mebel::~Mebel()
{
	printf("~Mebel() destructor called\n");
	delete type;
	h = 0;
	w = 0;
	d = 0;
	delete color;
	delete material;
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

void Mebel::setType(char* v)
{
	delete type; type = new char[strlen(v) + 1];
	strcpy(type, v);
}

void Mebel::setColor(char* v)
{
	delete color; color = new char[strlen(v) + 1];
	strcpy(color, v);
}

void Mebel::setMaterial(char* v)
{
	delete material; material = new char[strlen(v) + 1];
	strcpy(material, v);
}

void Mebel::setPrice(int v)
{
	price = v;
}


void Mebel::print()
{
	printf("MEBEL \n");
	printf("type - %s\n", type);
	printf("color - %s\n", color);
	printf("material - %s\n", material);
	printf("HxWxD - %dx%dx%d\n", h, w, d);
}
#pragma once
#include "Factory.h"
#include "helper.h"

class Mebel : public Factory
{
	char* type;
	int h;
	int w;
	int d;
	char* color;
	char* material;
	int price;

public:

	Mebel();
	Mebel(Mebel&);
	Mebel(char*, int, int, int, char*, char*, int);
	~Mebel();

	char* getType();
	int getH();
	int getW();
	int getD();
	char* getColor();
	char* getMaterial();
	int getPrice();

	void setType(char*);
	void setH(int);
	void setW(int);
	void setD(int);
	void setColor(char*);
	void setMaterial(char*);
	void setPrice(int);


	void edit() override;
	void print() override;

};
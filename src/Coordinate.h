#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
private:
	int X;
	int Y;
public:
	Coordinate() { X=0; Y=0; }
	Coordinate(int Y, int X) : Y(Y), X(X) {}
	void setX(int X){ this->X = X; }
	void setY(int Y){ this->Y = Y; }
	int getX(){ return X; }
	int getY(){ return Y; }
};

#endif

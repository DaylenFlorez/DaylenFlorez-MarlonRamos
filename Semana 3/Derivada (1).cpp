#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>


float funcion(float x);
float DCentral(float x, float h);

float funcion(float x)
{
    float a,y;
    a = x*x;
    y = exp(-a);
    return(y);
}

float DCentral(float x, float h)
{
    float a;
    a=((funcion(x+h)-funcion(x-h))/(2*h));
    return(a);
}

int main(){

	std::ofstream *File; // Definimos apuntador

	File = new std::ofstream[2]; // Reservamos memoria

	File[0].open( "MisDatos.txt", std::ofstream::trunc ); // Abrir y dejar listo para escribir

	std::cout << File  << std::endl;

	for(int i = 0; i < 4001; i++)
    {
		File[0] << (-20 + 0.01*i) << " " << DCentral(-20 + 0.01*i,0.01) << std::endl;
		//std::cout << i << std::endl; 
	}


	File[0].close();

	return 0;
}

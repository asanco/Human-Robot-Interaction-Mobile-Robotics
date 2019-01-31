/**
*  Modelaje y definicion del conjunto de movimientos basicos (reactivos)
*  Desarrollo Curso de Robotica Movil
*  Juan Sebastian Martinez y Fernando De la Rosa
*  Universidad de los Andes
*/

#include "Aria.h"

/*
Movimiento hacia adelante
*/
class Adelante
{
public:
	//Constructor del objeto
	Adelante(double velocidadMaxima, double distanciaFrenado, ArRobot *nrobot);
	//Destructor
	virtual ~Adelante(void){};
	//Moverse hacia adelante
	virtual bool moverAdelante( double multiplicador);

protected:
	//Robot
	ArRobot *robot;
	//Velocidad maxima permitida
	double velMaxima;
	//Distancia de frenado
	double distanciaF;
};

/*
Giro hacia la izquierda
*/
class GirarI
{
public:
	//Constructor del objeto
	GirarI(double distanciaFrenado, double velocidadIzquierda, double velocidadDerecha, ArRobot *nrobot);
	//Destructor
	virtual ~GirarI(void){};
	//Gira hacia la izuierda
	virtual bool girarIzquierda(void);
	
protected:
	//Robot
	ArRobot *robot;	
	//threshold
	double distanciaF;
	//velocidad Izquierda 
	double velIzq;
	//velocidad Derecha 
	double velDer;
};

/*
Giro a la derecha
*/
class GirarD
{
public:
	//Constructor del objeto
	GirarD(double distanciaFrenado, double velocidadIzquierda, double velocidadDerecha, ArRobot *nrobot);
	//Destructor
	virtual ~GirarD(void){};
	//Gira hacia la izuierda
	virtual bool girarDerecha(void);
	
protected:
	//Robot
	ArRobot *robot;	
	//threshold
	double distanciaF;
	//velocidad Izquierda 
	double velIzq;
	//velocidad Derecha 
	double velDer;
};

/*
Movimiento hacia atras
*/
class Atras
{
public:
	//Constructor del objeto
	Atras(double velocidadMaxima, ArRobot *nrobot);
	//Destructor
	virtual ~Atras(void){};
	//Moverse hacia adelante
	virtual bool moverAtras( void);

protected:
	//Robot
	ArRobot *robot;
	//Velocidad maxima permitida
	double velMaxima;

};

/*
Detener el robot
*/
class Detener
{
public:
	//Constructor del objeto
	Detener(ArRobot * nrobot);
	//Destructor
	virtual ~Detener(void){};
	//Moverse hacia adelante
	virtual void detener(void);

protected:
	//Robot
	ArRobot *robot;
};
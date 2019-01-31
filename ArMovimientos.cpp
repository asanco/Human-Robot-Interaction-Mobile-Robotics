/**
*  Implementacion del conjunto de movimientos basicos (reactivos)
*  Desarrollo Curso de Robotica Movil
*  Juan Sebastian Martinez y Fernando De la Rosa
*  Universidad de los Andes
*/

#include "ArMovimientos.h"   // Definicion de movimientos basicos (reactivos)

//Movimiento hacia adelante

/*Constructor*/
Adelante::Adelante(double velocidadMaxima, double distanciaFrenado,ArRobot *nrobot){
	robot = nrobot;
	velMaxima = velocidadMaxima;
	distanciaF = distanciaFrenado;
}

/**
 * Mover hacia adelante
 * retornar true si se pudo mover hacia adelante. retornar false en caso contrario
 */
bool Adelante::moverAdelante(double multiplicador){
	//Sonar para Movimiento
	ArRangeDevice *sonar;
	//Obtencion del sonar
	sonar = robot->findRangeDevice("sonar");
	//Distancia al obstaculo mas cercano al frente (antes de avanzar)
	double distancia = sonar->currentReadingPolar(-40, 40) - robot->getRobotRadius();

	// TODO Definir movimiento hacia adelante en linea recta. Que pasa si hay obstaculo muy cercano al frente?
	if(distancia <= distanciaF) {
		robot->setVel2(0, 0);
		return false;
	}
	robot->setVel2(velMaxima, velMaxima);
	return true;
}

//Girar hacia la izquierda

/*Constructor*/
GirarI::GirarI(double distanciaFrenado, double velocidadIzquierda, double velocidadDerecha, ArRobot *nrobot){
	robot = nrobot;
	distanciaF = distanciaFrenado;
	velIzq = velocidadIzquierda;
	velDer = velocidadDerecha;

}

/**
 * Girar hacia la izquierda
 * retornar true si se pudo realizar el giro. retornar false en caso contrario
 */
bool GirarI::girarIzquierda(){
	//Sonar de movimiento
	ArRangeDevice *sonar;
	sonar = robot->findRangeDevice("sonar");
	//Distancia al obstaculo mas cercano por izquierda (antes de girar)
	double distanciaObstIzquierdo = sonar->currentReadingPolar(30, 100) - robot->getRobotRadius();

	// TODO Redefinir rotacion. Que pasa si hay obstaculo muy cercano a la izquierda?
	robot->setVel2(velIzq, velDer);
	return true;
}

//Girar hacia la derecha

/*Constructor*/
GirarD::GirarD(double distanciaFrenado, double velocidadIzquierda, double velocidadDerecha, ArRobot *nrobot){
	robot = nrobot;
	distanciaF = distanciaFrenado;
	velIzq = velocidadIzquierda;
	velDer = velocidadDerecha;
}

/** 
 * Girar hacia la derecha
 * retornar true si se pudo realizar el giro. retornar false en caso contrario
 */
bool GirarD::girarDerecha(){
	//Sonar de movimiento
	ArRangeDevice *sonar;
	sonar = robot->findRangeDevice("sonar");
	//Distancia al obstaculo mas cercano por derecha (antes de girar)
	double distanciaObstDerecho = (sonar->currentReadingPolar(-100,-30) - robot->getRobotRadius());

	// TODO Redefinir rotacion. Que pasa si hay obstaculo muy cercano a la derecha?
	robot->setVel2(velIzq, velDer);
	return true;
}

//Movimiento hacia atras

/*Constructor*/
Atras::Atras(double velocidadMaxima, ArRobot *nrobot){
	robot = nrobot;
	velMaxima = velocidadMaxima;

}

/**
 * Mover hacia atras
 * retornar true si se pudo mover hacia adelante. retornar false en caso contrario
 */
bool Atras::moverAtras (){

	//No se puede obtener la distancia mas cercana hacia atras del robot (No hay sensores hacia atras)
	// TODO Definir movimiento hacia atras en linea recta
	// Precaucion: Definir movimiento lento
	robot->setVel2(-velMaxima, -velMaxima);
	return true;
}

//Detenerse

/*constructor*/
Detener::Detener(ArRobot * nrobot){
	robot = nrobot;
}

/**
 * Detener el robot
 */
void Detener::detener(){
	robot->setVel2(0.0, 0.0);

}
//Librerias necesarias para el funcionamiento del proyecto
#include <Wire.h>
#include <ADXL345.h>
#include <Servo.h>
//Crea el objeto adxl
ADXL345 adxl;
//crear los objetos servoX y servoY para controlar los servos
Servo servoX;
Servo servoY;
//Variables
int valorX;
int valorY;
int valorZ;
void setup()
{
adxl.powerOn();
//Pines usados para los servos
servoX.attach(5);
servoY.attach(6);
}

void loop(){
int x,y,z;
adxl.readAccel(&x, &y, &z);//leemos los valores del acelerómetro y almacenarlos en variables x, y, z
//las siguientes 3 lineas son para un desplazamiento 
valorX = x -  7;
valorY = y - 6;
valorZ = z + 10;
//escala para usarlo en el servo (valor entre 0 y 179)
valorX = map(valorX, -255, 255, 179, 0);
valorY = map(valorY, -255, 255, 0, 179);
//establece la posición del servo de acuerdo con el valor obtendido en el acelerometros ejes x e y
servoX.write(valorX);
delay(15);
servoY.write(valorY);
delay(15);
}

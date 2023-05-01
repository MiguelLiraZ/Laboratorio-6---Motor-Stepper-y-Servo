//Se incluyen Librerias
#include <Stepper.h>
#include <Servo.h>

int StepsPerRevolution = 2048; //Pasos que tiene que dar el Steppera para dar una Vuelta
Stepper myStepper(StepsPerRevolution,9,10,11,12); //Pines declarados para Stepper

//Variables para el Servomotor
int x;
Servo s1; 

//PushButtons
const int pb1 = 6;
const int pb2 = 7;
const int pb3 = 4;
const int pb4 = 5;

//Velocidades
int Velocidad = 10; //Desde 8 - 14; En Stepper
int VelocidadS = 50; //En Servomotor

void setup() {

  //Variables Generales
  s1.attach(3);
  myStepper.setSpeed(Velocidad);
  pinMode(pb1,INPUT);
  pinMode(pb2,INPUT);
  pinMode(pb3,INPUT);
  pinMode(pb4,INPUT);
}

void loop() {

 //Giro a la Derecha con Stepper
 if(digitalRead(pb1) == HIGH){
  myStepper.step(StepsPerRevolution);
 }

 //Giro a la Izquierda con Stepper
 if(digitalRead(pb2) == HIGH){
  myStepper.step(-StepsPerRevolution);
 }

 //Giro a la Izquierda con Servo
 if(digitalRead(pb3) == HIGH){
  for(x = 180 ; x >= 0; x--){
  s1.write(x);
  delay(VelocidadS);
 }
 }

 //Giro a la Derecha con Servo
 if(digitalRead(pb4) == HIGH){
  for(x = 0 ; x <= 180; x++){
  s1.write(x);
  delay(VelocidadS);
  }
 }
 
}

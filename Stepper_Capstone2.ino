/* Control velocidad y sentido giro de motor PaP con pololu A4988 
 */
 //STEPPER
int steps = 3;       // pin step 9
int direccion = 2;   // pin direccion 3
int potenciometro;   // lectura del potenciometro
 
 //DC
 const int enA = 11 ; //initializing pin 2 as pwm
 int in1 = 6;
 int in2 = 7;

 int rotDirection = 0;
 
void setup() {                
  
  // inicializamos pin como salidas.
  
  pinMode(steps, OUTPUT); 
  pinMode(direccion, OUTPUT); 


  pinMode(enA,OUTPUT) ;    //we have to set PWM pin as output
  pinMode(in1,OUTPUT) ;    //we have to set PWM pin as output
  pinMode(in2,OUTPUT) ;    //we have to set PWM pin as output

  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
}
 
void loop() {
 //STEPPER

    potenciometro = analogRead(A0);     // leemos el potenciometro
    potenciometro = map(potenciometro,0,1024,100,500);  // adaptamos el valor leido a un retardo
    digitalWrite(steps, HIGH);         // Aqui generamos un flanco de bajada HIGH - LOW
    delayMicroseconds(potenciometro);              // Pequeño retardo para formar el pulso en STEP
    digitalWrite(steps, LOW);         // y el A4988 de avanzara un paso el motor
    delayMicroseconds(potenciometro); // generamos un retardo con el valor leido del potenciometro

 //DC
    // If button is pressed - change rotation direction
  if (rotDirection == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    rotDirection = 1;
    delay(20000);
  }
  // If button is pressed - change rotation direction
  if (rotDirection == 1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    rotDirection = 0;
    delay(20000);
  }
  
  }

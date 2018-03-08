//2-Way motor control

int motorPin1 =  5;    // One motor wire connected to digital pin 5
int motorPin2 =  6;    // One motor wire connected to digital pin 6

//Assumptions:
//height of the person is taken as 6'1"
//height of the table is set as 20inches
//height of laptop is set as 10 inches
//height of the ideal height to be set is 52inches
//height of chair at the start is set as 20inches
//Refer to presentation for further clarification of formula
//Diameter of motor used is 2
//For rotating the motor by one turn it takes 10s

//int angle = 0;  
int height = 6.1; //In inches
int temp = 52 - (20+(height*12)/2);
int diameter = 2;
int turn = abs(temp/diameter);
int length=turn*10;


// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pins as an output:
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);  
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()                     
{
  if(temp < 0 )
  { 
  rotateLeft(150, length);
  }
  else 
  {
  rotateRight(50, length);
  }
  
}

void rotateLeft(int speedOfRotate, int length){
  analogWrite(motorPin1, speedOfRotate); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRight(int speedOfRotate, int length){
  analogWrite(motorPin2, speedOfRotate); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}


 
 #define rfReceivePin 12
 #define ledPin 5
int motor_left[]={2,3};
int motor_right[]={6,7};
unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 70;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value

void setup() 
{
   int i;
   for(i = 0; i < 2; i++)
    {
      pinMode(motor_left[i], OUTPUT); 
      pinMode(motor_right[i], OUTPUT);
      pinMode(5, OUTPUT);
    } 
} 
  void loop()
  {
     data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
   
    if(data>upperThreshold){
     digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
     Serial.println(data);
   }
   
   if(data<lowerThreshold){
     digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
     Serial.println(data);
   }
   /* data=digitalRead(12);   //listen for data on Analog pin 0
   
    if(data==HIGH){
        Serial.println("Fwd motion"); 
        forward();
        digitalWrite(5,HIGH);
        delay(3000);//If a LOW signal is received, turn LED OFF
        Serial.println(data);
   }
   
   if(data==LOW){
        Serial.println("Backward motion");
        backward();
                digitalWrite(5,LOW);
        delay(3000);//If a HIGH signal is received, turn LED ON
        Serial.println(data);
   }
    
    
   /* Serial.println("Zero degree left");
    ZeroDegreeLeft();
    delay(3000);
    Serial.println("Zero degree right");
    ZeroDegreeRight();
    delay(3000);*/
  }
  
// Simple functions to move bot   
  void forward()
  {
    digitalWrite(motor_left[0],HIGH);
    digitalWrite(motor_left[1],LOW);
    digitalWrite(motor_right[0],HIGH);
    digitalWrite(motor_right[1],LOW);
   } 
  void backward() 
  { 
    digitalWrite(motor_left[1],HIGH);
    digitalWrite(motor_left[0],LOW);
    digitalWrite(motor_right[1],HIGH);
    digitalWrite(motor_right[0],LOW);
  } 
  void ZeroDegreeLeft()
  {
    digitalWrite(motor_left[1],HIGH);
    digitalWrite(motor_left[0],LOW);
    digitalWrite(motor_right[0],HIGH);
    digitalWrite(motor_right[1],LOW); 
  } 
  void ZeroDegreeRight()
  { 
    digitalWrite(motor_left[0],HIGH);
    digitalWrite(motor_left[1],LOW);
    digitalWrite(motor_right[1],HIGH);
    digitalWrite(motor_right[0],LOW); 
  }

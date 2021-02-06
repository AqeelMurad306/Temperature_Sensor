int TMP = A5;
const int led_red = 2;
const int led_blue = 3;
const int led_green = 4;

void setup()
{
  pinMode(TMP, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(led_green, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float sensorInput = analogRead(TMP);
  
  float temp = sensorInput / 1024; 
  temp = temp * 5;                 
  temp = temp - 0.5;                
  temp = temp * 100;                
 
  Serial.print("Current Temperature: ");
  Serial.println(temp);

  if (temp < 25) {
    digitalWrite(led_red, HIGH);
    delay(5000);
    digitalWrite(led_red, LOW);
    delay(10);
  }
  
  else if (temp < 45){
    digitalWrite(led_blue, HIGH);
    delay(5000);
    digitalWrite(led_blue, LOW);
    delay(10);
  }    
  
  else if (temp > 46){
    digitalWrite(led_green, HIGH);
    delay(5000);
    digitalWrite(led_green, LOW);
    delay(10);
  }
  
  delay(1000);
}

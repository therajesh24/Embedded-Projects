


void setup() // put your setup code here, to run once:
{
 
  Serial.begin(9600);
 
}

void loop() // put your main code here, to run repeatedly:
{
  
int x = analogRead(A0);  //read from xpin
 
 int y = analogRead(A1);//read from ypin
 // float zero_G = 512.0; //ADC is 0~1023  the zero g output equal to Vs/2
                      //ADXL335 power supply by Vs 3.3V
//float scale = 102.3;  //ADXL335330 Sensitivity is 330mv/g
                       //330 * 1024/3.3/1000  
 int xsam=((float)x - 200)/5;
 int ysam=((float)y - 200)/5;
  Serial.print("\t xsam:");
  Serial.println(xsam);
  Serial.print("\t ysam:");
  Serial.println(ysam);
  delay(2000);
 
  Serial.print("\n");

  if((xsam<100)||(xsam>120))
   { 
   Serial.print("PERSON FELL DOWN BUZZER ON");
 
 delay(1000);
    }
    
}


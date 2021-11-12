#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#include <SoftwareSerial.h>
SoftwareSerial gps(2,3);

const int xpin = A1;                  // x-axis of the accelerometer
const int ypin = A2; 
char str[70];
String gpsString="";
char *test="$GPGGA";
String latitude="No Range      ";
String longitude="No Range     ";
int temp=0,i;
boolean gps_status=0;
int x1;            
int y1;
int inchar;




void setup() // put your setup code here, to run once:
{
 
  Serial.begin(9600);
  gps.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ACCIDENT PREVENTION");
  lcd.setCursor(4,1);
  lcd.print("SYSTEM");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GPS Initializing");
  lcd.setCursor(0,1);
  lcd.print("  No GPS Range  ");
  get_gps();
  delay(2000);
  lcd.clear();
  lcd.print("GPS Range Found");
  lcd.setCursor(0,1);
  lcd.print("GPS is Ready");    
  delay(2000);
  lcd.clear();
  lcd.print("System Ready");
  temp=0; 
//  pinMode(ir1,INPUT);
//   pinMode(ir2,INPUT);
  //  pinMode(mt,OUTPUT);

}

void loop() // put your main code here, to run repeatedly:
{
  
int x = analogRead(A1);  //read from xpin
 
int y = analogRead(A2);  //read from ypin
 // float zero_G = 512.0; //ADC is 0~1023  the zero g output equal to Vs/2
                      //ADXL335 power supply by Vs 3.3V
//float scale = 102.3;  //ADXL335330 Sensitivity is 330mv/g
                       //330 * 1024/3.3/1000  
 int xsam=((float)x - 200)/5;
  int ysam=((float)y - 200)/5;
  Serial.print("\t xsam:");
  Serial.print(xsam);
  Serial.print("\t ysam:");
  Serial.print(ysam);
  delay(2000);
 
  Serial.print("\n");
  lcd.clear();
  lcd.print("SYSTEM STABLE");
  lcd.setCursor(0,1);
  lcd.print("NO PROBLEM");    
  delay(100);
  if((xsam<35)||(xsam>50)||(ysam<35)||(ysam>50))
   { 
    lcd.clear();
  lcd.print("ACCIDENT");
  Serial.println("ACCIDENT");
  lcd.setCursor(0,1);
  lcd.print("ACCOURED");    
  //delay(1000);
  /*lcd.clear();
  lcd.print("MAKING CALL");
  lcd.setCursor(0,1);
  lcd.print("......");    
  delay(1000);
    delay(1000);
    Serial.println("AT");
    delay(1000); 
   Serial.println("ATD7905950195;");
   delay(10000);
   Serial.println("ATH");*/
  
    get_gps();
    delay(1000);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SENDING ");
    lcd.setCursor(0,4);
    lcd.print("MESSAGE");
    //delay(500);
   
 sms1();
  
    
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ACCIDENT PREVENTION");
  lcd.setCursor(4,1);
  lcd.print("SYSTEM");
  //delay(2000);
    }
}
void gpsEvent()
{
  gpsString="";
  while(1)
  {
   while (gps.available()>0)            //checking serial data from GPS
   {
    char inChar = (char)gps.read();
     gpsString+= inChar;                    //store data from GPS into gpsString
     i++;
     if (i < 7)                      
     {
      if(gpsString[i-1] != test[i-1])         //checking for $GPGGA sentence
      {
        i=0;
        gpsString="";
      }
     }
    if(inChar=='\r')
    {
     if(i>65)
     {
       gps_status=1;
       break;
     }
     else
     {
       i=0;
     }
    }
  }
   if(gps_status)
    break;
  }
}

void get_gps()
{
   gps_status=0;
   int x=0;
   while(gps_status==0)
   {
    gpsEvent();
    int str_lenth=i;
    latitude="";
    longitude="";
    int comma=0;
    while(x<str_lenth)
    {
      if(gpsString[x]==',')
      comma++;
      if(comma==2)        //extract latitude from string
      latitude+=gpsString[x+1];     
      else if(comma==4)        //extract longitude from string
      longitude+=gpsString[x+1];
      x++;
    }
    int l1=latitude.length();
    latitude[l1-1]=' ';
    l1=longitude.length();
    longitude[l1-1]=' ';
    lcd.clear();
    lcd.print("Lat:");
    lcd.print(latitude);
    lcd.setCursor(0,1);
    lcd.print("Long:");
    lcd.print(longitude);
    i=0;x=0;
    str_lenth=0;
    delay(2000);
   }
}
void sms1()
{
  Serial.println("AT");  
    delay(1000);
    Serial.println("ATE0");  
    delay(1000);
    Serial.println("AT+CMGF=1");   
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MSG SENDING..");
    Serial.println("AT+CMGS=\"+916304006901\"\r"); 
    delay(1000);
    Serial.println("ACCIDENT OCCOURED AT:");
    Serial.print("LATITUDE:");
    Serial.println(latitude);
    Serial.print("LONGITUDE:");
    Serial.println(longitude);
    delay(1000);
    Serial.println((char)26);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MSG SENT :)");
    delay(2000);
}

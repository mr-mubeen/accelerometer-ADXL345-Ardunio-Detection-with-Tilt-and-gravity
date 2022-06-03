#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <Wire.h>


// Accelerometer MEMS
int ADXL345 = 0x53;
int X_out, Y_out, Z_out;


void setup(){
    Serial.begin(9600);

  Serial.println("-------- CAR ACCIDENT DETECTION USING SHOCK SENSOR, ADXL345, GSM AND GPS WITH LIVE TRACKING LOCATION ------");

}



void loop(){

  // ADXL345 Accelerometer        
        Wire.beginTransmission(ADXL345);
        Wire.write(0x32);
        Wire.endTransmission(false);
        Wire.requestFrom(ADXL345, 6, true);
     
        X_out = ( Wire.read() | Wire.read() << 8);
        Y_out = ( Wire.read() | Wire.read() << 8);
        Z_out = ( Wire.read() | Wire.read() << 8);
     
        Serial.print("        X");
        Serial.print(X_out);
        Serial.println(" ");
//        Serial.print("Y");
     
//        Serial.print(Y_out);
//        Serial.print(" ");
     
        delay(2000);
}

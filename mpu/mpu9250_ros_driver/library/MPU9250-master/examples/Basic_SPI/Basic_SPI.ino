/*
Basic_SPI.ino
Brian R Taylor
brian.taylor@bolderflight.com

Copyright (c) 2017 Bolder Flight Systems

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on SPI bus 0 and chip select pin 10
MPU9250 imu_Link(SPI,10);
int status;

void setup() {
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with imu_Link 
  status = imu_Link.begin();
  if (status < 0) {
    Serial.println("imu_Link initialization unsuccessful");
    Serial.println("Check imu_Link wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  // read the sensor
  imu_Link.readSensor();
  // display the data
  Serial.print(imu_Link.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getGyroZ_rads(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print(imu_Link.getMagZ_uT(),6);
  Serial.print("\t");
  Serial.println(imu_Link.getTemperature_C(),6);
  delay(100);
}

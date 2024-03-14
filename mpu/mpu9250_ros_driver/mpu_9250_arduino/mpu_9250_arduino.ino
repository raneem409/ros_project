#include "MPU9250.h"
#include <ros.h>
#include <sensor_msgs/Imu.h>

ros::NodeHandle  nh;
sensor_msgs::Imu imu_msg;
ros::Publisher imu_pub("/imu/data_raw", &imu_msg);
long sequence = 0;

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 imu_Link(Wire,0x68);
int status;

void setup() {
  // serial to display data
  Serial.begin(57600);
  while(!Serial) {}

  nh.initNode();
  nh.advertise(imu_pub);

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
/*
  Serial.print("AccelX: ");
  Serial.print(imu_Link.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print("AccelY: ");  
  Serial.print(imu_Link.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print("AccelZ: ");  
  Serial.println(imu_Link.getAccelZ_mss(),6);
  
  Serial.print("GyroX: ");
  Serial.print(imu_Link.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print("GyroY: ");  
  Serial.print(imu_Link.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print("GyroZ: ");  
  Serial.println(imu_Link.getGyroZ_rads(),6);

  Serial.print("MagX: ");  
  Serial.print(imu_Link.getMagX_uT(),6);
  Serial.print("\t");  
  Serial.print("MagY: ");
  Serial.print(imu_Link.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print("MagZ: ");  
  Serial.println(imu_Link.getMagZ_uT(),6);
*/
  //Header
  imu_msg.header.seq = sequence++;
  imu_msg.header.stamp = nh.now();
  imu_msg.header.frame_id  ="imu_Link";

  //Linear Acceleration 
  imu_msg.linear_acceleration.x = imu_Link.getAccelX_mss() ;
  imu_msg.linear_acceleration.y = imu_Link.getAccelY_mss() ;
  imu_msg.linear_acceleration.z = imu_Link.getAccelZ_mss() ;
  
  //Angular Velocity
  imu_msg.angular_velocity.x = imu_Link.getGyroX_rads() ;
  imu_msg.angular_velocity.y = imu_Link.getGyroY_rads() ; 
  imu_msg.angular_velocity.z = imu_Link.getGyroZ_rads() ;  

  //Orientation
  imu_msg.orientation.x = 0 ;
  imu_msg.orientation.y = 0 ;
  imu_msg.orientation.z = 0 ;
  imu_msg.orientation.w = 0 ;

  imu_pub.publish(&imu_msg);
  nh.spinOnce();
  
  delay(10);
} 

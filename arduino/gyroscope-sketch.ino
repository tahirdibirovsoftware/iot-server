#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 accelgyro;


void setup() {
    Serial.begin(115200); // Start serial communication at 115200 baud
    Wire.begin();         // Initialize I2C
    accelgyro.initialize(); // Initialize the MPU-6050 sensor
    
    // Check if MPU-6050 is connected properly
    if (!accelgyro.testConnection()) {
        Serial.println("MPU6050 connection failed");
    } else {
        Serial.println("MPU6050 connection successful");
    }
}


void loop() {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    // Read raw accel/gyro measurements from MPU-6050
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Start JSON output
    Serial.print("{");

    // Add accelerometer data to JSON
    Serial.print("\"accelerometer\":{");
    Serial.print("\"x\":"); Serial.print(ax);
    Serial.print(", \"y\":"); Serial.print(ay);
    Serial.print(", \"z\":"); Serial.print(az);
    Serial.print("}, ");

    // Add gyroscope data to JSON
    Serial.print("\"gyroscope\":{");
    Serial.print("\"x\":"); Serial.print(gx);
    Serial.print(", \"y\":"); Serial.print(gy);
    Serial.print(", \"z\":"); Serial.print(gz);
    Serial.print("}");

    // End JSON output
    Serial.println("}");

    delay(100); // Delay to make the output readable
}

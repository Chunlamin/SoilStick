/*
 * โค๊ดตัวอย่างการทดสอบการอ่านค่าเอ๊าต์พุทของเซนเซอร์วัดความชื้นในดิน Soil Stick
 * 
 * 15 April 2020
 * facebook fan page: เกษตรไทย IoT
 */

#define ANALOG_PIN A0
#define ENABLE_PIN A1

void setup() {
  Serial.begin(115200);           // กำหนดค่าเริ่มต้นความเร็วซีเรียลที่ 115200
  pinMode(ENABLE_PIN, OUTPUT);    // กำหนดให้ENABLE_PINอยู่ในโหมดเอ้าต์พุท
  digitalWrite(ENABLE_PIN, HIGH); // ให้ENABLE_PIN เป็นhighเพื่อเปิดการทำงานของ Soil Stick
  delay(1000);                    // หน่วงเวลา 1วินาที เพื่อให้เอ้าต์พุทของ Soil Stick เริ่มนิ่ง
}

void loop() {
  float sensorValueVoltage = (float)analogRead(ANALOG_PIN)*5.0/1024.0;  // อ่านค่าอนาล๊อคจากANALOG_PIN และแปลงค่าที่อ่านได้เป็นแรงดันไฟฟ้า
  Serial.print("Soil Stick output = "); // แสดงข้อความ "Soil Stick output = " ทางซีเรียลมอนิเตอร์
  Serial.print(sensorValueVoltage);  // แสดงค่าแรงดันไฟฟ้าทางซีเรียลมอนิเตอร์
  Serial.print(" Volt\n");  // แสดงข้อความ "Volt" ทางซีเรียลมอนิเตอร์ และขึ้นบรรทัดใหม่
  delay(1000);  // หน่วงเวลา 1วินาที
}

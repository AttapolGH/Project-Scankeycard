

#include <SPI.h>
#include "MFRC522.h"
#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>

boolean staruwork[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#define LINE_TOKEN  "Elqn2D2QK5ruIhRtecwYm0FXhlKmRGN3t2k9FrIg21q"   // TOKEN
#define SSID        "siripat Floor 2"   // ชื่อ Wifi
#define PASSWORD    "0866916619"   // รหัส Wifi

#define RST_PIN  D1
#define SS_PIN  D2
#define BUZZER_PIN D0 // กำหนดหมายเลขขา D3 หรือหมายเลขขาที่คุณต่อ Buzzer

MFRC522 mfrc522(SS_PIN, RST_PIN);

String rfid_in = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("");
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting ",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);
  Serial.println("");
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    rfid_in=rfid_read();
    Serial.print(">>>> " + rfid_in);
    if(rfid_in=="73 3B 8E FB"){
      controlBuzzer(); // เรียกใช้ฟังก์ชันควบคุม Buzzer
      if(staruwork[0]==0){
        staruwork[0]=1;
        Serial.println(" >>>> นาย อรรถพล พุ่มชัย เข้าเรียน");
        LINE.notifyPicture("นายอรรถพล พุ่มชัย เข้าเรียน","https://scontent.fbkk4-4.fna.fbcdn.net/v/t39.30808-6/293627105_1121195751796092_5630101857069595150_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=9c7eae&_nc_eui2=AeHFglrHg-fBhLmWTQTmaD-6ovoBMJLpU1-i-gEwkulTX-yxByYkCIUWgXNJkdtYUOnwrDc0lRI7xWhKsWXTGZNc&_nc_ohc=YkVnpjSpbtMAX-9vtMj&_nc_zt=23&_nc_ht=scontent.fbkk4-4.fna&oh=00_AfAo1mLdv445yzAnY8RS3LTTO31P5N5Fek5Ev__lAD_KGA&oe=65BA4FB2");
      }
      else{
        staruwork[0]=0;
        Serial.println(" >>>> นาย อรรถพล พุ่มชัย ออกห้องเรียน");
        LINE.notifyPicture("นายอรรถพล พุ่มชัย ออกห้องเรียน","https://scontent.fbkk4-4.fna.fbcdn.net/v/t39.30808-6/293627105_1121195751796092_5630101857069595150_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=9c7eae&_nc_eui2=AeHFglrHg-fBhLmWTQTmaD-6ovoBMJLpU1-i-gEwkulTX-yxByYkCIUWgXNJkdtYUOnwrDc0lRI7xWhKsWXTGZNc&_nc_ohc=YkVnpjSpbtMAX-9vtMj&_nc_zt=23&_nc_ht=scontent.fbkk4-4.fna&oh=00_AfAo1mLdv445yzAnY8RS3LTTO31P5N5Fek5Ev__lAD_KGA&oe=65BA4FB2");
      }
      delay(2000);
            
    }
    else if(rfid_in=="A3 AE 8B C5"){
      controlBuzzer(); // เรียกใช้ฟังก์ชันควบคุม Buzzer
      if(staruwork[1]==0){
        staruwork[1]=1;
        Serial.println(" >>>> นาย จิรฉัตร ทองทะวัย เข้าเรียน");
        LINE.notifyPicture("นาย จิรฉัตร ทองทะวัย เข้าห้องเรียน","https://scontent.fbkk3-2.fna.fbcdn.net/v/t39.30808-6/285520092_3300033330276107_1603805143630305373_n.jpg?_nc_cat=104&ccb=1-7&_nc_sid=efb6e6&_nc_eui2=AeEde8Hv1TFSZeGoIkaMZ1nCviXp3bIXnvm-Jendshee-YcviOZMFiSH286qc6SPU5swrFAR-DNc6jcoXZSe78wR&_nc_ohc=7bwzF4C4nWkAX8hbK4P&_nc_zt=23&_nc_ht=scontent.fbkk3-2.fna&oh=00_AfAnUGXvL3e4GkPVZUatgKVYHbwVzf0axGMA9DDl2mYN0w&oe=65B98EB7");
      }
      else{
        staruwork[1]=0;
        Serial.println(" >>>> นาย จิรฉัตร ทองทะวัย ออกเรียน");
        LINE.notifyPicture("นาย จิรฉัตร ทองทะวัย ออกห้องเรียน","https://scontent.fbkk3-2.fna.fbcdn.net/v/t39.30808-6/285520092_3300033330276107_1603805143630305373_n.jpg?_nc_cat=104&ccb=1-7&_nc_sid=efb6e6&_nc_eui2=AeEde8Hv1TFSZeGoIkaMZ1nCviXp3bIXnvm-Jendshee-YcviOZMFiSH286qc6SPU5swrFAR-DNc6jcoXZSe78wR&_nc_ohc=7bwzF4C4nWkAX8hbK4P&_nc_zt=23&_nc_ht=scontent.fbkk3-2.fna&oh=00_AfAnUGXvL3e4GkPVZUatgKVYHbwVzf0axGMA9DDl2mYN0w&oe=65B98EB7");
      }
      delay(2000);
    }
    else{
        controlBuzzeri(); // เรียกใช้ฟังก์ชันควบคุม Buzzer
        Serial.println(" >>>> No data");
        LINE.notifyPicture("นักเรียนที่ไม่ได้อยู่ในคลาส","https://1417094351.rsc.cdn77.org/articles/5442/5441460/thumbnail/small.gif?1");
      }
  }
  delay(2000);
}

String rfid_read() {
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  return content.substring(1);
}

void controlBuzzer(){
  tone(BUZZER_PIN, 1000,500);
  delay(150);
}

void controlBuzzeri(){
  tone(BUZZER_PIN, 1000, 100);
  delay(100);
  tone(BUZZER_PIN, 0, 100);
  delay(100);
  tone(BUZZER_PIN, 1000, 100);
  delay(100);
  tone(BUZZER_PIN, 0, 100);
  delay(100);
  tone(BUZZER_PIN, 1000, 100);
  delay(100);
  tone(BUZZER_PIN, 0, 100);
  delay(100);
}

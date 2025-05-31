#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define trigPin 11
#define echoPin 12


Servo myServo;
int servoPin = 3;

void setup()
{

  pinMode(trigPin,OUTPUT);
  pinMode(trigPin,INPUT);

  myServo.attach(servoPin);
  Serial.println(myServo.attached());

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

}

void loop(){
  

  int angle;

  int distance_result = check_distance();

  work_servo(distance_result);
  

}

int work_servo(int distance){
  if(distance){//1 :: 20초과 >> 쓰레기 다 차지 않은 상태 > 0도
    // 
    Serial.println("20 초과 > 아직 ㄱㅊ음");
    myServo.write(0);
    delay(500);           // 잠깐 유지 (0.5초 정도)
    
  }else{
    // 0 :: 미만 쓰레기가 꽉 찬 상태 > 90 도
    Serial.println("20 이하 > 쓰레기 꽉 참");
    myServo.write(180);
    delay(500);           // 잠깐 유지 (0.5초 정도)
  }
}

int check_distance(){

  int result = 0; 
  //0이면 20cm 이하, 1이면 20cm초과

  long duration, distance;

  //초음파 발사 trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //10초
  digitalWrite(trigPin, LOW);

  //초음파가 사물 맞도 돌아온 시간 저장
  duration = pulseIn(echoPin, HIGH);
  //시간을 거리로 cm단위 환산
  distance = ((duration * 340) / 10000) / 2;

  print_lcd(distance);

  if (distance <= 20) {//
    result = 0;
  }else{
    result = 1;
  }

  return result;
}

void print_lcd(int distance){
  
  lcd.clear();
  lcd.setCursor(1,0);
  
  //확인용 print - log 느낌?
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm\n");

  //거리가 너무 크면 짤려서 나와염 
  lcd.setCursor(2,1);
  lcd.print("dis : ");
  lcd.print(distance);
  lcd.println("cm");
  delay(1000);
}

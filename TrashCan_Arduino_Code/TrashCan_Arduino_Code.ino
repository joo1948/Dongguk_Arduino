#include <Servo.h>

Servo myServo;
int servoPin = 3;
String buffer = "";
int trigPin = 5;           //초음파 센서 trig에 달린 번호
int echoPin = 6;           //초음파 센서 echo 에 달린 번호


void setup() {
  // put your setup code here, to run once:
  //초음파 센서

  
  Serial.begin(9600);
  pinMode(echoPin, INPUT);   // echo 초음파 돌아옴
  pinMode(trigPin, OUTPUT);  // trig 초음파

  myServo.attach(servoPin);
  Serial.println(myServo.attached());

}

void loop() {
  // put your main code here, to run repeatedly:
  int angle;
  
  int distance =   check_distance(); 
  


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


  //시리얼 모니터에 거리 출력
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm\n");

  delay(1000);

  if (distance <= 20) {//
    result = 0;
  }else{
    result = 1;
  }

  return result;
}

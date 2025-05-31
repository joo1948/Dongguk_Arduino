
# 개요
# 이미지 
1. 2차 테스트
<img src="https://github.com/user-attachments/assets/8450ad46-140d-4594-b74b-fd9e4bcc62b2"  width="400" height="500"/>

- 초음파센서 + 서보모터에서 **LCD 판 추가**
- **추후 구현 예정 : 무게감지 센서 + 소리 내는 센서 + 초음파 센서 한개 더 + wifi 모듈 추가

3. 1차 테스트
<img src="https://github.com/user-attachments/assets/ac10eb12-5c09-451a-8fd8-79285936df46"  width="400" height="500"/>


- 현재 거리감지 센서가 없어서 기본키트인 초음파 센서로 거리 측정
- 20CM 이하 : 쓰레기 찼다고 판단 -> 모터 90도 회전
- 20CM 초과 : 쓰레기 양 괜찮다고 판단 -> 모터 0도 회전
- **문제 : 서보모터랑 초음파 센서가 동일하게 5V를 사용하는데, 전력 문제 괜찮은지**
  - 추가 외부 전력 사용 예정

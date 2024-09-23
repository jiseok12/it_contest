/*
 * 무게 센서데이터를 읽어와 그래프로 출력한다 
*/
#include "HX711.h"

/*
 * HX711 센서 핀을 지정한다 
*/
HX711 scale(14, 27);
HX711 scale2(26, 25);   
HX711 scale3(22, 23);     //오류 발생
HX711 scale4(17, 5);

/*
 * 초기 시작 데이터를 입력 받는다 
*/
long settingvalue1; 
long settingvalue2;
long settingvalue3;
long settingvalue4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  settingvalue1 = scale.read(); //1번 센서 처음 세팅 값
  
  settingvalue2 = scale2.read(); //2번 센서 처음 세팅 값
  settingvalue3 = scale3.read(); //3번 센서 처음 세팅 값
  settingvalue4 = scale4.read(); //4번 센서 처음 세팅 값
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * 센서 데이터를 읽어온다 
  */
  long reading = valueconf();
  long reading2 = valueconf2();
  long reading3 = valueconf3();
  long reading4 = valueconf4();

  /*
   * 읽어온 데이터를 출력한다 
  */
  Serial.print(" s1:");                   // 1번 센서 값
  Serial.print(reading-settingvalue1);
  Serial.print(" s2:");                   // 2번 센서 값
  Serial.print(reading2-settingvalue2);
  Serial.print(" s3:");                   // 3번 센서 값
  Serial.print(reading3-settingvalue3);
  Serial.print(" s4:");                   // 4번 센서 값
  Serial.println(reading4-settingvalue4);
}

// 데이터 노이즈를 제거
/*
 *  센서값을 읽어와 데이터의 평균을 구한다
*/
long valueconf(){
  long readingav=0;
  for(int i=0;i<=3;i++){
    readingav=readingav+scale.read();
  }
  return readingav/4;
}

long valueconf2(){
  long readingav=0;
  for(int i=0;i<=3;i++){
    readingav=readingav+scale2.read();
  }
  return readingav/4;
}

long valueconf3(){
  long readingav=0;
  for(int i=0;i<=3;i++){
    readingav=readingav+scale3.read();
  }
  return readingav/4;
}

long valueconf4(){
  long readingav=0;
  for(int i=0;i<=3;i++){
    readingav=readingav+scale4.read();
  }
  return readingav/4;
}

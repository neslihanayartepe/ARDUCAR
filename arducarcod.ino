int MAileri = 7; //MOTORA ileri
int MAgeri = 8 ;  //MOTORB geri
int MBileri = 6;
int MBgeri = 5;
int vSpeed = 255;
int state; //Bluetooth cihazından gelecek sinyalin değişkeni
int i = 0; //Döngüler için atanan rastgele bir değişken
int j = 0; //Döngüler için atanan rastgele bir değişken
int enA = 9;

void setup() {

  pinMode(MAileri, OUTPUT);
  pinMode(MAgeri, OUTPUT);
  pinMode(MBileri, OUTPUT);
  pinMode(MBgeri, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
  }


  //Gelen veri 'F' ise araba ileri gider.
  if (state == 'F') {
    analogWrite(MAileri, vSpeed);
    analogWrite(MAgeri, 0);
    analogWrite(MBileri, vSpeed);
    analogWrite(MBgeri, 0);
  }


  //Gelen veri 'B' ise araba geri gider.
  else if (state == 'B') {
    analogWrite(MAileri, 0);
    analogWrite(MAgeri, vSpeed);
    analogWrite(MBileri, 0);
    analogWrite(MBgeri, vSpeed);
  }
  //Gelen veri 'L' ise araba sola gider.
  else if (state == 'L') {
    analogWrite(MAileri, 40);   analogWrite(MAgeri, 0);
    analogWrite(MBileri, vSpeed); analogWrite(MBgeri, 0);
  }
  //Gelen veri 'R' ise araba sağa gider
  else if (state == 'R') {
    analogWrite(MAileri, vSpeed);   analogWrite(MAgeri, 0);
    analogWrite(MBileri, 40) ;   analogWrite(MBgeri, 0);
  }
  //Gelen veri 'G' ise araba ileri sol(çapraz) gider.
  else if (state == 'G') {
    analogWrite(MAileri, 40 ); analogWrite(MAgeri, 0);
    analogWrite(MBileri, vSpeed);    analogWrite(MBgeri, 0);
  }
  //Gelen veri 'I' ise araba ileri sağ(çapraz) gider.
  else if (state == 'I') {
    analogWrite(MAileri, vSpeed); analogWrite(MAgeri, 0);
    analogWrite(MBileri, 40);      analogWrite(MBgeri, 0);
  }
  //Gelen veri 'H' ise araba geri sol(çapraz) sola doğru geri gider
  else if (state == 'H') {
    analogWrite(MAileri, 0);   analogWrite(MAgeri, 40);
    analogWrite(MBileri, 0); analogWrite(MBgeri, vSpeed);
  }
  //Gelen veri 'J' ise araba geri sağ(çapraz) sağa doğru geri gider
  else if (state == 'J') {
    analogWrite(MAileri, 0);   analogWrite(MAgeri, vSpeed);
    analogWrite(MBileri, 0);   analogWrite(MBgeri, 40);
  }

  //Gelen veri 'S' ise arabayı durdur.
  else if (state == 'S') {
    analogWrite(MAileri, 0);  analogWrite(MAgeri, 0);
    analogWrite(MBileri, 0);  analogWrite(MBgeri, 0);
  }
}

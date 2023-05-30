int kyori = 1;//距離センサからの値の入力　A0~A5から選ぶ（Aは書かなくてOK）
int LED = 2;//距離が近づいた時に光るLED
int volume = 3;//コントローラーの速度調整用ボリュームからの入力　A0~A5から選ぶ（Aは書かなくてOK）
int motor = 3;//モータードライバー制御用の出力　ピン番号の前に~が付いているところから選ぶ

void setup() {
  //準備
  pinMode(LED,OUTPUT);
  Serial.begin(600);
}

void loop() {
  //もし距離が近ければLEDを点灯させる
  if(analogRead(kyori) >= 512){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED,LOW);
  }

  //ボリュームの値に合わせてモータードライバーへの出力を変える
  analogWrite(motor, analogRead(volume) / 4);
  
  //距離センサの値確認用
  Serial.println(analogRead(kyori));
}

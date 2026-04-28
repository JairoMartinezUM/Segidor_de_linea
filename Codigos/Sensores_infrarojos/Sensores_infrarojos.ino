//este es el que se supone ya tiene todos los pines y todo bien mas nio arranco 
const int s0 = 26;
const int s1 = 27;
const int s2 = 14;
const int s3 = 12;
const int lectura = 13;

int mdpwm=4;
int diri=17;

//derecho
int mipwm=16;
int dird=2;

void setup() {
  Serial.begin(115200);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(lectura, INPUT); 
  
  pinMode(mdpwm, OUTPUT);
  pinMode(mipwm, OUTPUT);
  pinMode(diri, OUTPUT);
  pinMode(dird, OUTPUT);
}

void loop() {
  for (byte i = 0; i < 16; i++) {
    byte j = i;
    bool a = bitRead(j, 0);
    bool b = bitRead(j, 1);
    bool c = bitRead(j, 2);
    bool d = bitRead(j, 3);
    digitalWrite(s0, a);
    digitalWrite(s1, b);
    digitalWrite(s2, c);
    digitalWrite(s3, d);

    int valor_leido = analogRead(lectura);

    Serial.print(valor_leido);
    Serial.print("\t");
  }
  Serial.println();
  delay(100);

  digitalWrite(diri, HIGH);
  digitalWrite(dird, HIGH);
  analogWrite(mdpwm, 127);
  analogWrite(mipwm, 65);
}
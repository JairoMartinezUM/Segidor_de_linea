int mdpwm=4;
int diri=17;
int mipwm=16;
int dird=2;

void setup() {
pinMode(mdpwm,OUTPUT);
pinMode(mipwm,OUTPUT);
pinMode(diri,OUTPUT);
pinMode(dird,OUTPUT);
}

void loop() {
digitalWrite(diri,HIGH);
digitalWrite(dird,HIGH);
analogWrite(mdpwm,127);
analogWrite(mipwm,65);
}

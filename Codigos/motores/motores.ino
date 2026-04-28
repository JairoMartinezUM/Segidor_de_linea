//y este es que tienen  formas de camiar de dirección y todo eso pero no los e aplicado 
// Definición pines multiplexor
const int s0 = 26;
const int s1 = 27;
const int s2 = 15;
const int s3 = 12;
const int lectura = 13;

// Definición pines motores
// Izquierdo
int mdpwm = 4;
int diri = 17;

// Derecho
int mipwm = 16;
int dird = 2;

void setup() {
  Serial.begin(115200);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(lectura, INPUT); // Asegúrate de configurar el pin de lectura como entrada

  pinMode(mdpwm, OUTPUT);
  pinMode(mipwm, OUTPUT);
  pinMode(diri, OUTPUT);
  pinMode(dird, OUTPUT);
}

void loop() {
  int sensores[16]; // Arreglo para guardar las lecturas
  for (byte i = 0; i < 16; i++) // Leer los 16 posibles canales del multiplexor
  {
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
    sensores[i] = valor_leido; // Guardar valores en el arreglo

    Serial.print(valor_leido);
    Serial.print("\t");
  }
  Serial.println();

  // Toma de decisiones (activado)
  if (sensores[7] < 500||sensores[8] < 500 || sensores[9] < 500 || sensores[10] < 500) {
    // Centro
    Serial.println("centro");
    digitalWrite(diri, HIGH);
    digitalWrite(dird, HIGH);
    analogWrite(mdpwm, 30);
    analogWrite(mipwm, 30); // Misma velocidad para ambos motores para ir recto
  } else if (sensores[11] < 500||sensores[12] < 500||sensores[13] < 500) {
    // Izquierda
    Serial.println("izquierda");
    digitalWrite(diri, LOW);  // Un motor hacia adelante
    digitalWrite(dird, HIGH); // El otro motor hacia adelante (para girar)
    analogWrite(mdpwm, 100);
    analogWrite(mipwm, 100);
  } else if (sensores[2] < 500||sensores[3] < 500||sensores[4] < 500) {
    // Derecha
    Serial.println("derecha");
    digitalWrite(diri, HIGH); // Un motor hacia adelante
    digitalWrite(dird, LOW);  // El otro motor hacia adelante (para girar)
    analogWrite(mdpwm, 100);
    analogWrite(mipwm, 100);
  } else {
    // Perdido o no detecta línea
    Serial.println("perdido");
    digitalWrite(diri, LOW);
    digitalWrite(dird, LOW);
    analogWrite(mdpwm, 0);
    analogWrite(mipwm, 0); // Detener los motores
  }
}
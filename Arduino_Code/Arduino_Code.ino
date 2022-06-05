//LED-Pin Eşleştirmeleri:
#define L1 9
#define L2 8
#define L3 7
#define L4 6
#define L5 5
#define L6 4
#define L7 3
#define L8 2
//Su pompası ve nem sensörü pin eşleştirmeleri:
#define M 10
#define nem A0

int nem_deger = 0;  //Okunacak nem değeri için değişken oluşturma.

void setup() {
  //LED ve pompa pinlerini çıkış olarak ayarlama:
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  pinMode(M, OUTPUT);

  Serial.begin(115200); //Seri haberleşmeyi başlatma. (115200 Baud Rate)
}

void loop() {
  nem_deger = 800 - map(analogRead(nem), 0, 1023, 0, 800);  //Nem değerini okuma
  
  if (nem_deger >= 0 && nem_deger <= 100) //1.kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
    analogWrite(M, 255);
    Serial.print("1,");
  }
  
  if (nem_deger > 100 && nem_deger <= 200)//2. kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
    analogWrite(M, 255);
    Serial.print("1,");
  }
  
  if (nem_deger > 200 && nem_deger <= 300)//3.kademe{
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
    analogWrite(M, 255);
    Serial.print("1,");
  }
  
  if (nem_deger > 300 && nem_deger <= 400)//4.kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
    analogWrite(M, 255);
    Serial.print("1,");
  }
  
  if (nem_deger > 400 && nem_deger <= 500)//5.kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
    digitalWrite(M, LOW);
    Serial.print("0,");
  }
  
  if (nem_deger > 500 && nem_deger <= 600)//6.kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, HIGH);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
    digitalWrite(M, LOW);
    Serial.print("0,");
  }
  
  if (nem_deger > 600 && nem_deger <= 700)//7.kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, HIGH);
    digitalWrite(L7, HIGH);
    digitalWrite(L8, LOW);
    digitalWrite(M, LOW);
     Serial.print("0,");
  }
  
  if (nem_deger > 700 && nem_deger <= 800)//8.kademe
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, HIGH);
    digitalWrite(L7, HIGH);
    digitalWrite(L8, HIGH);
    digitalWrite(M, LOW);
    Serial.print("0,");
  }
  
  Serial.println(100 - map(analogRead(nem), 0, 1023, 0, 100));  //Okunan nem değerini seri porttan yazdırma.
  delay(10);
}

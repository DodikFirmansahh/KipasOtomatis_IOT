#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --- KONFIGURASI PIN & SENSOR ---
#define DHTPIN 2          // Pin Data DHT11 terhubung ke Digital 2
#define DHTTYPE DHT11     // Tipe Sensor DHT
#define RELAY_PIN 3       // Pin Kontrol Relay terhubung ke Digital 3

// --- KONFIGURASI AMBANG BATAS SUHU ---
const float TEMP_THRESHOLD = 30.0; // Kipas menyala jika suhu >= 30.0 °C

// Inisialisasi LCD (Alamat I2C umum: 0x27 atau 0x3F, ukuran 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Inisialisasi Sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inisialisasi Pin Relay
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Matikan Relay di awal (Active LOW relay)

  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  
  // Tampilan Awal (Splash Screen)
  lcd.setCursor(0, 0);
  lcd.print(" System Starting");
  lcd.setCursor(0, 1);
  lcd.print("   Auto Fan 12V ");
  delay(2000);
  lcd.clear();

  // Inisialisasi Sensor DHT11
  dht.begin();
}

void loop() {
  // Membaca suhu dalam satuan Celsius
  float temp = dht.readTemperature();

  // Cek apakah pembacaan sensor gagal
  if (isnan(temp)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Read Temp!");
    return;
  }

  // Tampilkan pembacaan suhu pada LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu : ");
  lcd.print(temp, 1); // Menampilkan 1 angka di belakang koma
  lcd.print((char)223); // Simbol Derajat (°)
  lcd.print("C   ");

  // Logika Kontrol Kipas / Relay
  if (temp >= TEMP_THRESHOLD) {
    // Jika suhu melebihi/sama dengan threshold -> KIPAS ON
    digitalWrite(RELAY_PIN, LOW); // Active LOW: LOW = Relay Aktif
    lcd.setCursor(0, 1);
    lcd.print("Status: Kipas ON ");
  } else {
    // Jika suhu di bawah threshold -> KIPAS OFF
    digitalWrite(RELAY_PIN, HIGH); // Active LOW: HIGH = Relay Mati
    lcd.setCursor(0, 1);
    lcd.print("Status: Kipas OFF");
  }

  delay(2000); // Pembacaan ulang setiap 2 detik
}
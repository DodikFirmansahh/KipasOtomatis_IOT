**🌡️ Smart Automatic Fan Control System (Arduino Uno + DHT11)**



Proyek ini adalah sistem kontrol kipas angin otomatis berbasis suhu menggunakan \*\*Arduino Uno\*\* dan sensor \*\*DHT11\*\*. Sistem ini menggunakan modul \*\*Relay\*\* untuk mengendalikan kipas DC 12V dan menampilkan pembacaan suhu secara \*real-time\* melalui \*\*LCD 16x2 I2C\*\*.



\---



**Komponen yang Dibutuhkan**



| Komponen | Jumlah | Keterangan |

| :--- | :---: | :--- |

| \*\*Arduino Uno R3\*\* | 1 | Microcontroller utama |

| \*\*Sensor Suhu \& Kelembaban DHT11\*\* | 1 | Membaca kondisi lingkungan |

| \*\*Modul Relay 1-Channel (5V)\*\* | 1 | Sakelar elektronik untuk beban 12V |

| \*\*LCD 16x2 + Modul I2C Backpack\*\* | 1 | Menampilkan output teks \& suhu |

| \*\*Kipas DC 12V\*\* | 1 | Output actuator (pendingin) |

| \*\*Adaptor / Power Supply 12V DC\*\* | 1 | Sumber daya untuk Kipas DC |

| \*\*Breadboard \& Kabel Jumper\*\* | Secukupnya | Koneksi antarkomponen |



\---





**Skema Pengkabelan (Wiring Diagram)**



\* \*\*1. Sensor DHT11 (Suhu)\*\*

&#x20; \* \*\*VCC\*\* ➔ Pin \*\*5V\*\* Arduino

&#x20; \* \*\*GND\*\* ➔ Pin \*\*GND\*\* Arduino

&#x20; \* \*\*DATA\*\* ➔ Pin \*\*D2\*\* Arduino



\* \*\*2. LCD 16x2 (I2C Module)\*\*

&#x20; \* \*\*VCC\*\* ➔ Pin \*\*5V\*\* Arduino

&#x20; \* \*\*GND\*\* ➔ Pin \*\*GND\*\* Arduino

&#x20; \* \*\*SDA\*\* ➔ Pin \*\*A4\*\* Arduino

&#x20; \* \*\*SCL\*\* ➔ Pin \*\*A5\*\* Arduino



\* \*\*3. Modul Relay 1-Channel\*\*

&#x20; \* \*\*VCC\*\* ➔ Pin \*\*5V\*\* Arduino

&#x20; \* \*\*GND\*\* ➔ Pin \*\*GND\*\* Arduino

&#x20; \* \*\*IN / Control\*\* ➔ Pin \*\*D3\*\* Arduino







**4. Rangkaian Daya Kipas DC 12V**

&#x20; > ⚠️ \*\*Catatan:\*\* Jangan langsung menyambungkan Kipas 12V ke pin Arduino karena tegangan output Arduino hanya 5V dan dapat merusak board.



&#x20; \* \*\*Positif Adaptor 12V (+)\*\* ➔ Pin \*\*COM\*\* (Common) pada Relay

&#x20; \* \*\*Pin NO (Normally Open)\*\* pada Relay ➔ \*\*Kabel Merah (+)\*\* Kipas DC 12V

&#x20; \* \*\*Negatif Adaptor 12V (-)\*\* ➔ \*\*Kabel Hitam (-)\*\* Kipas DC 12V \*(Ground terhubung langsung)\*



\---







**Kode Program (Arduino C++)**



Pastikan kamu sudah menginstal library berikut melalui \*\*Library Manager\*\* di Arduino IDE sebelum melakukan upload:

1\. `DHT sensor library` oleh Adafruit

2\. `LiquidCrystal\_I2C` oleh Frank de Brabander



File kode utama terdapat di folder `src/main.ino`.



\---







**Penjelasan Logika Kode Program**



1\. \*\*Inisialisasi \& Setup (`setup()`):\*\*

&#x20;  \* Mengatur `RELAY\_PIN` sebagai output. Sebagian besar modul relay Arduino bersifat \*\*Active LOW\*\* (aktif saat diberi sinyal `LOW`), sehingga diset `HIGH` pada awal program agar kipas tidak langsung menyala saat baru dinyalakan.

&#x20;  \* Menyiapkan LCD I2C dan menyalakan \*backlight\*.

&#x20;  \* Menginisialisasi sensor DHT11.



2\. \*\*Pembacaan Suhu (`dht.readTemperature()`):\*\*

&#x20;  \* Sensor mengambil sampel suhu lingkungan dalam derajat Celsius setiap 2 detik sekali.



3\. \*\*Logika Ambang Batas / Operational Threshold (`if-else`):\*\*

&#x20;  \* Variabel `TEMP\_THRESHOLD` didefinisikan sebesar `30.0°C` (dapat disesuaikan kebutuhan).

&#x20;  \* \*\*`temp >= TEMP\_THRESHOLD`\*\*: Relay mendapatkan logika `LOW` ➔ Sakelar tertutup ➔ Arus 12V mengalir ke Kipas ➔ \*\*Kipas ON\*\*.

&#x20;  \* \*\*`temp < TEMP\_THRESHOLD`\*\*: Relay mendapatkan logika `HIGH` ➔ Sakelar terbuka ➔ Arus terputus ➔ \*\*Kipas OFF\*\*.



\---







**Cara Penggunaan**



1\. Rangkai seluruh komponen sesuai panduan skema pengkabelan di atas.

2\. Hubungkan Arduino ke PC/Laptop menggunakan kabel USB.

3\. Buka \*\*Arduino IDE\*\*, pilih modul \*\*Arduino Uno\*\* dan \*Port\* yang sesuai.

4\. \*Compile\* dan \*Upload\* file `src/main.ino`.

5\. Hubungkan adaptor 12V ke sumber listrik external untuk mencatu daya kipas DC.

6\. LCD akan menampilkan suhu sekitar secara \*real-time\*.

'@ | Set-Content -Path "README.md" -Encoding UTF8


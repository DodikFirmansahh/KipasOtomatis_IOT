**Kipas Otomatis IoT**



1\. Deskripsi Project

Kipas Otomatis IoT adalah project sederhana berbasis Arduino Uno yang digunakan untuk mengontrol kipas secara otomatis berdasarkan suhu lingkungan.

Sistem menggunakan sensor DHT11 untuk membaca suhu. Jika suhu mencapai atau melebihi 30°C, Arduino akan mengaktifkan relay sehingga kipas 12V menyala. Jika suhu berada di bawah 30°C, kipas akan dimatikan.



2\. Komponen yang Digunakan

Project ini menggunakan beberapa komponen utama:

Arduino Uno

Sensor DHT11

Relay

Fan 12V

Kabel jumper

Power supply



3\. Struktur Project

Struktur folder project:

KipasOtomatis\_IOT/

README.md

src/

KipasOtomatis\_IOT.ino

File `README.md` digunakan sebagai dokumentasi project.

Folder `src/` digunakan untuk menyimpan source code Arduino.

File `KipasOtomatis\_IOT.ino` merupakan program utama yang dijalankan pada Arduino Uno.



4\. Konsep Sistem

Konsep utama project ini adalah mengontrol kipas berdasarkan hasil pembacaan suhu dari sensor DHT11.

Arduino Uno berfungsi sebagai pengendali utama. Sensor DHT11 membaca suhu lingkungan kemudian mengirimkan data suhu ke Arduino.

Arduino kemudian membandingkan suhu yang terbaca dengan batas suhu yang telah ditentukan, yaitu 30°C.

Jika suhu mencapai atau lebih dari 30°C, Arduino memberikan perintah kepada relay untuk mengaktifkan kipas.

Jika suhu kurang dari 30°C, Arduino memberikan perintah kepada relay untuk mematikan kipas.



5\. Cara Kerja

Cara kerja sistem adalah sebagai berikut:

* Arduino Uno mulai menjalankan program.
* Sensor DHT11 membaca suhu lingkungan.
* Data suhu dikirimkan ke Arduino Uno.
* Arduino memeriksa nilai suhu.
* Jika suhu >= 30°C, relay diaktifkan.
* Relay mengaktifkan fan 12V.
* Jika suhu < 30°C, relay dimatikan.
* Fan 12V berhenti berputar.
* Proses pembacaan suhu dilakukan secara berulang.





6\. Logika Program

Logika utama sistem dapat digambarkan sebagai berikut:

Jika:

Suhu >= 30°C
→ Relay ON
→ Fan ON

Jika:

Suhu < 30°C
→ Relay OFF
→ Fan OFF

7\. Peran Setiap Komponen

* Arduino Uno

Arduino Uno digunakan sebagai mikrokontroler utama untuk membaca data dari sensor DHT11 dan mengontrol relay.

* DHT11

DHT11 digunakan untuk membaca suhu lingkungan.

* Relay

Relay digunakan sebagai saklar elektronik untuk mengontrol fan 12V berdasarkan perintah dari Arduino.

* Fan 12V

Fan 12V digunakan sebagai perangkat yang dikontrol secara otomatis oleh sistem.



8\. Tujuan Project

Project ini dibuat untuk mempelajari:

* Pemrograman Arduino
* Penggunaan sensor DHT11
* Penggunaan relay
* Pembacaan data sensor
* Pengendalian perangkat berdasarkan kondisi suhu
* Dasar sistem otomasi dan IoT





9\. Teknologi

Teknologi yang digunakan:

* Arduino Uno
* Arduino IDE
* Sensor DHT11
* Relay Module
* Fan 12V
* C/C++ Arduino



10\. Author

Dodik Firmansah


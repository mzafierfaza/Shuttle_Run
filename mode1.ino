
void mode1(String gender) {
  while (1) {
    bacaTombol();
    dataStream = 0;
    if (gender == "putra") {
      lcd.setCursor(0, 0); lcd.print("Ready");
      lcd.setCursor(5, 0); lcd.print(" | ");
      lcd.setCursor(8, 0); lcd.print("MODE_1-Putra");
      lcd.setCursor(0, 1); lcd.print("--------------------");
      lcd.setCursor(1, 2); lcd.print("Harap tekan tombol");
      lcd.setCursor(3, 3); lcd.print("Untuk memulai");
    }
    else if (gender == "putri") {
      lcd.setCursor(0, 0); lcd.print("Ready");
      lcd.setCursor(5, 0); lcd.print(" | ");
      lcd.setCursor(8, 0); lcd.print("MODE_1-Putri");
      lcd.setCursor(0, 1); lcd.print("--------------------");
      lcd.setCursor(1, 2); lcd.print("Harap tekan tombol");
      lcd.setCursor(3, 3); lcd.print("Untuk memulai");
    }
    digitalWrite(buzzer, LOW);       // buzzer LOW
    lastMillis1 = millis();
    if (!btn && !hitung_ms1) {
      digitalWrite(buzzer, HIGH);       // buzzer tiittttttt
      lcd.clear();
      hitung_ms1 = true;
    }
    while (hitung_ms1 == true) {    // ============== LAP 1 =================
      do {
        previousMillis1 = millis();
        sonic1();
        //        Serial.print("lastMls1 = "); Serial.print(lastMillis1); Serial.print(" | ");
        //        Serial.print("prvsMls1 = "); Serial.print(previousMillis1); Serial.print(" | ");
        //        Serial.print("1 = "); Serial.print(distance1); Serial.println(" | ");
        if (previousMillis1 - lastMillis1 >= waktuBuzzer) {
          digitalWrite(buzzer, LOW);    // buzzer LOW
        }
      } while (distance1 > jarakTrigger);
      hitung_lap1 = true;
      if (hitung_lap1 == true) {
        digitalWrite(buzzer, HIGH);       // buzzer tiittttttt
        waktu_1 = (previousMillis1 - lastMillis1); // ini kan masih milidetik
        waktu_1 = waktu_1 / 1000;   // dakjadi pake kecepatan , jadinyo ambek waktu nyo bae

        //        kecepatan1 = jarak1 / waktu_1; // satuannya mm/ms.
        //        Serial.print("Kec 1 = "); Serial.print(kecepatan1, 3); Serial.println(" | ");
        hitung_ms2 = true;
        hitung_ms1 = false;
      }
      break;
    }
    lastMillis2 = millis();
    while (hitung_ms2 == true) {     // ============== LAP 2 =================
      do {
        previousMillis2 = millis();
        sonic2();
        //        Serial.print("lastMls2 = "); Serial.print(lastMillis2); Serial.print(" | ");
        //        Serial.print("prvsMls2 = "); Serial.print(previousMillis2); Serial.print(" | ");
        //        Serial.print("2 = "); Serial.print(distance2); Serial.println(" | ");
        if (previousMillis2 - lastMillis2 >= waktuBuzzer) {
          digitalWrite(buzzer, LOW);    // buzzer LOW
        }
      } while (distance2 > jarakTrigger);
      hitung_lap2 = true;
      if (hitung_lap2 == true) {
        digitalWrite(buzzer, HIGH);       // buzzer tiittttttt
        waktu_2 = (previousMillis2 - lastMillis2); // ini kan masih milidetik
        waktu_2 = waktu_2 / 1000;   // dakjadi pake kecepatan , jadinyo ambek waktu nyo bae

        //        kecepatan2 = jarak2 / waktu_2; // satuannya mm/ms.
        //        Serial.print("Kec 1 = "); Serial.print(kecepatan1, 3); Serial.print(" | ");
        //        Serial.print("Kec 2 = "); Serial.print(kecepatan2, 3); Serial.println(" | ");
        hitung_ms3 = true;
        hitung_ms2 = false;
      }
      break;
    }
    lastMillis3 = millis();
    while (hitung_ms3 == true) {     // ============== LAP 3 =================
      do {
        previousMillis3 = millis();
        sonic3();
        //        Serial.print("lastMls3 = "); Serial.print(lastMillis3); Serial.print(" | ");
        //        Serial.print("prvsMls3 = "); Serial.print(previousMillis3); Serial.print(" | ");
        //        Serial.print("1 = "); Serial.print(distance1); Serial.println(" | ");
        if (previousMillis3 - lastMillis3 >= waktuBuzzer) {
          digitalWrite(buzzer, LOW);    // buzzer LOW
        }
      } while (distance3 > jarakTrigger);
      hitung_lap3 = true;
      if (hitung_lap3 == true) {
        digitalWrite(buzzer, HIGH);       // buzzer tiittttttt
        waktu_3 = (previousMillis3 - lastMillis3); // ini kan masih milidetik
        waktu_3 = waktu_3 / 1000;   // dakjadi pake kecepatan , jadinyo ambek waktu nyo bae
        hitung_ms3 = false;
        hasil = true;
      }
      break;
    }
    while (hasil == true) {
      bacaTombol();
      total = (waktu_1 + waktu_2 + waktu_3);
      if (gender == "putra") {
        cekNilai(total, "male");
      }
      else if (gender == "putri") {
        cekNilai(total, "female");
      }
      // ---------------- EXCEL --------------------
      for (dataStream; dataStream < 1; dataStream++) {
        digitalWrite(buzzer, HIGH);    // buzzer tiittttt
        delay(1000);
        digitalWrite(buzzer, LOW);       // buzzer LOW
        lcd.setCursor(0, 0); lcd.print("1: ");
        lcd.setCursor(3, 0); lcd.print(waktu_1);
        lcd.setCursor(9, 0); lcd.print("|");
        lcd.setCursor(11, 0); lcd.print("3: ");
        lcd.setCursor(14, 0); lcd.print(waktu_3); // kecepatan3
        lcd.setCursor(0, 1); lcd.print("2: ");
        lcd.setCursor(3, 1); lcd.print(waktu_2);
        lcd.setCursor(9, 1); lcd.print("|");
        lcd.setCursor(11, 1); lcd.print("T: ");
        lcd.setCursor(14, 1); lcd.print(total); // rata2
        lcd.setCursor(0, 2); lcd.print("--------------------");
        lcd.setCursor(0, 3); lcd.print("Rate: ");
        lcd.setCursor(5, 3); lcd.print(nilai);
        Serial.print("DATA,");
        Serial.print("1,");   // MODE
        Serial.print(waktu_1);   // Lap 1
        Serial.print(" s,");
        Serial.print(waktu_2);   // Lap 2
        Serial.print(" s,");
        Serial.print(waktu_3);   // Lap 3
        Serial.print(" s,");
        Serial.print(total);    // Total
        Serial.print(" s,");
        Serial.print(nilai);    // String Nilai
        Serial.print(",");
        Serial.println(gender);    // String gender
      }
      if (!mode) {  // tombol reset maka dia reset
        lcd.clear();
        delay(200);
        hasil = false;
        break;
      }
    }
    break;
  }
}

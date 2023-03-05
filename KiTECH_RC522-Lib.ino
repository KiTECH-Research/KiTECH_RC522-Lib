#include "KiTECH_RC522.h"

KiTECH_RC522 reader;

void setup() {
    Serial.begin(9600);
    reader.setup();
}

void loop() {
    if (!reader.isNewCardPresent()) {
        return;
    }

    if (!reader.readCardSerial()) {
        return;
    }

    Serial.println(reader.readCurrentCard());
    delay(2000);
}

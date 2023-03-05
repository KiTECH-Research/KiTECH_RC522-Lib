#include "Arduino.h"
#include <SPI.h>
#include <MFRC522.h>
#include "KiTECH_RC522.h"

KiTECH_RC522::KiTECH_RC522() {}

MFRC522 mfrc522(21, 22);

bool KiTECH_RC522::setup() {
    SPI.begin();
    mfrc522.PCD_Init();
    return true;
}

bool KiTECH_RC522::isNewCardPresent() {
    return mfrc522.PICC_IsNewCardPresent();
}

bool KiTECH_RC522::readCardSerial() {
    return mfrc522.PICC_ReadCardSerial();
}

String KiTECH_RC522::readCurrentCard() {
    String content = "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }

    return content;
}
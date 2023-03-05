#ifndef KiTECH_RC522_h
#define KiTECH_RC522_h

#include "Arduino.h"

class KiTECH_RC522
{
private:
public:
    KiTECH_RC522();
    KiTECH_RC522(int rstPin, int ssPin);

    bool setup();
    bool isNewCardPresent();
    bool readCardSerial();
    String readCurrentCard();

};

#endif
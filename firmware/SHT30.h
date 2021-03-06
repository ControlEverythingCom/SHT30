#include "spark_wiring_i2c.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_constants.h"
#include "spark_wiring.h"

class SHT30{
public:
    bool setAddress(int a0);
    bool update();
    double temperature;
    double humidity;
    
private:
    int address = 0x44;
    unsigned int buffer[6] = {0,0,0,0,0,0};
};

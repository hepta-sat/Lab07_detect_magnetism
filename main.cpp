#include "mbed.h"
#include "HEPTA_EPS.h"
#include "Hepta9axis.h"

RawSerial pc(USBTX,USBRX,9600);
HEPTA_EPS eps(PA_0,PA_4);
DigitalOut condition(PB_1);
Hepta9axis sensor(PB_7,PB_6,0x19,0x69,0x13);
int main()
{
    float mx,my,mz;
    pc.printf("Magnetometer Mode\r\n");
    for(int i = 0; i<50; i++) {
        sensor.sen_mag(&mx,&my,&mz);
        pc.printf("mag : %f,%f,%f\r\n",mx,my,mz);
        wait(1.0);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "thermo.h"

// convert temperature sensor value to a struct
int set_temp_from_ports(temp_t *temp){
    // THERMO_SENSER_PORT above maximum trusted value
    if(THERMO_SENSOR_PORT > 64000) return 1;

    // check lowest bit of THERMO_STATUS_PORT
    int temp_bit = THERMO_STATUS_PORT & 1;
    if(temp_bit == 1){  // first bit is 1, deg F
        temp->is_fahrenheit = 1;
    } else {  // first bit is 0, deg C
        temp->is_fahrenheit = 0;
    }

    // update structure
    int degree = THERMO_SENSOR_PORT/64;
    if(THERMO_SENSOR_PORT % 64 > 31){  // rounding mechanism
        degree += 1;
    }

    // fill in temp structure
    if(temp->is_fahrenheit == 0){  // is deg C
        temp->tenths_degrees = -500 + degree;
    } else {  // is deg F
        int deg_c = -500 + degree;
        temp->tenths_degrees = (deg_c * 90) / 50 + 320;  // convert deg C to deg F
    }
    return 0;
}

int set_display_from_temp(temp_t temp, int *display){
    // if temp has wrong value, do nothing
    if(temp.is_fahrenheit == 0){  // is deg C
        if(temp.tenths_degrees < -500 || temp.tenths_degrees > 500) return 1;
    } else if(temp.is_fahrenheit == 1){  // is deg F
        if(temp.tenths_degrees < -580 || temp.tenths_degrees > 1220) return 1;
    } else if(temp.is_fahrenheit!=0 && temp.is_fahrenheit!=1){  // number for judging deg unit is incorrect
        return 1;
    }

    int degrees = temp.tenths_degrees;
    // convert degrees to positive to make the process easier
    if(degrees < 0) degrees *= -1;

    // digit mask array
    int masks[10] = {
        0b1111110, // 0
        0b0001100, // 1
        0b0110111, // 2
        0b0011111, // 3
        0b1001101, // 4
        0b1011011, // 5
        0b1111011, // 6
        0b0001110, // 7
        0b1111111, // 8
        0b1011111  // 9
    };
    // bit masks for special characters
    int negative_mask = 0b0000001;
    int blank_mask = 0b0000000;
    int deg_c_mask = 0b01;
    int deg_f_mask = 0b10;

    // extract digits from each position
    int temp_thousands = degrees / 1000;
    int temp_hundres = (degrees - temp_thousands*1000) / 100;
    int temp_tens = (degrees - temp_thousands*1000 - temp_hundres*100) / 10;
    int temp_ones = degrees - temp_thousands*1000 - temp_hundres*100 - temp_tens*10;

    int result_bit = 0;  // bits to be manipulated with
    result_bit ^= masks[temp_tens];  // combine temp_tens

    // display ones
    int ones_bit = 0;
    ones_bit ^= masks[temp_ones];
    // combine with temp_ones mask
    result_bit = (result_bit << 7) | ones_bit;
    // display hundres
    int hundres_bit = 0;
    if(temp_hundres == 0){  // if the degree contains only 2 digit
        if(temp.tenths_degrees < 0){  // for negative degrees, '-' will take the position
            hundres_bit ^= negative_mask;
        } hundres_bit ^= blank_mask;
    } else {hundres_bit ^= masks[temp_hundres];}
    // combine with temp_hundres mask
    result_bit = (hundres_bit << 14) | result_bit;
    // display tens
    int tens_bit = 0;
    tens_bit ^= masks[temp_tens];
    // combine with temp_tens mask
    result_bit = (tens_bit << 7) | result_bit;

    // negative sign bits
    if(temp.tenths_degrees < 0 && temp_hundres!=0){
        result_bit = (negative_mask << 21) | result_bit;
    } else if(temp_thousands!=0){  // if the degree has 4 digits
        int thousands_bit = 0;
        thousands_bit ^= masks[temp_thousands];
        result_bit = (thousands_bit << 21) | result_bit;
    }

    // degree unit's bits
    if(temp.is_fahrenheit == 0){  // is deg C
        result_bit = (deg_c_mask << 28) | result_bit;
    } else {result_bit = (deg_f_mask << 28) | result_bit;}
    
    // set display's value
    *display = result_bit;
    return 0;
}

int thermo_update(){ 
    temp_t temp = {(short)THERMO_SENSOR_PORT};
    set_temp_from_ports(&temp);

    // check to see if set_temp_from_ports() have errors
    if (set_temp_from_ports(&temp)==1) return 1;

    // check to see if set_display_from_temp() have errors
    int display = 0;
    set_display_from_temp(temp, &display);
    if (set_display_from_temp(temp, &display)==1) return 1;

    // update THERMO_DISPLAY_PORT
    THERMO_DISPLAY_PORT = display;
    return 0;
}

#include <reg51.h>

sbit adc_ctrl = P3^7;
sbit eoc = P3^6;
sbit redLED = P0^0;
sbit yellowLED = P0^1;

sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

unsigned char value;
unsigned int timeout;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 120; j++);
}

void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    delay_ms(2);
    en = 0;
    delay_ms(2);
}

void lcd_data(unsigned char dat) {
    P2 = dat;
    rs = 1;
    rw = 0;
    en = 1;
    delay_ms(2);
    en = 0;
    delay_ms(2);
}

void lcd_init(void) {
    delay_ms(20);
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x80);
}

void lcd_string(unsigned char *str) {
    while(*str) {
        lcd_data(*str);
        str++;
    }
}

void lcd_print_number(unsigned char num) {
    unsigned char buffer[4];
    unsigned char i = 0;

    if(num == 0) {
        lcd_data('0');
        return;
    }

    while(num > 0) {
        buffer[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }

    while(i > 0) {
        i--;
        lcd_data(buffer[i]);
    }
}

void main() {
    P1 = 0xFF;
    lcd_init();

    while(1) {
        adc_ctrl = 0;
        delay_ms(1);
        adc_ctrl = 1;
        delay_ms(1);
        adc_ctrl = 0;

        timeout = 0;
        while(eoc == 0 && timeout < 5000) {
            timeout++;
        }

        delay_ms(2);

        value = P1;

        lcd_cmd(0x80);
        lcd_string("Dist:");
        lcd_print_number(value);
        lcd_string("    ");

        if(value < 80) {
            redLED = 0;
            yellowLED = 1;
        }
        else if(value < 160) {
            redLED = 1;
            yellowLED = 0;
        }
        else {
            redLED = 1;
            yellowLED = 1;
        }

        delay_ms(60);
    }
}

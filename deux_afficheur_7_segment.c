const unsigned char digits[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void main() {
    unsigned char left_digit = 0;
    unsigned char right_digit = 0;
    unsigned int count = 0;

    TRISB = 0b10000000;
    TRISC = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;

    while (1) {
        left_digit = count / 10;
        right_digit = count % 10;

        PORTB = digits[left_digit];
        PORTC = digits[right_digit];

        Delay_ms(500);

        count++;
        if (count > 99) {
            count = 0;
        }
    }
}
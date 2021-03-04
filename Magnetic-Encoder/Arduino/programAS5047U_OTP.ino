#include <SPI.h>

// OTP non-volatile programming
// 1. Power on cycle
// 2. Write the SETTINGS1 and SETTINGS2 and SETTINGS3 registers with the Custom settings for this application
// 3. Place the magnet at the desired zero position
// 4. Read out the measured angle from the ANGLECOM register
// 5. Write ANGLECOM [5:0] into the ZPOSL register and ANGLECOM[13:6] into the ZPOSM register
// 6. Read reg(0x0016) to reg(0x001A)
// 7. Set ECC_en in Register ECC to 1 (ECC protection enabled)
// 8. Read ECC_s (0x3FD0) to get the correct ECC key
// 9. Write ECC_s key into ECC register
// 10. Read reg(0x0016) to reg(0x001B) → read register step1
// 11. Comparison of written content (settings and angle) with content of read register step1
// 12. If point 11 is correct, enable OTP read / write by setting PROGEN = 1 in the PROG register
// 13. Start the OTP burn procedure by setting PROGOTP = 1 in the PROG register
// 14. Read the PROG register until it reads 0x0001 (Programming procedure complete)
// 15. Clear the memory content by writing 0x00 in the whole non-volatile memory
// 16. Set the PROGVER = 1 to set the Guard band for the guard band test.1
// 17. Refresh the non-volatile memory content with the OTP content by setting OTPREF = 1
// 18. Read reg(0x0016) to reg(0x001B) → read register step2
// 19. Comparison of written content (settings and angle) with content of read register step2. 
//     If a deviation in the comparison occurs, the guard band test was not successful. 
//     Reprogramming is not allowed! Mandatory: guard band test
// 20. New power on cycle.
// 21. Read reg(0x0016) to Reg(0x001B) → read register step3
// 22. Comparison of written content (settings and angle) with content of read register step3. 
//     If a deviation in the comparison occurs, the power on test was not successful. 
//     Reprogramming is not allowed!
// 23. If point 18 is correct, the programming was successful.

#define CS_PIN 42

uint8_t crc8(unsigned char *data ,int length) {
    uint32_t crc = 0xC4;
    for (uint8_t i=0;i<length;i++) {
        crc ^= data[i];
        for (uint8_t bit=0;bit<8;bit++) {
            if ( (crc & 0x80)!=0 ) {
                crc <<= 1;
                crc ^= 0x1D;
            }
            else {
                crc <<= 1;
            }
        }
    }
    return (~crc)&0xFF;
}

uint32_t readRegister(uint16_t address) {
  uint8_t msg[3];
  msg[0] = ((address >> 8) & 0x3F) | 0x40; // Upper part of address and read flag
  msg[1] = (address & 0x00FF); // Lower part of address
  msg[2] = crc8(msg,2);
  // First 24bit transaction
  delayMicroseconds(10);
  digitalWrite(CS_PIN, LOW); // CS high
  SPI.transfer(msg[0]);
  SPI.transfer(msg[1]); 
  SPI.transfer(msg[2]); 
  digitalWrite(CS_PIN, HIGH); // CS high
  // Second 24bit transaction
  delayMicroseconds(10);
  digitalWrite(CS_PIN, LOW); // CS high
  union { uint32_t out; uint8_t in[4]; } answer;
  answer.in[3] = 0;
  answer.in[2] = SPI.transfer(msg[0]);
  answer.in[1] = SPI.transfer(msg[1]);
  answer.in[0] = SPI.transfer(msg[2]); 
  digitalWrite(CS_PIN, HIGH); // CS high
  return answer.out;
}

uint16_t readRegister16(uint16_t address) {
  uint8_t msg[3];
  msg[0] = ((address >> 8) & 0x3F) | 0x40; // Upper part of address and read flag
  msg[1] = (address & 0x00FF); // Lower part of address
  msg[2] = crc8(msg,2);
  // First 24bit transaction
  delayMicroseconds(10);
  digitalWrite(CS_PIN, LOW); // CS high
  SPI.transfer(msg[0]);
  SPI.transfer(msg[1]); 
  SPI.transfer(msg[2]); 
  digitalWrite(CS_PIN, HIGH); // CS high
  // Second 24bit transaction
  delayMicroseconds(10);
  digitalWrite(CS_PIN, LOW); // CS high
  union { uint16_t out; uint8_t in[2]; } answer;

  // EDIT: I switched the 0 in  answer.in[0] to a 1 and the same of the other
  answer.in[1] = SPI.transfer(msg[0]);
  answer.in[0] = SPI.transfer(msg[1]);
  SPI.transfer(msg[2]); 
  digitalWrite(CS_PIN, HIGH); // CS high
  return answer.out & 0x3F;
}

void writeRegister(uint16_t address, uint16_t data) {
  uint8_t msg[3];
  msg[0] = ((address >> 8) & 0x3F); // Upper part of address and write flag
  msg[1] = (address & 0x00FF); // Lower part of address
  msg[2] = crc8(msg,2);
  // First 16bit transaction
  delayMicroseconds(10);
  digitalWrite(CS_PIN, LOW); // CS high
  SPI.transfer(msg[0]);
  SPI.transfer(msg[1]); 
  SPI.transfer(msg[2]); 
  digitalWrite(CS_PIN, HIGH); // CS high
  // Second 16bit transaction
  msg[0] = ((data >> 8) & 0x00FF); // Upper part of address
  msg[1] = (data & 0x00FF); // Lower part of address
  msg[2] = crc8(msg,2);
  delayMicroseconds(10);
  digitalWrite(CS_PIN, LOW); // CS high
  SPI.transfer(msg[0]);
  SPI.transfer(msg[1]); 
  SPI.transfer(msg[2]); 
  digitalWrite(CS_PIN, HIGH); // CS high
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Configure SPI
  pinMode(CS_PIN, OUTPUT); // SS
  digitalWrite(8, HIGH); // CS high
  pinMode(7, OUTPUT); // MOSI
  // MISO D6
  pinMode(5, OUTPUT); // SCK
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
}

void loop() {
  Serial.println("Reading error register");
  Serial.print("0x0001 "); Serial.println(readRegister(0x0001), HEX);
  
    // ==> OTP sequence
  Serial.println("Writing volatile register content");
  // Write registers content once
  // DISABLE 0x0015
  // FILTER_disable na ABI_off UVW_off 
  // 0              0  0       1
  writeRegister(0x0015,0x0001);
  // ZPOSM & ZPOSL
  uint16_t zeroPos = 0; // 14bit
  writeRegister(0x0016, (zeroPos >> 6) & 0x00FF );
  writeRegister(0x0017, (zeroPos << 2) & 0x00FC );
  // SETTINGS1, default 0x0000, leave as is
  writeRegister(0x0018, 0x0000 );
  // SETTINGS2
  // PWMon Data_select ABI_DEC DAECDIS UVW_ABI DIR NOISESET IWIDTH   
  // 0     0           0       0       0       0   1        1
  writeRegister(0x0019, 0b00000011 );
  // SETTINGS3
  // UVWPP HYS ABIRES
  // ABIRES HYS UVWPP
  // 000   00  000
  // 101   00  000
  writeRegister(0x001A, 0b10000000 );
  // Readback
  Serial.println("Reading volatile register content");
  Serial.print("0x0015 "); Serial.println(readRegister(0x0015), HEX);
  Serial.print("0x0016 "); Serial.println(readRegister(0x0016), HEX);
  Serial.print("0x0017 "); Serial.println(readRegister(0x0017), HEX);
  Serial.print("0x0018 "); Serial.println(readRegister(0x0018), HEX);
  Serial.print("0x0019 "); Serial.println(readRegister(0x0019), HEX);
  Serial.print("0x001A "); Serial.println(readRegister(0x001A), HEX);
  // ECC
  Serial.println("Generate ECC");
  writeRegister(0x001B, 0x0080 );
  uint16_t ecc = readRegister16(0x3FD0);
  Serial.print("0x3FD0 "); Serial.println(ecc, HEX);
  writeRegister(0x001B, ecc | 0x0080);
  readRegister(0x0001); // Read the error, which was caused by the checksum change
  // Readback
  Serial.println("Reading volatile register content + ecc");
  Serial.print("0x0015 "); Serial.println(readRegister(0x0015), HEX);
  Serial.print("0x0016 "); Serial.println(readRegister(0x0016), HEX);
  Serial.print("0x0017 "); Serial.println(readRegister(0x0017), HEX);
  Serial.print("0x0018 "); Serial.println(readRegister(0x0018), HEX);
  Serial.print("0x0019 "); Serial.println(readRegister(0x0019), BIN);
  Serial.print("0x001A "); Serial.println(readRegister(0x001A), BIN);
  Serial.print("0x001B "); Serial.println(readRegister(0x001B), HEX);
  // Danger
  // ===========================================================================================
  while(1);
  // ===========================================================================================  
  Serial.println("Writing OTP");
  // Unlock OTP area
  writeRegister(0x0003, 0x0001 );
  // Start OTP burning
  writeRegister(0x0003, 0x0008 );
  // Read OTP_CTRL
  uint16_t reg3 = 0;
  while (reg3 != 0x0001) {
    reg3 = readRegister16(0x0003);
  }
  // Clear memory
  writeRegister(0x0015, 0x0000);
  writeRegister(0x0016, 0x0000);
  writeRegister(0x0017, 0x0000);
  writeRegister(0x0018, 0x0000);
  writeRegister(0x0019, 0x0000);
  writeRegister(0x001A, 0x0000);
  writeRegister(0x001B, 0x0000);
  // Set Guardband
  writeRegister(0x0003, 0x0040);
  // Refresh memory with OTP content
  writeRegister(0x0003, 0x0004);
  // Readback
  Serial.println("Reading non-volatile register content");
  Serial.print("0x0015 "); Serial.println(readRegister(0x0015), HEX);
  Serial.print("0x0016 "); Serial.println(readRegister(0x0016), HEX);
  Serial.print("0x0017 "); Serial.println(readRegister(0x0017), HEX);
  Serial.print("0x0018 "); Serial.println(readRegister(0x0018), HEX);
  Serial.print("0x0019 "); Serial.println(readRegister(0x0019), HEX);
  Serial.print("0x001A "); Serial.println(readRegister(0x001A), HEX);
  Serial.print("0x001B "); Serial.println(readRegister(0x001B), HEX);
  Serial.println("If those registers do not fit the chip is bricked...");
  while(1);
}

### Motorware modifications

The firmware of the uDrivers has to be modified:

* In the file "user_j1.h", "user_j5.h", "user_mtr_on_j1.h", "user_mtr_on_j5.h" #define USER_MOTOR_ENCODER_LINES changed to ().

| in file | output in SPI |
|-------------|-------------|
|133.7|852143|
|1024.0|65735|
|32768.0|28|
|65536.0|7|
|131072.0|3|
|262144.0|1|

---


## uDrivers Firmware

* All instructions were followed as described by the original instructions.

+ As the AS5047 can only output 4096 ticks per revolution via ABI at max, the configuration for the Motor in the uDriver firmware had to be altered.

* udriver_firmware-master\firmware\user_config_f28069m_drv8305
    * user_j1
    * user_j5
    * user_mtr_on_j1
    * user_mtr_on_j5
    
 In all instances, under "USER_MOTOR == TMotor_Antigravity_4004_300kv"

 the define USER_MOTOR_ENCODER_LINES (or USER_MOTOR_ENCODER_LINES_2) was changed from 5000.0 to 4096.0.
#include <Arduino.h>

// 舵机计时器通道 
int channel_PWM = 3;  
// 舵机频率，那么周期也就是1/50，也就是20ms ，PWM一共有16个通道，0-7位高速通道由80Mhz时钟驱动，后面8个为低速通道由1Mhz时钟驱动
int freq_PWM = 50;   
// PWM分辨率，取值为 0-20 之间  ，这里填写为10，那么后面的ledcWrite 这个里面填写的pwm值就在 0 - 2的10次方 之间 也就是 0-1024 
int resolution_PWM = 10;
// 绑定的IO，在下面的绑定函数里面会用到，绑定之后这个IO就会变成我们PWM的输出口
const int PWM_Pin = 4; 

void setup() {      //123
  Serial.begin(115200);
  ledcSetup(channel_PWM, freq_PWM, resolution_PWM); // 设置舵机通道
  ledcAttachPin(PWM_Pin, channel_PWM);  //将 LEDC 通道绑定到指定 IO 口上以实现输出
}


void loop() {
  ledcWrite(channel_PWM, 102);  //20ms高电平时间2/20*1024 => 102，此时360度舵机正传135
  delay(1000);
  ledcWrite(channel_PWM, 25);  //20ms高电平时间0.5/20*1024 => 0.5，此时360度舵机几乎停转
  delay(1000);
  ledcWrite(channel_PWM, 921);  //20ms高电平时间18/20*1024 => 921，此时360度舵机反转135
  delay(1000);
  //ledcDetachPin(PWM_Pin);  //这个是解除IO口的pwm输出功能模式
}

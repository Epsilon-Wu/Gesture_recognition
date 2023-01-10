#ifndef  __kalman_H_
#define  __kalman_H_

#include <sys.h>


//extern  float x_last=0;    // 表示上一次的最优值
//extern  float p_last=0.02; // 表示上一次的 最优协方差
//extern  float Q=0.018;     // Q （偏差）为高斯白噪声 不随时间变化
//extern  float R=0.542;     // R  (偏差) 为高斯白噪声 不随时间变化
//extern  float kg;          // kg 为 kalman filter 用于计算 最优值
//extern  float x_mid;       // 当前的预测值  
//extern  float x_now;       // 当前的最优值
//extern  float p_mid;       // 当前的协方差
//extern  float p_now;       // 当前的 最优 协方差 
//extern  float sumerror_kalman=0;  // 卡尔曼估计值的 累计 误差 
//extern  float sumerror_measure=0; // 真值 和 估计值的 累计误差


//    卡尔曼滤波函数 （只适用于近似线性变化的量）
//     参数 ： 需要进行滤波的变量 

float kalman_filter(int kalman_val);

#endif 

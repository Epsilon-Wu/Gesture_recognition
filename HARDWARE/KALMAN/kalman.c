#include <kalman.h>
#include <math.h>
#include <stm32f10x.h>

float x_last=0;    // 表示上一次的最优值
float p_last=0.02; // 表示上一次的 最优协方差
float Q=0.018;     // Q （偏差）为高斯白噪声 不随时间变化
float R=0.542;     // R  (偏差) 为高斯白噪声 不随时间变化
float kg;          // kg 为 kalman filter 用于计算 最优值
float x_mid;       // 当前的预测值  
float x_now;       // 当前的最优值
float p_mid;       // 当前的协方差
float p_now;       // 当前的 最优 协方差 
float sumerror_kalman=0;  // 估计值的 累计 误差 
float sumerror_measure=0; // 测量值的 累计误差

float kalman_filter(int kalman_val)
{
	x_mid=x_last;  
	p_mid=p_last+Q;
	kg=p_mid/(p_mid+R);
	x_now=x_mid+kg*(kalman_val-x_mid);
	p_now=(1-kg)*p_mid;
	
	sumerror_kalman = sumerror_kalman + fabs(x_mid - x_now);
	sumerror_measure = sumerror_measure + fabs(kalman_val - x_now);
	
	p_last = p_now;  //更新covariance值
	x_last = x_now;  //更新系统状态值
	
	return p_now;
}

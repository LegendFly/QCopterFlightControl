/*==============================================================================================*/
/*==============================================================================================*/
#include "stm32f4_system.h"
#include "stm32f4_i2c.h"
#include "module_hmc5883.h"
/*==============================================================================================*/
/*==============================================================================================*
**函數 : HMC5883_Init
**功能 : 初始化HMC5883
**輸入 : None
**輸出 : None
**使用 : HMC5883_Init()
**==============================================================================================*/
/*==============================================================================================*/
void HMC5883_Init( void )
{
	u8 HMC5883_Init_Data[3] = {
			0x70, /* HMC5883_REG_CONF_A */
			0xA0, /* HMC5883_REG_CONF_B */
			0x00  /* HMC5883_REG_MODE */
		};
	I2C_DMA_WriteReg(HMC5883_I2C_ADDR, HMC5883_REG_CONF_A, HMC5883_Init_Data,   1); Delay_1ms(10);
	I2C_DMA_WriteReg(HMC5883_I2C_ADDR, HMC5883_REG_CONF_B, HMC5883_Init_Data+1, 1); Delay_1ms(10);
	I2C_DMA_WriteReg(HMC5883_I2C_ADDR, HMC5883_REG_MODE,   HMC5883_Init_Data+2, 1); Delay_1ms(10);
}
/*==============================================================================================*/
/*==============================================================================================*/

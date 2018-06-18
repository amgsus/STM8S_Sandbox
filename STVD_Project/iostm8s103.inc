SFR(PA_ODR,       0x5000); // Data Output Latch reg
SFR(PA_IDR,       0x5001); // Input Pin Value reg
SFR(PA_DDR,       0x5002); // Data Direction
SFR(PA_CR1,       0x5003); // Control register 1
SFR(PA_CR2,       0x5004); // Control register 2
SFR(PB_ODR,       0x5005); // Data Output Latch reg
SFR(PB_IDR,       0x5006); // Input Pin Value reg
SFR(PB_DDR,       0x5007); // Data Direction
SFR(PB_CR1,       0x5008); // Control register 1
SFR(PB_CR2,       0x5009); // Control register 2
SFR(PC_ODR,       0x500A); // Data Output Latch reg
SFR(PC_IDR,       0x500B); // Input Pin Value reg
SFR(PC_DDR,       0x500C); // Data Direction
SFR(PC_CR1,       0x500D); // Control register 1
SFR(PC_CR2,       0x500E); // Control register 2
SFR(PD_ODR,       0x500F); // Data Output Latch reg
SFR(PD_IDR,       0x5010); // Input Pin Value reg
SFR(PD_DDR,       0x5011); // Data Direction
SFR(PD_CR1,       0x5012); // Control register 1
SFR(PD_CR2,       0x5013); // Control register 2
SFR(PE_ODR,       0x5014); // Data Output Latch reg
SFR(PE_IDR,       0x5015); // Input Pin Value reg
SFR(PE_DDR,       0x5016); // Data Direction
SFR(PE_CR1,       0x5017); // Control register 1
SFR(PE_CR2,       0x5018); // Control register 2
SFR(PF_ODR,       0x5019); // Data Output Latch reg
SFR(PF_IDR,       0x501A); // Input Pin Value reg
SFR(PF_DDR,       0x501B); // Data Direction
SFR(PF_CR1,       0x501C); // Control register 1
SFR(PF_CR2,       0x501D); // Control register 2
SFR(FLASH_CR1,    0x505A); // Flash Control Register 1
SFR(FLASH_CR2,    0x505B); // Flash Control Register 2
SFR(FLASH_NCR2,   0x505C); // Flash Complementary Control Reg 2
SFR(FLASH_FPR,    0x505D); // Flash Protection reg
SFR(FLASH_NFPR,   0x505E); // Flash Complementary Protection reg
SFR(FLASH_IAPSR,  0x505F); // Flash in-appl Prog. Status reg
SFR(FLASH_PUKR,   0x5062); // Flash Program memory unprotection reg
SFR(FLASH_DUKR,   0x5064); // Data EEPROM unprotection reg
SFR(EXTI_CR1,     0x50A0); // Ext Int Ctrl reg 1
SFR(EXTI_CR2,     0x50A1); // Ext Int Ctrl reg 2
SFR(RST_SR,       0x50B3); // Reset Status register
SFR(CLK_ICKCR,    0x50C0); // Internal Clock Control reg
SFR(CLK_ECKCR,    0x50C1); // External Clock Control reg
SFR(CLK_CMSR,     0x50C3); // Master Status reg
SFR(CLK_SWR,      0x50C4); // Master Switch reg
SFR(CLK_SWCR,     0x50C5); // Switch Control reg
SFR(CLK_CKDIVR,   0x50C6); // Divider register
SFR(CLK_PCKENR1,  0x50C7); // Peripheral Clock Gating reg 1
SFR(CLK_CSSR,     0x50C8); // Security System register
SFR(CLK_CCOR,     0x50C9); // Configurable Clock Ctrl reg
SFR(CLK_PCKENR2,  0x50CA); // Peripheral Clock Gating reg 2
SFR(CLK_CANCCR,   0x50CB); // Can Clock Control reg
SFR(CLK_HSITRIMR, 0x50CC); // HSI Calibration Trimming reg
SFR(CLK_SWIMCCR,  0x50CD); // SWIM Clock Control reg
SFR(WWDG_CR,      0x50D1); // WWDG Control register
SFR(WWDG_WR,      0x50D2); // WWDG Window register
SFR(IWDG_KR,      0x50E0); // IWDG Key register
SFR(IWDG_PR,      0x50E1); // IWDG Prescaler register
SFR(IWDG_RLR,     0x50E2); // IWDG Reload register
SFR(AWU_CSR1,     0x50F0); // AWU Control/Status reg 1
SFR(AWU_APR,      0x50F1); // AWU Async Prescale Buffer reg
SFR(AWU_TBR,      0x50F2); // AWU Timebase selection reg
SFR(BEEP_CSR,     0x50F3); // BEEP control/status reg
SFR(SPI_CR1,      0x5200); // SPI Control register 1
SFR(SPI_CR2,      0x5201); // SPI Control register 2
SFR(SPI_ICR,      0x5202); // SPI Interrupt/Ctrl reg
SFR(SPI_SR,       0x5203); // SPI Status register
SFR(SPI_DR,       0x5204); // SPI Data I/O reg
SFR(SPI_CRCPR,    0x5205); // SPI CRC Polynomial reg
SFR(SPI_RXCRCR,   0x5206); // SPI Rx CRC register
SFR(SPI_TXCRCR,   0x5207); // SPI Tx CRC register
SFR(I2C_CR1,      0x5210); // Control register 1
SFR(I2C_CR2,      0x5211); // Control register 2
SFR(I2C_FREQR,    0x5212); // Frequency register
SFR(I2C_OARL,     0x5213); // Own Address reg low
SFR(I2C_OARH,     0x5214); // Own Address reg high
SFR(I2C_DR,       0x5216); // Data Register
SFR(I2C_SR1,      0x5217); // Status Register 1
SFR(I2C_SR2,      0x5218); // Status Register 2
SFR(I2C_SR3,      0x5219); // Status Register 3
SFR(I2C_ITR,      0x521A); // Interrupt Control reg
SFR(I2C_CCRL,     0x521B); // Clock Control reg low
SFR(I2C_CCRH,     0x521C); // Clock Control reg high
SFR(I2C_TRISER,   0x521D); // Trise reg
SFR(I2C_PECR,     0x521E); // Packet Error Checking reg
SFR(UART1_SR,     0x5230); // Status register
SFR(UART1_DR,     0x5231); // Data register
SFR(UART1_BRR1,   0x5232); // Baud Rate reg 1
SFR(UART1_BRR2,   0x5233); // Baud Rate reg 2
SFR(UART1_CR1,    0x5234); // Control register 1
SFR(UART1_CR2,    0x5235); // Control register 2
SFR(UART1_CR3,    0x5236); // Control register 3
SFR(UART1_CR4,    0x5237); // Control register 4
SFR(UART1_CR5,    0x5238); // Control register 5
SFR(UART1_GTR,    0x5239); // Guard Time register
SFR(UART1_PSCR,   0x523A); // Prescaler register
SFR(TIM1_CR1,     0x5250); // Control register 1
SFR(TIM1_CR2,     0x5251); // Control register 2
SFR(TIM1_SMCR,    0x5252); // Slave Mode Control reg
SFR(TIM1_ETR,     0x5253); // External Trigger reg
SFR(TIM1_IER,     0x5254); // Interrupt Enable reg
SFR(TIM1_SR1,     0x5255); // Status register 1
SFR(TIM1_SR2,     0x5256); // Status register 2
SFR(TIM1_EGR,     0x5257); // Event Generation reg
SFR(TIM1_CCMR1,   0x5258); // Capture/Compare Mode reg 1
SFR(TIM1_CCMR2,   0x5259); // Capture/Compare Mode reg 2
SFR(TIM1_CCMR3,   0x525A); // Capture/Compare Mode reg 3
SFR(TIM1_CCMR4,   0x525B); // Capture/Compare Mode reg 4
SFR(TIM1_CCER1,   0x525C); // Capture/Compare Enable reg 1
SFR(TIM1_CCER2,   0x525D); // Capture/Compare Enable reg 2
SFR(TIM1_CNTRH,   0x525E); // Counter reg High
SFR(TIM1_CNTRL,   0x525F); // Counter reg Low
SFR(TIM1_PSCRH,   0x5260); // Prescaler reg High
SFR(TIM1_PSCRL,   0x5261); // Prescaler reg Low
SFR(TIM1_ARRH,    0x5262); // Auto-reload reg High
SFR(TIM1_ARRL,    0x5263); // Auto-reload reg Low
SFR(TIM1_RCR,     0x5264); // Repetition Counter reg
SFR(TIM1_CCR1H,   0x5265); // Capture/Compare reg 1 High
SFR(TIM1_CCR1L,   0x5266); // Capture/Compare reg 1 Low
SFR(TIM1_CCR2H,   0x5267); // Capture/Compare reg 2 High
SFR(TIM1_CCR2L,   0x5268); // Capture/Compare reg 2 Low
SFR(TIM1_CCR3H,   0x5269); // Capture/Compare reg 3 High
SFR(TIM1_CCR3L,   0x526A); // Capture/Compare reg 3 Low
SFR(TIM1_CCR4H,   0x526B); // Capture/Compare reg 4 High
SFR(TIM1_CCR4L,   0x526C); // Capture/Compare reg 4 Low
SFR(TIM1_BKR,     0x526D); // Break register
SFR(TIM1_DTR,     0x526E); // Dead Time register
SFR(TIM1_OISR,    0x526F); // Output Idle State reg
SFR(TIM2_CR1,     0x5300); // Control register 1
SFR(TIM2_IER,     0x5303); // Interrupt Enable reg
SFR(TIM2_SR1,     0x5304); // Status Register 1
SFR(TIM2_SR2,     0x5305); // Status Register 2
SFR(TIM2_EGR,     0x5306); // Event Generation reg
SFR(TIM2_CCMR1,   0x5307); // Capture/Compare Mode reg 1
SFR(TIM2_CCMR2,   0x5308); // Capture/Compare Mode reg 2
SFR(TIM2_CCMR3,   0x5309); // Capture/Compare Mode reg 3
SFR(TIM2_CCER1,   0x530A); // Capture/Compare Enable reg 1
SFR(TIM2_CCER2,   0x530B); // Capture/Compare Enable reg 2
SFR(TIM2_CNTRH,   0x530C); // Counter reg High
SFR(TIM2_CNTRL,   0x530D); // Counter reg Low
SFR(TIM2_PSCR,    0x530E); // Prescaler register
SFR(TIM2_ARRH,    0x530F); // Auto-reload reg High
SFR(TIM2_ARRL,    0x5310); // Auto-reload reg Low
SFR(TIM2_CCR1H,   0x5311); // Capture/Compare Reg 1 High
SFR(TIM2_CCR1L,   0x5312); // Capture/Compare Reg 1 Low
SFR(TIM2_CCR2H,   0x5313); // Capture/Compare Reg 2 High
SFR(TIM2_CCR2L,   0x5314); // Capture/Compare Reg 2 Low
SFR(TIM2_CCR3H,   0x5315); // Capture/Compare Reg 3 High
SFR(TIM2_CCR3L,   0x5316); // Capture/Compare Reg 3 Low
SFR(TIM4_CR1,     0x5340); // Control register 1
SFR(TIM4_IER,     0x5343); // Interrupt enable reg
SFR(TIM4_SR,      0x5344); // Status register
SFR(TIM4_EGR,     0x5345); // Event Generation reg
SFR(TIM4_CNTR,    0x5346); // Counter register
SFR(TIM4_PSCR,    0x5347); // Prescaler register
SFR(TIM4_ARR,     0x5348); // Auto-reload register
SFR(ADC_CSR,      0x5400); // Control/Status reg
SFR(ADC_CR1,      0x5401); // Configuration reg 1
SFR(ADC_CR2,      0x5402); // Configuration reg 2
SFR(ADC_CR3,      0x5403); // Configuration reg 3
SFR(ADC_DRH,      0x5404); // Data reg high
SFR(ADC_DRL,      0x5405); // Data reg low
SFR(ADC_TDRH,     0x5406); // Schmitt Trigger Disable reg high
SFR(ADC_TDRL,     0x5407); // Schmitt Trigger Disable reg low
SFR(ADC_HTRH,     0x5408); // high threshold reg high
SFR(ADC_HTRL,     0x5409); // high threshold reg low
SFR(ADC_LTRH,     0x540A); // low threshold reg high
SFR(ADC_LTRL,     0x540B); // low threshold reg low
SFR(ADC_AWSRH,    0x540C); // analog watchdog status reg high
SFR(ADC_AWSRL,    0x540D); // analog watchdog status reg low
SFR(ADC_AWCRH,    0x540E); // analog watchdog control reg high
SFR(ADC_AWCRL,    0x540F); // analog watchdog control reg low
SFR(CFG_GCR,      0x7F60); // Global Configuration register
SFR(ITC_SPR1,     0x7F70); // Interrupt Software Priority Reg 1
SFR(ITC_SPR2,     0x7F71); // Interrupt Software Priority Reg 2
SFR(ITC_SPR3,     0x7F72); // Interrupt Software Priority Reg 3
SFR(ITC_SPR4,     0x7F73); // Interrupt Software Priority Reg 4
SFR(ITC_SPR5,     0x7F74); // Interrupt Software Priority Reg 5
SFR(ITC_SPR6,     0x7F75); // Interrupt Software Priority Reg 6
SFR(ITC_SPR7,     0x7F76); // Interrupt Software Priority Reg 7
SFR(ITC_SPR8,     0x7F77); // Interrupt Software Priority Reg 8
SFR(SWIM_CSR,     0x7F80); // SWIM Control Status Register
SFR(DM_BK1RE,     0x7F90); // IC Debugging Breakpoint 1 ESB Reg
SFR(DM_BK1RH,     0x7F91); // IC Debugging Breakpoint 1 High
SFR(DM_BK1RL,     0x7F92); // IC Debugging Breakpoint 1 Low
SFR(DM_BK2RE,     0x7F93); // IC Debugging Breakpoint 2 ESB Reg
SFR(DM_BK2RH,     0x7F94); // IC Debugging Breakpoint 2 High
SFR(DM_BK2RL,     0x7F95); // IC Debugging Breakpoint 2 Low
SFR(DM_CR1,       0x7F96); // IC Debugging Control register 1
SFR(DM_CR2,       0x7F97); // IC Debugging Control register 2
SFR(DM_CSR1,      0x7F98); // IC Debugging Control/Status reg 1
SFR(DM_CSR2,      0x7F99); // IC Debugging Control/Status reg 2
SFR(DM_ENFCTR,    0x7F9A); // IC Debugging Function Enable Reg 2
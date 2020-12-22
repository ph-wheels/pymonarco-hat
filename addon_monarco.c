/* add next section to monarco.c at line 33 */

/* Service Data Channel (SDC) registers data Items */
monarco_sdc_item_t *sdc_item_status;
monarco_sdc_item_t *sdc_item_fw_ver_lo, *sdc_item_fw_ver_hi;
monarco_sdc_item_t *sdc_item_hw_ver_lo, *sdc_item_hw_ver_hi;
monarco_sdc_item_t *sdc_item_mcu_id_1, *sdc_item_mcu_id_2, *sdc_item_mcu_id_3, *sdc_item_mcu_id_4;
monarco_sdc_item_t *sdc_item_config1;
monarco_sdc_item_t *sdc_item_rs485_baud, *sdc_item_rs485_mode;
monarco_sdc_item_t *sdc_item_cnt1_mode, *sdc_item_cnt2_mode;

/* add next section to monarco.c at line 166 just above the function "static void monarco_sdc_tx(monarco_cxt_t *cxt)" */
/* mind this part was found within the monarco examples file "main-complex-demo.c" as how to load the SDC struct and execute it. */
/*
 * Application Initialization
 *   We define here our set of SDC (Service Data Channel) Registers and initialize corresponding Item structures
 */
void sdc_init(monarco_cxt_t *cxt, uint16_t hw_config, uint16_t rs485_baud, uint16_t rs485_mode)
{
    int i = 0;

    /* Status Code */
    sdc_item_status = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_STATUS,
        .factor = 1
    };
    /* Firmware version */
    sdc_item_fw_ver_lo = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_FWVERL,
        .request = 1
    };
    sdc_item_fw_ver_hi = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_FWVERH,
        .request = 1
    };
    /* Hardware version */
    sdc_item_hw_ver_lo = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_HWVERL,
        .request = 1
    };
    sdc_item_hw_ver_hi = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_HWVERH,
        .request = 1
    };
    /* MCU ID */
    sdc_item_mcu_id_1 = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_MCUID1,
        .request = 1
    };
    sdc_item_mcu_id_2 = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_MCUID2,
        .request = 1
    };
    sdc_item_mcu_id_3 = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_MCUID3,
        .request = 1
    };
    sdc_item_mcu_id_4 = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_MCUID4,
        .request = 1
    };
    /* Hardware Configurarion Register 1 - enable RS-485 termination, both analog inputs in voltage mode */
    sdc_item_config1 = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_HWCONFIG1,
        .value = hw_config,
        //MONARCO_SDC_CONFIG1_RS485TERM | MONARCO_SDC_CONFIG1_AI1V | MONARCO_SDC_CONFIG1_AI2V,
        .write = 1,
        .request = 1
    };
    /* RS-485 Configuration - 38400 Baud, 8 data bits, 1 stop bit */
    sdc_item_rs485_baud = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_RS485BAUD,
        .value = rs485_baud,
        //384,
        .write = 1,
        .request = 1
    };
    sdc_item_rs485_mode = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_RS485MODE,
        .value = rs485_mode,
        //MONARCO_SDC_RS485_MODE_PARITY_NONE | MONARCO_SDC_RS485_MODE_DATABITS_8 | MONARCO_SDC_RS485_MODE_STOPBITS_1_0,
        .write = 1,
        .request = 1
    };
    /* Counter 1, 2 Configuration */
    sdc_item_cnt1_mode = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_CNT1CFG,
        .value = MONARCO_SDC_COUNTER_MODE_PCNT | MONARCO_SDC_COUNTER_EDGE_BOTH,
        .write = 1,
        .request = 1
    };
    sdc_item_cnt2_mode = &cxt->sdc_items[i]; cxt->sdc_items[i++] = (monarco_sdc_item_t){
        .address = MONARCO_SDC_REG_CNT2CFG,
        .value = MONARCO_SDC_COUNTER_MODE_QUAD,
        .write = 1,
        .request = 1
    };

    cxt->sdc_size = i;
}

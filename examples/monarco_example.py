import pymonarco_hat as plc
import sys
import time

lib_path = sys.argv[1]
plc_handler = plc.Monarco(lib_path, debug_flag=plc.MONARCO_DPF_WRITE | plc.MONARCO_DPF_VERB)

"""
addition of two function as to load the SDC struct with appication data and then execute it
"""

# load sdc values as to adjust hat behaviour, currently it only holds three values to adjust
plc_handler.sdc_load(0x01, 0x60, 0x38)	# rs485 term = on, rs485_baud = 96, rs485_mode = N, 1, 8
# execute sdc items list
plc_handler.sdc_exec()

""" end additional functions """

time.sleep(1)

while 1:
    print("AIN1:", plc_handler.get_analog_in(plc.AIN1))
    time.sleep(1)






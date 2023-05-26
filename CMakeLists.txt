cmake_minimum_required(VERSION 3.25)
project(rfPacketRx_CC1310_LAUNCHXL_nortos_ccs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(smartrf_settings)

add_executable(rfPacketRx_CC1310_LAUNCHXL_nortos_ccs
        smartrf_settings/smartrf_settings.c
        smartrf_settings/smartrf_settings.h
        Board.h
        CC1310_LAUNCHXL.c
        CC1310_LAUNCHXL.h
        CC1310_LAUNCHXL_fxns.c
        ccfg.c
        main_nortos.c
        rfPacketRx.c
        RFQueue.c
        RFQueue.h
        SerialPort.c
        SerialPort.h)

include_directories(D:/Install_software/ti/ccs1230/simplelink_cc13x0_sdk_4_20_02_07/source)
include_directories(D:/Install_software/ti/ccs1230/simplelink_cc13x0_sdk_4_20_02_07/kernel/nortos)
include_directories(D:/Install_software/ti/ccs1230/simplelink_cc13x0_sdk_4_20_02_07/kernel/nortos/posix)
include_directories(D:/Install_software/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include)
include_directories(D:/Install_software/ti/ccs1230/simplelink_cc13x0_sdk_4_20_02_07/source/ti/devices)
include_directories(D:/Install_software/ti/ccs1230/simplelink_cc13x0_sdk_4_20_02_07/source/ti/devices/cc13x0/driverlib)

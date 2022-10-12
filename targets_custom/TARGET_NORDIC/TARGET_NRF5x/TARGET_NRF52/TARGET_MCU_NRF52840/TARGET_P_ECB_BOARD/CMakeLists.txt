add_library(mbed-p-ecb-board INTERFACE)
#target_sources(mbed-p-ecb-board
#    INTERFACE
#        PeripheralPins.c
#)

target_include_directories(mbed-p-ecb-board
    INTERFACE
        .
)

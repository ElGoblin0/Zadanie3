#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>

#include "small_hw_emulator_lib.h"

using namespace std::chrono_literals;

void blink_led_1()
{
    emulator_lib::setLed1(true);
    std::this_thread::sleep_for(500ms);
    emulator_lib::setLed1(false);
    std::this_thread::sleep_for(500ms);
}

void blink_led_2()
{
    emulator_lib::setLed2(true);
    std::this_thread::sleep_for(250ms);
    emulator_lib::setLed2(false);
    std::this_thread::sleep_for(250ms);
}

void blink_led_3()
{
    emulator_lib::setLed3(true);
    std::this_thread::sleep_for(167ms);
    emulator_lib::setLed3(false);
    std::this_thread::sleep_for(167ms);
}

int main(int argc, char *argv[])
{
    std::cout << "init: " << emulator_lib::init("", "") << "!\n";

    int arr_size = 20;
    double vol1_sum = 0;
    double vol2_sum = 0;
    double vol1_avg;
    double vol2_avg;
    int loop1 = 1;
    int loop2 = 1;

    while (1)
    {
        auto vol1 = emulator_lib::getVoltage1();
        auto vol2 = emulator_lib::getVoltage2();
        auto in1 = emulator_lib::getInput1();
        auto in2 = emulator_lib::getInput2();

        double voltage1[arr_size];
        double voltage2[arr_size];

        std::string mean_value = std::to_string((vol1 + vol2)/2);

        emulator_lib::setLCD(mean_value);

        /* Próbowałem, ale nie chciało działać tak jak powinno
        if(in1 != true || in2 != true)
        {
             if(in1)
            {           
                vol1_avg = 0;

                for(int i = 0; i < arr_size; i++)
                { 
                    vol1_sum -= voltage1[i];
                    voltage1[i] = emulator_lib::getVoltage1();
                    vol1_sum += voltage1[i];
                    vol1_avg = vol1_sum/loop1;

                    if(loop1 <= 20)
                    {
                        loop1++;
                    }
                }
                std::string vol1_string = std::to_string(vol1_avg);
                emulator_lib::setLCD(vol1_string);
            }

            if(in2)
            {
                vol2_avg = 0;
                for(int i = 0; i < arr_size; i++)
                { 
                    vol2_sum -= voltage2[i];
                    voltage2[i] = emulator_lib::getVoltage2();
                    vol2_sum += voltage2[i];
                    vol2_avg = vol2_sum/loop2;

                    if(loop2 <= 20)
                    {
                        loop2++;
                    }                
                }

                std::string vol2_string = std::to_string(vol2_avg);

                emulator_lib::setLCD(vol2_string);
               
            }
        }
        */
        

        blink_led_1();
        std::this_thread::sleep_for(1000ms); 
        blink_led_2();
        std::this_thread::sleep_for(1000ms);
        blink_led_3();
        std::this_thread::sleep_for(1000ms);
    }

    return 0;
}

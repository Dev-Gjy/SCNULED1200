// Generated by imageconverter. Please, do not edit!

#ifndef TOUCHGFX_SVGDATABASE_HPP
#define TOUCHGFX_SVGDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/hal/VGData.hpp>

enum SVGImages
{
    SVG_BADBULBS_ID = 0,
    SVG_BLACKB_ID = 1,
    SVG_BLUEB_ID = 2,
    SVG_BLUETOOTH_ID = 3,
    SVG_CHOOSEBG_ID = 4,
    SVG_CHOOSEDOWN_ID = 5,
    SVG_CHOOSEUP_ID = 6,
    SVG_DMX_ID = 7,
    SVG_EXCHANGE_FUNDS_FILL_ID = 8,
    SVG_EXP_ID = 9,
    SVG_EXPLODE_ID = 10,
    SVG_FIREWORK_ID = 11,
    SVG_FLASH_ID = 12,
    SVG_LIGHTNING_ID = 13,
    SVG_LINE_CHART_FILL_ID = 14,
    SVG_LOG_ID = 15,
    SVG_PAPARAZZI_ID = 16,
    SVG_PULSE_ID = 17,
    SVG_S_ID = 18,
    SVG_SETTINGS_5_FILL_ID = 19,
    SVG_SOUND_MODULE_FILL_ID = 20,
    SVG_TRANSLATE_ID = 21,
    SVG_TV_ID = 22,
    SVG_WINDY_FILL_ID = 23,
    SVG_XY_ID = 24,
    NUMBER_OF_SVG_IMAGES = 25
};

namespace SVGDatabase
{
const touchgfx::VGObject* getInstance();
uint16_t getInstanceSize();
} // namespace SVGDatabase

#endif // TOUCHGFX_SVGDATABASE_HPP

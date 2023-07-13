/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenstudio_screen/ScreenStudioViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

ScreenStudioViewBase::ScreenStudioViewBase()
{
    __background.setPosition(0, 0, 480, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 480, 320);
    box1.setColor(touchgfx::Color::getColorFromRGB(41, 36, 36));
    add(box1);

    textArea1.setXY(153, 19);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_E91Y));
    add(textArea1);

    box_0.setPosition(198, 118, 85, 85);
    box_0.setColor(touchgfx::Color::getColorFromRGB(41, 36, 36));
    box_0.setBorderColor(touchgfx::Color::getColorFromRGB(0, 179, 255));
    box_0.setBorderSize(5);
    box_0.setVisible(false);
    add(box_0);

    image1.setXY(208, 128);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_STUDIO_ID));
    add(image1);
}

ScreenStudioViewBase::~ScreenStudioViewBase()
{

}

void ScreenStudioViewBase::setupScreen()
{

}
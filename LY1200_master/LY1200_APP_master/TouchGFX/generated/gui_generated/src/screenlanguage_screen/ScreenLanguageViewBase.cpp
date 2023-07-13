/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenlanguage_screen/ScreenLanguageViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

ScreenLanguageViewBase::ScreenLanguageViewBase()
{
    __background.setPosition(0, 0, 480, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 480, 320);
    box1.setColor(touchgfx::Color::getColorFromRGB(41, 36, 36));
    add(box1);

    textArea1.setXY(145, 17);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M5RJ));
    add(textArea1);

    image1_1.setXY(76, 100);
    image1_1.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_MEDIUM_ROUND_NORMAL_ID));
    add(image1_1);

    image1.setXY(76, 184);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_MEDIUM_ROUND_NORMAL_ID));
    add(image1);

    box_1.setPosition(128, 194, 208, 40);
    box_1.setColor(touchgfx::Color::getColorFromRGB(0, 54, 74));
    box_1.setVisible(false);
    add(box_1);

    box_0.setPosition(128, 110, 208, 40);
    box_0.setColor(touchgfx::Color::getColorFromRGB(0, 54, 74));
    box_0.setVisible(false);
    add(box_0);

    textArea2.setXY(162, 110);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YEAS));
    add(textArea2);

    textArea2_1.setXY(171, 194);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_N8ZP));
    add(textArea2_1);
}

ScreenLanguageViewBase::~ScreenLanguageViewBase()
{

}

void ScreenLanguageViewBase::setupScreen()
{

}

void ScreenLanguageViewBase::handleKeyEvent(uint8_t key)
{
    if(10 == key)
    {
        //Interaction1
        //When hardware button 10 clicked set language GB
        //Change language to GB
        Texts::setLanguage(GB);
        invalidate();
    
    }

    if(11 == key)
    {
        //Interaction2
        //When hardware button 11 clicked set language EN
        //Change language to EN
        Texts::setLanguage(EN);
        invalidate();
    
    }
}
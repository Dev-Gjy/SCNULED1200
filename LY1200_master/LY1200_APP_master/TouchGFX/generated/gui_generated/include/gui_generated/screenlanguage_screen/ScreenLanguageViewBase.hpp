/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENLANGUAGEVIEWBASE_HPP
#define SCREENLANGUAGEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screenlanguage_screen/ScreenLanguagePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/SVGImage.hpp>

class ScreenLanguageViewBase : public touchgfx::View<ScreenLanguagePresenter>
{
public:
    ScreenLanguageViewBase();
    virtual ~ScreenLanguageViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextArea textArea1;
    touchgfx::SVGImage svgchoosebg;
    touchgfx::SVGImage box_0;
    touchgfx::SVGImage box_1;
    touchgfx::TextArea textArea2;
    touchgfx::TextArea textArea2_1;

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // SCREENLANGUAGEVIEWBASE_HPP

#ifndef SCREENEFFECTPRESENTER_HPP
#define SCREENEFFECTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenEffectView;

class ScreenEffectPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenEffectPresenter(ScreenEffectView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

		void saveEffectType(int Type)
		{
			 model->saveEffectType(Type);			
		}
		
		
		int getEffectType()
		{
			return model->getEffectType();
		}	

    virtual ~ScreenEffectPresenter() {};

private:
    ScreenEffectPresenter();

    ScreenEffectView& view;
};

#endif // SCREENEFFECTPRESENTER_HPP

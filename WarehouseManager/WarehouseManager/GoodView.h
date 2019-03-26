#pragma once
#include <SFGUI/Widgets.hpp>
#include <SFML/Window.hpp>
#include "Good.h"
#include "GoodController.h"

class GoodView {
private:
	const Good* good;
	GoodController* controller;
	shared_ptr<sfg::Window> window;
	shared_ptr<sfg::Box> windowBox;
	shared_ptr<sfg::Entry> nameEntry;
	shared_ptr<sfg::SpinButton> quantitySpinButton;
	shared_ptr<sfg::SpinButton> weightSpinButton;
	shared_ptr<sfg::Button> saveButton;
	shared_ptr<sfg::Label> nameLabel;
	shared_ptr<sfg::Label> quantityLabel;
	shared_ptr<sfg::Label> weightLabel;
	uint32_t saveSignal = 0;
	void fillWindow();
public:
	GoodView();
	void setGood(const Good* good);
	void setController(GoodController* goodController);
	shared_ptr<sfg::Window> getWindow();
	shared_ptr<sfg::Button> getSaveButton();
	void setVisible(bool val);
};

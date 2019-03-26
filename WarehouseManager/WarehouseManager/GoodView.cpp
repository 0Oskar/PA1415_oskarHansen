#include "GoodView.h"

GoodView::GoodView() {
	good = nullptr;

	nameLabel = sfg::Label::Create("Name: ");
	quantityLabel = sfg::Label::Create("Quantity: ");
	weightLabel = sfg::Label::Create("Weight: ");

	nameEntry = sfg::Entry::Create();
	nameEntry->SetRequisition(sf::Vector2f(150, 30));
	
	quantitySpinButton = sfg::SpinButton::Create(0, 1000000, 1);
	quantitySpinButton->SetRequisition(sf::Vector2f(150, 30));
	
	weightSpinButton = sfg::SpinButton::Create(0, 1000000, 0.1);
	weightSpinButton->SetRequisition(sf::Vector2f(150, 30));
	weightSpinButton->SetDigits(1);

	saveButton = sfg::Button::Create("Save");
	
	windowBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
	windowBox->SetRequisition(sf::Vector2f(180, 200));
	windowBox->Pack(nameLabel);
	windowBox->Pack(nameEntry);
	windowBox->Pack(quantityLabel);
	windowBox->Pack(quantitySpinButton);
	windowBox->Pack(weightLabel);
	windowBox->Pack(weightSpinButton);
	windowBox->Pack(saveButton);

	window = sfg::Window::Create(sfg::Window::Style::NO_STYLE);
	window->SetRequisition(sf::Vector2f(180, 200));
	window->Add(windowBox);

	fillWindow();

	saveSignal = saveButton->GetSignal(sfg::Button::OnLeftClick).Connect(
		[&] {
		if (controller) {
			controller->setQuantity(quantitySpinButton->GetValue());
			controller->setWeight(weightSpinButton->GetValue());
			controller->setName(nameEntry->GetText());
		}
	});
}

shared_ptr<sfg::Window> GoodView::getWindow() {
	return window;
}

void GoodView::setGood(const Good* good) {
	this->good = good;
	if (good) {
		fillWindow();
	}
}

void GoodView::setController(GoodController* goodController) {
	controller = goodController;
}

void GoodView::fillWindow() {
	if (good) {
		window->Show(true);
		nameEntry->SetText(good->getName());
		quantitySpinButton->SetValue(good->getQuantity());
		weightSpinButton->SetValue(good->getWeight());
	}
	else {
		window->Show(false);
	}
}

void GoodView::setVisible(bool val) {
	window->Show(val);
}

shared_ptr<sfg::Button> GoodView::getSaveButton() {
	return saveButton;
}
#include"TruckViewer.h"

TruckViwer::TruckViwer()
{
	this->truck = nullptr;
	this->window = sfg::Window::Create();
	this->window->SetTitle("Truck");
	this->window->SetStyle(sfg::Window::Style::BACKGROUND | sfg::Window::Style::CLOSE | sfg::Window::Style::TITLEBAR);
	this->window->GetSignal(sfg::Window::OnCloseButton).Connect([&] { setTruck(nullptr); });
	this->window->SetRequisition(sf::Vector2f(600, 600));
	this->window->SetPosition(sf::Vector2f(400, 400));
	windowBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 3.f);

	this->xAndYCordLabel = sfg::Label::Create("Move truck to: (X/Y)");
	windowBox->Pack(xAndYCordLabel);
	this->xCord = sfg::Entry::Create();
	this->xCord->SetRequisition(sf::Vector2f(50, 30));
	windowBox->Pack(xCord, false, false);

	this->yCord = sfg::Entry::Create();
	this->yCord->SetRequisition(sf::Vector2f(50, 30));
	windowBox->Pack(yCord, false, false);

	this->moveTruck = sfg::Button::Create("Move truck");
	windowBox->Pack(moveTruck);

	

	this->batteryTypeLabel = sfg::Label::Create("Battery Type: ");
	windowBox->Pack(batteryTypeLabel);
	this->batteryType = sfg::Entry::Create();
	this->batteryType->SetRequisition(sf::Vector2f(200, 30));
	windowBox->Pack(batteryType);


	this->manufactoryLabel = sfg::Label::Create("Truck Manufactor: ");
	windowBox->Pack(manufactoryLabel);
	this->manufactorName = sfg::Entry::Create();
	this->manufactorName->SetRequisition(sf::Vector2f(200, 30));
	windowBox->Pack(manufactorName);

	
	this->lastDayOfServiceLabel = sfg::Label::Create("Date of latest service: ");
	windowBox->Pack(lastDayOfServiceLabel);
	this->lastDateOfService = sfg::Entry::Create();
	this->lastDateOfService->SetRequisition(sf::Vector2f(250, 30));
	windowBox->Pack(lastDateOfService);


	this->updateButton = sfg::Button::Create("Update");

	windowBox->Pack(updateButton);
	window->Add(windowBox);

	fillWindow();

	moveTruckSignal = moveTruck->GetSignal(sfg::Button::OnLeftClick).Connect(
		[&] {
		if (truckController) {
			int x, y;
			std::stringstream xPos(static_cast<std::string>(xCord->GetText()));
			xPos >> x;
			std::stringstream yPos(static_cast<std::string>(yCord->GetText()));
			yPos >> y;
	
			this->truckController->moveTruck(this->truckController->getTruck(), x, y);
		}
	});
	updateSignal = updateButton->GetSignal(sfg::Button::OnLeftClick).Connect(
		[&] {
		if (truckController) {
			//Do the update
			truckController->setBatteryType(batteryType->GetText());
			truckController->setDateOfLatestService(lastDateOfService->GetText());
			truckController->setTruckManufactor(manufactorName->GetText());

			
		}
	});
}
void TruckViwer::setTruck(const Truck* truck)
{
	this->truck = truck;
	if (truck)
	{
		setVisible(true);
		fillWindow();
	}
	else
	{
		setVisible(false);
	}
}
void TruckViwer::setController(TruckController* truckController)
{
	this->truckController = truckController;
}

void TruckViwer::setVisible(bool val)
{
	window->Show(val);
}

void TruckViwer::fillWindow() {
	if (truck) {
		window->Show(true);
		this->batteryType->SetText(truck->getBatteryType());
		this->manufactorName->SetText(truck->getTruckManufactor());
		this->lastDateOfService->SetText(truck->getDateOfLatestService());
		this->xCord->SetText("0");
		this->yCord->SetText("0");

	}
	else {
		window->Show(false);
	}
}

sf::FloatRect TruckViwer::getRect()
{
	return this->window->GetAllocation();
}

void TruckViwer::update(float seconds)
{
	this->window->Update(seconds);
}
void TruckViwer::handleEvent(sf::Event event)
{
	this->window->HandleEvent(event);
}
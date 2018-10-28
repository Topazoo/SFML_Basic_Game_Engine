#include "Menu.h"

MenuButton::MenuButton(int top, int height, int left, int width,
	std::string actionName, int action) : rect(new sf::Rect<int>)
{
	/* Create a button */

	rect->top = top;
	rect->height = height;
	rect->left = left;
	rect->width = width;

	this->actionName = actionName;
	this->action = action;
}

MenuButton::~MenuButton()
{
	delete rect;
}

void Menu::AddButton(int top, int height, int left, int width,
	std::string actionName)
{
	/* Add a button to the menu */

	/* Create an incremental button number */
	/* Reserve 0 for doing nothing */
	int buttonNum = static_cast<int>(_menuButtons->size()) + 1;

	/* Create the button */
	MenuButton* newButton = new MenuButton(top, height, left, width,
		actionName, buttonNum);

	/* Store in hash table of hash tables based on bottom and right margins */
	(*_menuButtons)[newButton->GetBottom()][newButton->GetRight()] = newButton;
}

int Menu::Show(sf::RenderWindow* window)
{
	/* Display the main menu and responds to button presses */

	/* Load menu image (with buttons drawn in */
	sf::Texture menuImage;
	menuImage.loadFromFile("images/menu/Mainmenu.png");
	sf::Sprite sprite(menuImage);

	/* Create buttons */
	AddButton(145, 235, 0, 1023, "Play"); // 1
	AddButton(383, 177, 0, 1023, "Exit"); // 2

	window->draw(sprite);
	window->display();

	return GetMenuResponse(window);
}

int Menu::HandleClick(int x, int y)
{
	/* Determine menu button pressed by click coordinates */

	std::map<int, std::map<int, MenuButton*> >::iterator col;
	std::map<int, MenuButton*>::iterator row;

	/* Search column hash table for column of buttons closest to click */
	col = _menuButtons->lower_bound(y);

	/* If no column of buttons found, do nothing */
	if (col == _menuButtons->end())
		return 0;

	/* Otherwise search for closest button in column */
	row = col->second.lower_bound(x);

	/* Validate that button is correct */
	if (row != col->second.end())
	{
		if (row->second->GetTop() < y &&
			row->second->GetBottom() > y &&
			row->second->GetLeft() < x &&
			row->second->GetRight() > x)
		{
			return row->second->GetAction();
		}
	}

	/* Return 0 if not found or not correct */
	return 0;	
}

int Menu::GetMenuResponse(sf::RenderWindow* window)
{
	/* Respond to user actions on the menu */

	sf::Event menuEvent;
	
	/* Infinite loop on menu until user action */
	while (true)
	{

		while (window->pollEvent(menuEvent))
		{
			/* If clicked, check coordinates to see if there's a button there */
			if (menuEvent.type == sf::Event::MouseButtonPressed)
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);

			/* If closed, exit game */
			if (menuEvent.type == sf::Event::Closed)
				return -1;	
		}
	}
}

Menu::~Menu()
{
	/* Deallocate all stored objects using functor */
	std::for_each(_menuButtons->begin(), _menuButtons->end(), MenuButtonColDeallocator());
	delete _menuButtons;
}
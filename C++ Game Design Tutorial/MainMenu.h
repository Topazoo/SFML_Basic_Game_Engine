#pragma once

class MenuButton
{
public:
	MenuButton(int top, int right, int bottom, int left,
		std::string actionName, int action);

	int button_getTop() { return rect.top; };
	int button_getBottom() { return rect.top + rect.height; };
	int button_getLeft() { return rect.left; };
	int button_getRight() { return rect.left + rect.width; };
	int button_getAction() { return action; };
	std::string button_getActionName() { return actionName; };

private:
	sf::Rect<int> rect;
	int action;
	std::string actionName;
};

class Menu
{

public:
	int Show(sf::RenderWindow* window);
	void AddButton(int top, int height, int left, int width,
		std::string actionName);

	~Menu();

private:
	int HandleClick(int x, int y);
	int GetMenuResponse(sf::RenderWindow* window);
	std::map<int, MenuButton*> _menuButtons;
};
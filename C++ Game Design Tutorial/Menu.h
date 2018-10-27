#pragma once

class MenuButton
{
public:
	MenuButton(int top, int right, int bottom, int left,
		std::string actionName, int action);

	int GetTop() { return rect.top; };
	int GetBottom() { return rect.top + rect.height; };
	int GetLeft() { return rect.left; };
	int GetRight() { return rect.left + rect.width; };
	int GetAction() { return action; };
	std::string GetActionName() { return actionName; };

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
	std::map<int, std::map<int, MenuButton*> > _menuButtons;
};
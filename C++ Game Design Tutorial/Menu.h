#pragma once

class MenuButton
{
public:
	MenuButton(int top, int right, int bottom, int left,
		std::string actionName, int action);

	int GetTop() const { return rect->top; };
	int GetBottom() const { return rect->top + rect->height; };
	int GetLeft() const { return rect->left; };
	int GetRight() const { return rect->left + rect->width; };
	int GetAction() const { return action; };

	std::string GetActionName() const { return actionName; };

	~MenuButton();

private:
	sf::Rect<int>* rect;
	int action;
	std::string actionName;
};

class Menu
{

public:
	Menu() : _menuButtons(new std::map<int, std::map<int, MenuButton*> >) {};

	int Show(sf::RenderWindow* window);
	void AddButton(int top, int height, int left, int width,
		std::string actionName);

	~Menu();

private:
	int HandleClick(int x, int y);
	int GetMenuResponse(sf::RenderWindow* window);
	std::map<int, std::map<int, MenuButton*> >* _menuButtons;


	/* Functor to use during foreach deallocation */
	struct MenuButtonRowDeallocator
	{
		void operator()(const std::pair<int, MenuButton*> & p) const
		{
			delete p.second;
		}
	};

	/* Functor to use during foreach column deallocation */
	struct MenuButtonColDeallocator
	{
		void operator()(const std::pair<int, std::map<int, MenuButton*> > & p) const
		{
			std::for_each(p.second.begin(), p.second.end(), MenuButtonRowDeallocator());
		}
	};

};
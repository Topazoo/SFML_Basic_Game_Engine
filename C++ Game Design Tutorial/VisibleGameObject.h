#pragma once
class VisibleGameObject
{
public:
	VisibleGameObject(std::string name, std::string filename) : _isLoaded(false), _name(name), _filename(filename) {};
	virtual ~VisibleGameObject();

	virtual void Load();
	virtual std::string getName() { return _name; };
	virtual void Draw(sf::RenderWindow* window);

	virtual void SetPosition(float x, float y);

	std::string _name;
	std::string _filename;

private:
	sf::Sprite  _sprite;
	sf::Texture _image;
	bool _isLoaded;
};


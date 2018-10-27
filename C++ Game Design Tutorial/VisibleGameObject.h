#pragma once

class VisibleGameObject
{
public:
	VisibleGameObject(std::string name, std::string filename) : _isLoaded(false), _name(name), _filename(filename) {};
	virtual ~VisibleGameObject();

	virtual void Load(float xPos, float yPos);
	virtual void Draw(sf::RenderWindow* window);
	virtual void SetPosition(float x, float y);

	virtual std::string GetName() { return _name; };

protected:
	std::string _name;
	std::string _filename;

private:
	sf::Sprite  _sprite;
	sf::Texture _image;
	bool _isLoaded;
};


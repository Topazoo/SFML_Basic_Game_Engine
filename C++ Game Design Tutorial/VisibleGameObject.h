#pragma once

class VisibleGameObject
{
public:
	VisibleGameObject(std::string name, std::string filename) : 
		_isLoaded(false), _name(name), _filename(filename), 
		_sprite(new sf::Sprite), _image(new sf::Texture) {};

	virtual ~VisibleGameObject();

	virtual void Load(float xPos, float yPos);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(float elapsedTime);

	virtual void SetPosition(float x, float y);
	
	virtual sf::Vector2f GetPosition() const;
	virtual std::string GetName() const { return _name; };

protected:
	sf::Sprite* GetSprite();

private:
	std::string _name;
	std::string _filename;
	sf::Sprite*  _sprite;
	sf::Texture* _image;
	bool _isLoaded;
};


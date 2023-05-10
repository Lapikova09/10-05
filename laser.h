#pragma once
#include "settings.h"
class Laser {
public:
	enum LaserType { BLUE, GREEN, RED, TYPES_QTY };
	Laser(LaserType type, sf::Vector2f playerPos);
	void update();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	LaserType type;

	sf::Sprite& getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	float getPosY() { return sprite.getPosition().y; }

};
Laser::Laser(LaserType type, sf::Vector2f playerPos) {
	this->type = type;
	switch (type) {
	case BLUE:
		texture.loadFromFile(BLUE_FILENAME);
		break;
	case GREEN:
		texture.loadFromFile(GREEN_FILENAME);
		break;
	case RED:
		texture.loadFromFile(RED_FILENAME);
		break;
	}
	sprite.setTexture(texture);
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	sprite.setPosition(playerPos);
}
void Laser::update() {
	sprite.move(LASER_SPEED, 0.f);
}
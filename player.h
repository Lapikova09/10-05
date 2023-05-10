#pragma once
#include <list>
#include "settings.h"
class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedY;
	void controlPlayer();
public:
	Player();

	void fire();

	void update();

	void draw(sf::RenderWindow& window);

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};

Player::Player() {
	texture.loadFromFile(PLAYER_FILENAME);
	sprite.setTexture(texture);
	sprite.setPosition(START_POS);
}
void Player::update() {
	speedY = 0.f;
	controlPlayer();
	sprite.move(0.f, speedY);
}
void Player::controlPlayer() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		speedY = -SPEED_Y;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		speedY = SPEED_Y;
	}
	if (sprite.getPosition().y < 0) {
		sprite.setPosition(sprite.getPosition().x, 0.f);
	}
	else if (sprite.getPosition().y > WINDOW_HEIGHT - sprite.getGlobalBounds().height) {
		sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - sprite.getGlobalBounds().height);
	}
};
void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
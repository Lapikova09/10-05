#pragma once
#include <vector>
#include "settings.h"
#include "player.h"
#include "okean.h"
#include "fish.h"
class Game {
public:
	enum GameState { PLAY, GAME_OVER, YOU_WIN };
	GameState gameState = PLAY;
	Game() {
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		Fish* fish1 = new Fish(Fish::FishType::RED);
		Fish* fish2 = new Fish(Fish::FishType::GREEN);
		Fish* fish3 = new Fish(Fish::FishType::BLUE);
		Fish* fish4 = new Fish(Fish::FishType::RED);
		Fish* fish5 = new Fish(Fish::FishType::GREEN);
		Fish* fish6 = new Fish(Fish::FishType::BLUE);
		fishSprites.push_back(fish1);
		fishSprites.push_back(fish2);
		fishSprites.push_back(fish3);
		fishSprites.push_back(fish4);
		fishSprites.push_back(fish5);
		fishSprites.push_back(fish6);
	}

	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			draw();
		}
	}

private:
	sf::RenderWindow window;
	Player player;
	Okean ocean;
	std::list<Fish*> fishSprites;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update() {
		switch (gameState) {
		case PLAY:
			player.update();
			for (auto& fish : fishSprites) {
				fish->update();
			}
			ocean.update();
			break;
		case GAME_OVER:
			
			break;
		case YOU_WIN:
			
			break;
		}
	}


	void checkCollisions() {
		   


	}

	void draw() {
		switch (gameState) {
		case PLAY:
			window.clear();
			ocean.draw(window);
			player.draw(window);
			for (const auto& fish : fishSprites) {
				fish->draw(window);
			}
			window.display();
			break;
		case GAME_OVER:
			window.clear();
			
			window.display();
			break;
		case YOU_WIN:
			window.clear();
		
			window.display();
			break;
		}
	}
};

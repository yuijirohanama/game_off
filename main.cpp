#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Projectile.h"
#include "Door.h"


static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{	
	sf::RenderWindow window(sf::VideoMode(512, 512), "Game");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	window.setMouseCursorVisible(false); // Hide cursor
	sf::Texture Crosshair;
    Crosshair.loadFromFile("../curosor.png");
    sf::Sprite MouseSprite(Crosshair);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("../adventurer_sprite_sheet_v1.1.png");	
	sf::Texture mapTexture;
	mapTexture.loadFromFile("../ZeldaOverworldMapQ1.png");
	sf::Texture healthBar;
    healthBar.loadFromFile("../healthbar.png");
	sf::Texture bulletTexture;
	bulletTexture.loadFromFile("../bullet.jpg");
	sf::Texture doorTexture;
	doorTexture.loadFromFile("../door_cel-sheet.png");
	std::vector<Door> doors;
	doors.emplace_back(&doorTexture, sf::Vector2f(300,100), false, 0.08f, Door::left);
	//doors.emplace_back(&doorTexture, sf::Vector2f(300,200), false, 0.08f, Door::left);
	Player player(&playerTexture, sf::Vector2u(13,8), 0.08f, 100.0f);
	player.AddDoors(&doors);
	sf::RectangleShape map(sf::Vector2f(17408.0f, 5632.0f));
	map.setTexture(&mapTexture);
	Platform platform1(nullptr, sf::Vector2f(40.0f, 20.0f), sf::Vector2f(700.0f, 300.0f));
	Platform platform2(nullptr, sf::Vector2f(40.0f, 20.0f), sf::Vector2f(800.0f, 0.0f));
	Projectile bullet(&bulletTexture, sf::Vector2f(255.0f, 0.0f), 8.0f, player.GetPosition());
	float deltaTime = 0.0f;
	sf::Clock clock;
	while (window.isOpen()){
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
        while (window.pollEvent(event))
            
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus:
				std::cout << "lost" << std::endl;
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			
			}
	player.Update(deltaTime);
	Collider col = player.GetCollider();
	for (size_t i = 0; i < doors.size(); i++)
	{
		doors[i].Update(deltaTime);
	}
	
	platform1.GetCollider().checkCollision(col, 1.0f);
	platform2.GetCollider().checkCollision(col, 0.0f);
	view.setCenter(player.GetPosition());
	window.clear();	
	window.setView(view);
	window.draw(map);
	player.Draw(window);
	platform1.Draw(window);
	platform2.Draw(window);
	for (size_t i = 0; i < doors.size(); i++)
	{
		doors[i].Draw(window);
	}
	MouseSprite.setOrigin(500,500);
    MouseSprite.setPosition(((static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) + player.GetPosition()) - sf::Vector2f((window.getSize().x) /2, (window.getSize().y) /2));
    MouseSprite.setScale(sf::Vector2f(0.05f,0.05f));	
	window.draw(MouseSprite);
	window.display();
	}
	return 0;
}

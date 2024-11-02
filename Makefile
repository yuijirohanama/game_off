all:
	clang++ -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system main.cpp Animation.cpp Player.cpp Collider.cpp Platform.cpp Projectile.cpp Hurtbox.cpp Hitbox.cpp -o bin/game

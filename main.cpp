#include "game.h"

int main() {
	player j("hi");
	database d;
	game g(j, d);
	g.play();
}
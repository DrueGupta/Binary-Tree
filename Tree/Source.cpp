#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
	Tree<string> Destiny;
	//Kinetic
	Destiny.insert("Conditional Finality");
	Destiny.insert("Travelers Choosen");
	Destiny.insert("Khovostov");
	//Energy
	Destiny.insert("Polaris Lance");
	Destiny.insert("Icebreaker");
	Destiny.insert("Vex Mythoclast");
	//Power
	Destiny.insert("Gjallorhorn");
	Destiny.insert("Deathbringer");
	Destiny.insert("Dragons Breath");

	Destiny.remove("Vex Mythoclast");
	Destiny.display();
}

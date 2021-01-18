#include <iostream>
#include <string>
#include "CCoffee.cpp"

int main() {
	// Some Variables
	std::string CS = "The Coffee Shop";

	// Head Info/MetaData
	metadata.title(CS + " - Home");
	metadata.link("main.css", "stylesheet");

	// Body Info/MainData
	maindata.header(CS, "1", "color: #6B4C35; text-align: center; font-family: Custom;");
	maindata.paragraph("Thank you for checking out CCoffee! Here is a very compact and simple compiled site (excluding main.css).", "text-align: center; color: #6B4C35;");
	maindata.image("coffee.gif", "620", "348", "display: block; margin-left: auto; margin-right: auto; border: 3px dotted #6B4C35;");

	compiler.compile("index");
}

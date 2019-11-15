/*
Abdulaziz Alamro
CS441 - Software Engineering
Group Project - Recipe Class
*/

#include <string>
#include <stdlib.h>
#include "Drink.h"
#include "recipe.h"
#include "Ingredient.h"

Recipe tempRecipe;
Recipe::Recipe()
{}


void Recipe::readRecipe()
{
	string inputLine;
	string drink;
	ifstream fin;
	fin.open("File.txt");
	if (!fin) {
		cout << "The input file can not be opened.\n";
	}
	else {
		getline(fin, inputLine);
		if (inputLine == "Drink") {
			getline(fin, drink);
			while (getline(fin, inputLine)) {
				if (inputLine != "End")
					recipeList.push_back(inputLine);
				else
					break;
			}
		}
	}
}

void Recipe::displayRecipe()
{
	int length = recipeList.size();
	for (int i = 0; i < length; i++) {
		cout << "Step " << i + 1 << ": ";
		cout << recipeList.at(i) << "\n";
	}
	cout << "\n";
}

void Recipe::readMaterials() {
	string inputLine;
	ifstream fin;
	fin.open("File.txt");
	if (!fin) {
		cout << "The input file can not be opened.\n";
		return;
	}
	while (getline(fin, inputLine)) {
		if (inputLine == "Materials")
		{
			while (getline(fin, inputLine))
			{
				if (inputLine == "End")
					break;
				reqMaterials.push_back(inputLine);
			}
		}
	}
}

void Recipe::displayMaterials()
{
	int length = reqMaterials.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Material " << i + 1 << ": " << reqMaterials.at(i) << "\n";
	}
}

//void Recipe::addIngredient(Ingredient newIngredient)
//{
//	ingredientList.push_back(newIngredient);
//}

void Recipe::displayIngredients()
{
	int length = ingredientList.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Ingredient " << i + 1 << ": " << ingredientList.at(i).getName() << "\n";
	}
}


Recipe Recipe::addIngredient(Ingredient ingredient)
{
	ingredientList.push_back(ingredient);
	return *this;
}


void Recipe::readDrinks()
{

	string inputLine;
	string drink;
	string ingredient;
	type drinktype;
	int proof;
	price dPrice;
	string sPrice;
	ifstream fin;

	fin.open("File.txt");
	if (!fin) {
		cout << "The input file can't be opened.\n";
		return;
	}

	while (!EOF) {
		getline(fin, inputLine);
		if (inputLine == "Drink")
			getline(fin, drink);

		getline(fin, inputLine);
		while (inputLine == "Ingredients")
		{

			getline(fin, ingredient);
			getline(fin, inputLine);
			if (inputLine == "liquid")
				drinktype = liquid;
			else
				drinktype = garnish;
			getline(fin, inputLine);
			proof = stoi(inputLine);
			getline(fin, inputLine);
			sPrice = inputLine;
			if (inputLine == "low")
				dPrice = low;
			else if (inputLine == "mid")
				dPrice = mid;
			else
				dPrice = high;

			Ingredient tempIngredient(ingredient, drinktype, proof, dPrice);
			tempRecipe.addIngredient(tempIngredient);

			getline(fin, inputLine);
		}

		while (getline(fin, inputLine))
		{
			if (inputLine == "Materials") {
				while (getline(fin, inputLine)) {
					if (inputLine == "End")
						break;
					tempRecipe.reqMaterials.push_back(inputLine);
				}
			}
		}

		getline(fin, inputLine);
		if (inputLine == "Steps")
		{
			while (getline(fin, inputLine))
			{
				if (inputLine == "End")
					break;
				tempRecipe.recipeList.push_back(inputLine);
			}
		}
		getline(fin, inputLine);
		if (inputLine == "Alcohol Content")
			getline(fin, inputLine);
		Drink tempDrink(drink, tempRecipe, inputLine);

	}
}

/*
Abdulaziz Alamro
CS441 - Software Engineering
Group Project - Recipe Class
*/
#include <iostream>
#include <vector>
#include <fstream>
#include "Ingredient.h"

using namespace std;

class Recipe
{
public:
	

	Recipe();
	void readDrinkName();
	void readRecipe();
	void displayRecipe();
	void readMaterials();
	void displayMaterials();
	Recipe addIngredient(Ingredient ingredient);
	void displayIngredients();
	void readDrinks();

	vector<string> recipeList;
	vector<string> reqMaterials;
	vector<Ingredient> ingredientList;
	friend class Read;

};

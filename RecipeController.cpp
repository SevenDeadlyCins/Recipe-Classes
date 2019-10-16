/*
Abdulaziz Alamro
CS441 - Software Engineering
Group Project - Recipe Class
*/
#include <iostream>
#include <vector>
using namespace std;

class RecipeController{
	private:
		vector<Recipe> recipeList;
	public:
		void addRecipe(Recipe recipe){
			recipeList.push_back(recipe);
		}
		
		void deleteRecipe(int position){
			 recipeList.erase(position);
		}
		
		void editRecipe(Recipe recipe,int position){
			recipeList.insert(position,recipe);
		}
		
};

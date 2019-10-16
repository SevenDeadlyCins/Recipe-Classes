/*
Abdulaziz Alamro
CS441 - Software Engineering
Group Project - Recipe Class
*/

#include <iostream>
#include <vector>
using namespace std;

//Class
class Recipe{
	// Access specifier 
    private: 
    
    // Data Members 
    string recipeName; 
    vector<Ingredient> ingredientList;
	 
  	public:
  		
    // getter and setter for Name 
    void setRecipeName(string recipeName){
    	this->recipeName = recipeName;
	}
	
	string getRecipeName(){
		return recipeName;
	}
	
    //getter setter for Vector of Favorite
    
    void setIngredientList(vector<Ingredient> ingredientList){
    	this->ingredientList = ingredientList;
	}
	
	vector<Favorite> getIngredientList(){
		return ingredientList;
	}
};

#include <iostream>
#include <vector>
/*
* This is a code which violates the principle
* where we constantly have to make change in ProductFilter class
* which is working well.
* But constant changes will compromise the integrity of
* the class
*/
using namespace std;

class enum Color{red, green, blue};
class enum Size{small, medium, large};

struct Product{
	string name;
	Color color;
	Size size;
	};

struct ProductFilter{
	//This works fine for class having one filter
	vector<Product*> by_color(vector<Product* >items, Color color) {
		vector<Product* > result;
		for (auto& i : items) {
			if (i->color == color)
				result.push_back(i);
		}
		return result;
	}
	//For another attribute need to modify the code
	vector<Product*> by_size(vector<Product* >items, Size size) {
		vector<Product* > result;
		for (auto& i : items) {
			if (i->size == size)
				result.push_back(i);
		}
	return result;
	}
	//For another new requirement again modification of code is required
	vector<Product*> by_size_and_color(vector<Product* >items, Size size, Color color) {
		vector<Product* > result;
		for (auto& i : items) {
			if (i->size == size && i->color == color)
				result.push_back(i);
		}
	return result;
	}
};



int main(){
	Product apple{ "Apple", Color::green, Size::small };
	Product tree{ "Tree", Color::green, Size::large };
	Product house{ "House", Color::blue, Size::large };
	vector<Product*> list{ &apple, &tree, &house };
	
	ProductFilter pf;
	vector<Product*> res = pf.by_color(list, Color::green);
	
	for (auto& i : res) {
		cout << i->name << " ";
	}
	
	vector<Product*> res2 = pf.by_size(list, Size::large);
	
	for (auto& i : res2) {
		cout << i->name << " ";
	}
	
	vector<Product*> res3 = pf.by_color_and_size(list, Color::green, Size::large);
	
	for (auto& i : res3) {
		cout << i->name << " ";
	}
	
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

/*
* If the code is not broken 
* then dont touch it just extend it
* This is what open close pattern states
* Open for extension close for modification
*/

class enum Color{red, green, blue};
class enum Size{small, medium, large};

struct Product{
	string name;
	Color color;
	Size size;
	};
	

template <typename T>
struct Specification{
	virtual ~Specification(){}
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct Filter{
	virtual vector<T*> filter(vector<T*> items, Specification<T> &spec) = 0;
};

struct BetterFilter: Filter<Product>{
	vector<Product*> filter(vector<Product *> list, Specification<Product> &spec) {
	vector<Product *> result;
	for (auto& i : list) {
		if (spec.is_satisfied(i)) {
			result.push_back(i);
		}
	}

	return result;
}

struct ColorSpecification : Specification<Product> {
	Color color;
	
	ColorSpecification(Color color) :color(color) {}
	
	bool is_satisfied(Product* item){
		return item->color == this->color;
	}
};

struct SizeSpecification : Specification<Product> {
	Size size;
	
	SizeSpecification(Size color) :size(size) {}
	
	bool is_satisfied(Product* item){
		return item->size == this->size;
	}
};

int main(){
	Product apple{ "Apple", Color::green, Size::small };
	Product tree{ "Tree", Color::green, Size::large };
	Product house{ "House", Color::blue, Size::large };
	vector<Product*> list{ &apple, &tree, &house };
	

	BetterFilter bf;
	ColorSpecification green{ Color::green };

	for (auto& i : bf.filter(list, green)) {
		cout << i->name << " ";
	}
	
	return 0;
}


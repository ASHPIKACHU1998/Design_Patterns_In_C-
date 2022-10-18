#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Journal {
		string title;
		vector<string> entries;
		static int count;
		
		Journal(const string& title): title(title){}
		
		void addEntry(const string& entry){
			char tmp[1024] = {0};
			snprintf(tmp, sizeof(entry), "%d: %s", udemy::Journal::count++, entry.c_str());
			this->entries.push_back(tmp);
		}
	};
	
	struct PersistenceManager {
		void static save(const Journal& j, const string& fileName) {
			ofstream ofs(fileName);
			for (auto& e : j.entries) {
				ofs << e << endl;
			}
		}
	};

int main() {
	Journal journal{ "Dear Diary" };
	journal.addEntry("I luv u");
	journal.addEntry("It is done");
	journal.addEntry("This is the third unit");

	PersistenceManager pm;
	pm.save(journal, "TEST.txt");

	return 0;
}
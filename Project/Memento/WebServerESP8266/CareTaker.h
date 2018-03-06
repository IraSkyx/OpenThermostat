#include <vector>

using namespace std;
class CareTaker
{
	void add(Memento state) { mementoList.push_back(state); }
	Memento get(int index) { return mementoList[index];  }
private:
	vector<Memento> mementoList;
};

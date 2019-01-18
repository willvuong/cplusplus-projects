#include "ItemManager.h"
#include "Item.h"
#include <vector>

void ItemManager::display(std::ostream & os, bool t) const {
	/*std::vector<Item> items;
	std::vector<Item>::iterator itemIterator;

	for (itemIterator = items.begin(); itemIterator != items.end(); itemIterator++) {
		itemIterator->display(os, t);
	}*/

	std::vector<Item>::const_iterator itemIterator;
	for (itemIterator = this->begin(); itemIterator != this->end(); itemIterator++) {
		itemIterator->display(os, t);
	}
}

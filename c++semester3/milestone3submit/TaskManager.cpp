#include "TaskManager.h"
#include "Task.h"
#include "ItemManager.h"
#include "Item.h"
#include <algorithm>

void TaskManager::validate(std::ostream & os) {
	bool t = true;
	for (int i = 0; i < this->size(); i++) {
		for (int j = 0; j < this->size(); j++) {
			if (this->at(i).validate(this->at(j))) {
				t = false;
			}
		}
		t = true;
	}
	if (!t) {
		os << "Not all task have been validated";
	}
}

void TaskManager::validate(const ItemManager & itemManager, std::ostream & os) {
	std::vector<Item>::const_iterator iterator;
	for (iterator = itemManager.begin(); iterator != itemManager.end(); iterator++) {
		auto removerLambda = [&](const Task& task) {
			if (task.getName() == iterator->getRemover()) { return true; }
			else { return false; }
		};
		auto fillerLambda = [&](const Task& task) {
			if (task.getName() == iterator->getFiller()) { return true; }
			else { return false; }
		};

		if (std::find_if(this->begin(), this->end(), removerLambda) == this->end()) { // check object for matching remover task
			os << iterator->getRemover() << " is not available" << std::endl;
		}
		if (std::find_if(this->cbegin(), this->cend(), fillerLambda) == this->cend()) { // check object for matching filler task
			os << iterator->getFiller() << " is not available" << std::endl;
		}
	}
}

void TaskManager::display(std::ostream & os) const {
	/*std::vector<Task> tasks;
	std::vector<Task>::iterator tasksIterator;

	for (tasksIterator = tasks.begin; tasksIterator != tasks.end; tasksIterator++) {
		tasksIterator->display(os);
	}*/

	std::vector<Task>::const_iterator taskIterator;
	for (taskIterator = this->cbegin(); taskIterator != this->cend(); taskIterator++) {
		taskIterator->display(os);
	}
}

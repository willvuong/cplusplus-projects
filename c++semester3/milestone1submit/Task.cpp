#include "Task.h"
#include "Utilities.h"
#include <iomanip>

size_t Task::field_width;

Task::Task(const std::string& record) {
	slots = "1";
	pNextTask[redirect] = nullptr;
	pNextTask[passed] = nullptr;

	Utilities utilitiesObj;
	std::string token;
	size_t position = 0;
	bool t = true;

	for (int i = 0; t; i++) {
		token = utilitiesObj.nextToken(record, position, t);
		if (!token.empty()) {
			if (i == 0) {
				name = token;
			}
			else if (i == 1) {
				if (t) {
					slots = token;
				}
			}
			else if (i == 2) {
				nextTask[passed] = token;
			}
			else if (i == 3) {
				nextTask[redirect] = token;
			}
			else {
				break;
			}
		}
		if (field_width < utilitiesObj.getFieldWidth()) {
			field_width = utilitiesObj.getFieldWidth();
		}
	}
}

bool Task::validate(const Task & task) {
	if (task.name == nextTask[passed]) {
		pNextTask[passed] = &task;
	}
	if (task.name == nextTask[redirect]) {
		pNextTask[redirect] = &task;
	}

	return ((nextTask[passed].empty() || pNextTask[passed]) && (nextTask[redirect].empty()) || pNextTask[redirect]);
}

const std::string & Task::getName() const {
	return name;
}

unsigned int Task::getSlots() const {
	return stoi(slots);
}

const Task * Task::getNextTask(Quality quality) const {
	if (!pNextTask[quality]) {
		throw "*** Validate  [" + nextTask[quality] + "] @ [" + name + "] ***";
	}
	return pNextTask[quality];
}

void Task::display(std::ostream & os) const {
	os << "Task Name    : " <<  "[" + name + "]" << "[" + slots + "]" << std::endl;
	if (pNextTask[passed] == nullptr && pNextTask[redirect] == nullptr)
	{
		if (!nextTask[passed].empty()) {
			os << "Countinue to : " << "[" + nextTask[passed] + "]  " << "*** to be validated ***" << std::endl;
			if (!nextTask[redirect].empty()) {
				os << " Redirect to : " << '[' + nextTask[redirect] + "]  " << "*** to be validated ***" << std::endl;
			}
		}
	}
	else {
		if (!nextTask[passed].empty()) {
			os << "Countinue to : " <<  "[" + nextTask[passed] + "]" << std::endl;
			if (!nextTask[redirect].empty()) {
				os << " Redirect to : " << '[' + nextTask[redirect] + "]" << std::endl;
			}
		}
	}


}

size_t Task::getFieldWidth() {
	return field_width;
}

bool operator==(const Task & task_a, const Task & task_b) {
	if (task_a.getName() == task_b.getName()) {
		return true;
	}
	else {
		return false;
	}
}

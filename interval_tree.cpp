#include "leetcode.h"

struct Interval {
	int low;
	int high;

	Interval(int l, int h) {
		low = l;
		high = h;
	}

	bool overlaps(Interval itv) {
		return this->low <= itv.high && itv.low <= this->high;
	}
};

class IntervalTree {
private:
	Interval interval = {0, 0};
	int max_left;
	IntervalTree* left = NULL;
	IntervalTree* right = NULL;
public:
	IntervalTree(Interval itv, int max_left);
	IntervalTree* insert(int low, int high);
	IntervalTree* insert(Interval itv);
	vector<IntervalTree*> searchOverlaps(Interval itv);
	IntervalTree* remove(Interval itv);
	IntervalTree* concat(IntervalTree* it);
	void inorder();
	void printInorder();
	void clean();
};

IntervalTree::IntervalTree(Interval itv, int max_left) {
	this->interval = itv;
	this->max_left = max_left;
}

void IntervalTree::printInorder() {
	cout << "Inorder traversal begins: " << endl;
	inorder();
}

void IntervalTree::inorder() {
	if (left)
		left->inorder();
	cout << "(" << interval.low << ", " << interval.high << ")" << endl;
	if (right)
		right->inorder();
}

IntervalTree* IntervalTree::concat(IntervalTree* it) {
	if (it->interval.low > interval.low) {
		if (right == NULL) {
			right = it;
			return this;
		}
		right = right->concat(it);
		return this;
	}
	else {
		if (left == NULL) {
			left = it;
			return this;
		}
		left = left->concat(it);
		return this;
	}
}

IntervalTree* IntervalTree::remove(Interval itv) {

	if (itv.low == interval.low && itv.high == interval.high) {
		if (left == NULL && right == NULL) {
			delete this;
			return NULL;
		}
		else if (left == NULL) {
			IntervalTree* r = right;
			delete this;
			return r;
		}
		else if (right == NULL) {
			IntervalTree* l = left;
			delete this;
			return l;
		}
		IntervalTree* t = left->concat(right);
		delete this;
		return t;
	}
	
	if (itv.low < interval.low) {
		if (left == NULL)
			return this;
		left = left->remove(itv);
		return this;
	}
	else if (itv.low > interval.low) {
		if (right == NULL)
			return this;
		right = right->remove(itv);
		return this;
	}

	return this;
}

IntervalTree* IntervalTree::insert(int low, int high) {
	Interval i(low, high);
	return insert(i);
}

IntervalTree* IntervalTree::insert(Interval itv) {
	if (itv.overlaps(this->interval)) {
		IntervalTree* it = remove(this->interval);
		// cout << "???" << endl;
		if (it == NULL)
			it = new IntervalTree(Interval(min(itv.low, interval.low), max(itv.high, interval.high)), max(itv.high, interval.high));
		else {
			it = it->insert(Interval(min(itv.low, interval.low), max(itv.high, interval.high)));
			it->max_left = max(itv.high, interval.high);
		}
		// cout << "???" << endl;
		
		return it;
	}

	if (itv.low < interval.low) {
		if (!left) {
			left = new IntervalTree(itv, itv.high);
			return this;
		}
		left = left->insert(itv);
		return this;
	}
	else {
		if (!right) {
			right = new IntervalTree(itv, itv.high);
			return this;
		}
		right = right->insert(itv);
		return this;
	}
		
}

void IntervalTree::clean() {
	if (left) {
		left->clean();
		delete left;
	}
		
	if (right) {
		right->clean();
		delete right;
	}
	
	return;
}

int main() {
	IntervalTree* root = new IntervalTree(Interval(0, 4), 4);
	root = root->insert(5, 7);
	root->printInorder();
	root = root->insert(0, 7);
	root->printInorder();
	root = root->insert(2, 10);
	root->printInorder();
	root = root->insert(100, 120);
	root->printInorder();
	root = root->insert(300, 400);
	root->printInorder();
	root->clean();
	delete root;

}
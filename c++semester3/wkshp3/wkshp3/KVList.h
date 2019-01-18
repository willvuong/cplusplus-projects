#ifndef _KVLIST_H_
#define _KVLIST_H_

#include <iostream>

template <typename K, typename V, int N>

class KVList {
	K k[N];
	V v[N];
private:
	int entries;
public:
	KVList() { entries = 0; }
	size_t size() const { return entries; }
	const K& key(int i) const { return k[i]; }
	const V& value(int i) const { return v[i]; }
	
	KVList& add(const K& tempK, const V& tempV) {
		if (entries < N) {
			k[entries] = tempK;
			v[entries] = tempV;
			entries++;
		}
		return *this;
	}

	int find(const K& tempK) const {
		for (int i = 0; i < entries; i++) {
			if (k[i] == tempK) {
				return i;
			}
		}
		return 0;
	}

	KVList& replace(int i, const K& tempK, const V& tempV) {
		k[i] = tempK;
		v[i] = tempV;
		return *this;
	}
};

#endif // !_KVLISH_H_
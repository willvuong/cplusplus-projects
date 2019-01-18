#ifndef _W8_DATA_TABLE_H_
#define _W8_DATA_TABLE_H_

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

namespace w8 {
	template<typename T>
	class DataTable {
	private:
		int fieldWidth;
		int numOfDecimals;
		vector<T> x;
		vector<T> y;
		T yAccumulate;
		T xAccumulate;
	public:
		DataTable(ifstream& fs, int TEMPfieldWidth, int TEMPnumOfDecimals) {
			T tempX, tempY;
			while (fs.is_open() && !fs.eof()) {
				fs >> tempX;
				x.push_back(tempX);
				fs >> tempY;
				y.push_back(tempY);
				
			}
			yAccumulate = accumulate(y.begin(), y.end(), 0.0);
			xAccumulate = accumulate(x.begin(), x.end(), 0.0);
			fieldWidth = TEMPfieldWidth;
			numOfDecimals = TEMPnumOfDecimals;	
		}

		T mean() const {
			return yAccumulate / y.size();
		}

		T sigma() const {
			T sum = 0;
			for (int i = 0; i < y.size(); i++) {
				sum += (y.at(i) - mean()) * (y.at(i) - mean());
			}
			return sqrt(static_cast<double>(sum / (y.size() - 1)));
		}

		T median() const {
			vector<T> yTemp = y;
			sort(yTemp.begin(), yTemp.end());
			T size = y.size();
			return yTemp[size / 2];
		}

		void regression(T& slope, T& y_intercept) const {
			T xyTotal = inner_product(x.begin(), x.end(), y.begin(), (T)0);
			T xTotal = inner_product(x.begin(), x.end(), x.begin(), (T)0);
			T ySize = y.size();
			slope = (ySize * xyTotal - xAccumulate * yAccumulate) / (ySize * xTotal - xAccumulate * xAccumulate);
			y_intercept = (yAccumulate - slope * xAccumulate) / ySize;
		}

		void display(std::ostream&os) const {
			os << setw(fieldWidth) << 'X';
			os << setw(fieldWidth) << 'Y' << endl;
			for (int i = 0; i < x.size(); i++) {
				os << setw(fieldWidth) << fixed << setprecision(numOfDecimals) << x[i] << 
					setw(fieldWidth) << fixed << setprecision(numOfDecimals) << y[i] << endl;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const DataTable& dt) {
			dt.display(os);
			return os;
		}

	};
}

#endif // !_W8_DATA_TABLE_H_
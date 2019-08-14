#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		char chesspiece;
		int m;
		int n;
		cin >> chesspiece >> m >> n;
		switch (chesspiece) {
		case 'r':
			cout << min(m, n) << '\n';
			break;
		case 'k':
			cout << ceil((float)m / 2) * ceil((float)n / 2) + floor((float)m / 2) * floor((float)n / 2) << '\n';
			break;
		case 'Q':
			cout << min(m, n) << '\n';
			break;
		case 'K':
			cout << ceil((float)m / 2) * ceil((float)n / 2) << '\n';
			break;
		}
	}
}

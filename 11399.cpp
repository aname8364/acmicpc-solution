#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::int_fast32_t N;
	std::cin >> N;

	std::vector<std::int_fast32_t> vec;
	vec.reserve(N);

	while (N--) {
		int_fast32_t x;
		std::cin >> x;
		vec.push_back(x);
	}

	std::sort(vec.begin(), vec.end());

	int_fast32_t total = 0;
	int_fast32_t value = 0;
	std::for_each(vec.begin(), vec.end(), [&total, &value]
	(const auto& v) {
			value += v;
			total += value;
		});

	std::cout << total;
}
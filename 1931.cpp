#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::int_fast32_t N;
	std::cin >> N;

	std::vector<std::pair<std::int_fast32_t, std::int_fast32_t>> vec;
	vec.reserve(N);

	while (N--) {
		std::int_fast32_t start, end;
		std::cin >> start >> end;
		vec.emplace_back(std::pair<std::int_fast32_t, std::int_fast32_t>{ start, end });
	}

	std::sort(vec.begin(), vec.end(), [](const auto& x, const auto& y) {
		if (x.second != y.second) { return x.second < y.second; }
		return x.first < y.first;
		});

	std::int_fast32_t last_end = 0;
	std::int_fast32_t count = 0;

	std::for_each(vec.begin(), vec.end(), [&count, &last_end](const auto& v) {
		auto current_start = v.first;
		auto current_end = v.second;
		if (last_end <= current_start) {
			++count;
			last_end = current_end;
		}
		});

	std::cout << count;
}
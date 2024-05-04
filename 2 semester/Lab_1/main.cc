#include <iostream>
#include <cmath>
#include <functional>

int sequence_sum(int value, int step, int n) {
    return n * (2 * value + step * (n - 1)) / 2;
}

int dif_h(int y, int m, int n) {
    int top = sequence_sum(1, 1, m * (y - 1));
    int amount = sequence_sum(1, 1, m * n);
    int bottom = amount - top;
    return top - bottom;
}

int dif_v(int x, int m, int n) {
    int amount = sequence_sum(1, 1, m * n);
    int left = n * sequence_sum(0, 1, x - 1) + (x - 1) * sequence_sum(1, m, n);
    int right = amount - left;
    return left - right;
}

std::pair<int, int> binsearch(int left, int right, std::function<int(int)> diff) {
    while (left < right) {
        if ((right - left) <= 1) {
            int diff_left = diff(left);
            int diff_right = diff(right);
            if (std::abs(diff_left) < std::abs(diff_right)) {
                return std::make_pair(diff_left, left);
            }
            else {
                return std::make_pair(diff_right, right);
            }
        }
        int mid = (left + right) / 2;
        int dmid = diff(mid);
        if (dmid < 0) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;

        auto result_v = binsearch(1, m, [&](int x) { return dif_v(x, m, n); });
        auto result_h = binsearch(1, n, [&](int y) { return dif_h(y, m, n); });

        if (std::abs(result_h.first) < std::abs(result_v.first)) {
            std::cout << "H " << result_h.second << std::endl;
        }
        else {
            std::cout << "V " << result_v.second << std::endl;
        }
    }

    return 0;
}

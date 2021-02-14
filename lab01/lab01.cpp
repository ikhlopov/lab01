#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    vector<double> numbers(number_count);
    cerr << "Enter numbers: ";
    for (int i = 0; i < number_count; i++) cin >> numbers[i];

    size_t bin_count;
    cerr << "Enter number bins: ";
    cin >> bin_count;

    vector<size_t> bins(bin_count);

    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }

    double bin_size = (max - min) / bin_count;
    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }

    size_t max_bin = bins[0];
    for (size_t x : bins) {
        if (x > max_bin) {
            max_bin = x;
        }
    }

    size_t height;
    for (int i = 0; i < bin_count; i++) {
        cout << bins[i] << "|";
        for (int j = 0; j < bins[i]; j++) cout << "*";
        cout << endl;
    }
} // каво



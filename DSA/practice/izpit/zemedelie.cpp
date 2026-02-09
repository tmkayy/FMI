// Faculty_number: 
#include <bits/stdc++.h>
using namespace std;

struct Property {
    int idx;
    double diameter;
    double price;
    double pricePerSqM;
    double sqM;

    Property(int i, double d, double p) {
        idx = i; diameter = d; price = p; sqM = (diameter / 2) * (diameter / 2);  pricePerSqM = price / sqM;
    }

    const bool operator<(const Property& other) {
        if (pricePerSqM == other.pricePerSqM) {
            return sqM > other.sqM;
        }
        return pricePerSqM < other.pricePerSqM;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    vector<Property> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        double d, p;
        cin >> d >> p;
        v.emplace_back(Property(i + 1, d, p));
    }
    sort(v.begin(), v.end());
    for (auto& el : v) {
        cout << el.idx << ' ';
    }
    return 0;
}
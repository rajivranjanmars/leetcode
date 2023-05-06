class Solution {
public:
    string intToRoman(int num) {
          map<int, string> romanTable = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string result = "";
        for (auto it = romanTable.rbegin(); it != romanTable.rend(); ++it) {
            while (num >= it->first) {
                num -= it->first;
                result += it->second;
            }
        }
        return result;
    }
};
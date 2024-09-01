// 273. Integer to English Words

// Solution 1: using map
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    unordered_map<int, string> ones = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}
    };

    unordered_map<int, string> tens = {
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
        {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };

    unordered_map<int, string> hundreds = {
        {100, "Hundred"}
    };

    string helper(int num) {
        if (num == 0) return "";
        string result;
        if (num >= 100) {
            result += ones[num / 100] + " " + hundreds[100];
            num %= 100;
            if (num > 0) result += " ";
        }
        if (num >= 20) {
            result += tens[num / 10 * 10];
            num %= 10;
            if (num > 0) result += " ";
        }
        if (num > 0) {
            result += ones[num];
        }
        return result;
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result;
        if (num / 1000000000 > 0) {
            result += helper(num / 1000000000) + " Billion";
            num %= 1000000000;
            if (num > 0) result += " ";
        }
        if (num / 1000000 > 0) {
            result += helper(num / 1000000) + " Million";
            num %= 1000000;
            if (num > 0) result += " ";
        }
        if (num / 1000 > 0) {
            result += helper(num / 1000) + " Thousand";
            num %= 1000;
            if (num > 0) result += " ";
        }
        if (num > 0) {
            result += helper(num);
        }
        return result;
    }
};

// Solution 2: using vector
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    const vector<string> ones = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };

    const vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int num) {
        if (num == 0) return "";
        string result;
        if (num >= 100) {
            result += ones[num / 100] + " " + "Hundred";
            num %= 100;
            if (num > 0) result += " ";
        }
        if (num >= 20) {
            result += tens[num/10];
            num %= 10;
            if (num > 0) result += " ";
        }
        if (num > 0) {
            result += ones[num];
        }
        return result;
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result;
        if (num / 1000000000 > 0) {
            result += helper(num / 1000000000) + " Billion";
            num %= 1000000000;
            if (num > 0) result += " ";
        }
        if (num / 1000000 > 0) {
            result += helper(num / 1000000) + " Million";
            num %= 1000000;
            if (num > 0) result += " ";
        }
        if (num / 1000 > 0) {
            result += helper(num / 1000) + " Thousand";
            num %= 1000;
            if (num > 0) result += " ";
        }
        if (num > 0) {
            result += helper(num);
        }
        return result;
    }
};
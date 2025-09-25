// 3484. Design Spreadsheet

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */


// Solution 1: Easy and Straight forward using Matrix and String Operations
// Time Complexity: O(1)
// Space Complexity: O(26*n) = O(n), where n is the number of rows in the spreadsheet
class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.resize(26);
        for(int i = 0; i < 26;i++) sheet[i].resize(rows, 0);
    }

    tuple<int,int> getCellCoordinates(string cell){
        int r = cell[0] - 'A', c = stoi(cell.substr(1)) - 1;
        return {r,c};
    }
    
    void setCell(string cell, int value) {
        auto [x, y] = getCellCoordinates(cell);
        sheet[x][y] = value;
    }

    int getCell(string cell){
        auto [x, y] = getCellCoordinates(cell);
        return sheet[x][y];
    }

    bool isCell(string op){
        return ('A' <= op[0] && op[0] <= 'Z');
    }
    
    void resetCell(string cell) {
        auto [x, y] = getCellCoordinates(cell);
        sheet[x][y] = 0;
    }
    
    int getValue(string formula) {
        int pos = formula.find("+");
        string op1 = formula.substr(1, pos), op2 = formula.substr(pos+1);
        int res = 0;
        res += (isCell(op1) ? getCell(op1) : stoi(op1));
        res += (isCell(op2) ? getCell(op2) : stoi(op2));
        return res;
    }
};

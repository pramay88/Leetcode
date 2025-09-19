class Spreadsheet {
    vector<vector<int>> grid;
    pair<int, int> parseCell(const string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }
public:
    Spreadsheet(int rows) {
        grid.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        if (formula[0] == '=') formula = formula.substr(1);

        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1, val2;

        if (isdigit(left[0])) val1 = stoi(left);
        else{
            auto [row, col] = parseCell(left);
            val1 = grid[row][col];
        }

        if (isdigit(right[0])) val2 = stoi(right);
        else {
            auto [row, col] = parseCell(right);
            val2 = grid[row][col];
        }
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
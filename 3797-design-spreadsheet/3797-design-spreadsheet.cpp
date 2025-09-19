class Spreadsheet {
public:
    map<char , map<int,int>> sheet ; 
    Spreadsheet(int rows) {
        sheet.clear() ;  
    }
    pair<char,int> extractCellInfo(string s) {
        pair<char,int> currCell = {'a' , 0} ; 
        currCell.first = s[0] ; 

        currCell.second = stoi(s.substr(1 , s.length() - 1)) ;

        return currCell ;  
    }
    void setCell(string cell, int value) {
        pair<char,int> currentCell = extractCellInfo(cell) ; 
        sheet[currentCell.first][currentCell.second] = value ; 
    }
    
    void resetCell(string cell) {
        pair<char,int> currentCell = extractCellInfo(cell) ; 

        sheet[currentCell.first][currentCell.second] = 0 ; 
    }
    int decrypt(string s) {
        int value = 0 ; 
        if (s[0] >= 'A' && s[0] <= 'Z'){
            pair<char,int> currentCell = extractCellInfo(s) ; 
            value = sheet[currentCell.first][currentCell.second] ; 
        }else {
            value = stoi(s) ; 
        }
        return value ; 
    }
    int getValue(string s) {
        s = s.substr(1 , s.length() - 1) ; 
        string one = "" , two = "" ; 
        int i = 0 ; 
        while (s[i] != '+'){
            one.push_back(s[i++]) ; 
        }
        i++ ; 
        while (i < s.length()) {
            two.push_back(s[i++]) ;
        }

        return decrypt(one) + decrypt(two) ; 

    }
















};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
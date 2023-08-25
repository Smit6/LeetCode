class SQL {
public:
    SQL(vector<string>&, vector<int>&);
    void insertRow(string, vector<string>);
    void deleteRow(string, int);
    string selectCell(string, int, int);
private:
    unordered_map<string, int> name2id;
    unordered_map<string, unordered_map<int, vector<string>>> tables;
};


SQL::SQL(vector<string>& names, vector<int>& columns) {
    for (int i = 0; i < names.size(); i++)
        name2id[names[i]] = 0;
}

void SQL::insertRow(string name, vector<string> row) {
    tables[name][++name2id[name]] = row;
}

void SQL::deleteRow(string name, int rowId) {
    tables[name].erase(rowId);
}

string SQL::selectCell(string name, int rowId, int columnId) {
    return tables[name][rowId][columnId - 1];
}

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
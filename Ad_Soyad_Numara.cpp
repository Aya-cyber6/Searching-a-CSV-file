#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

void HashSearch(const string& book, unordered_map<string, vector<string>>& myMap) {
    auto it = myMap.find(book);
    if (it != myMap.end()) {
        cout << book << " Found" << endl;
        cout << "Book info: ";
        for (const string& value : it->second) {
            cout << value << " ";
        }
        cout << endl;
    } else {
        cout << "Author not found" << endl;
    }
}




int main() {
    // Open the file
    ifstream file("tr_books.csv");
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Define an unordered map to store the file contents
    unordered_map<string, vector<string>> Map;

    // Read the file line by line
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string key;
        vector<string> values;

        // Parse the line into key and values
        getline(ss, key, ',');
        string value;
        while (getline(ss, value, ',')) {
            values.push_back(value);
        }

        // Insert the key and values into the unordered map
       Map[key] = values;
    }
    
    // Close the file
    file.close();
    string BookName;
    cout << "Enter book name to be searched: "<< endl;
    cin >> BookName;
    string book = "\"" + BookName + "\"";
    HashSearch(book, Map);
    
    return 0;
}

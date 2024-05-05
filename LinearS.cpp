#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int linearSearch(const string& book, map<string, vector<string>>& myMap) {
    for ( auto pair: myMap) {
        if (pair.first == book) {
            cout << book << " Found" <<endl;
            cout << "Book info: " ;
             for (const string& value : pair.second) {
               cout << value << " ";
             } 
             return 0; // Book found, return 0 to indicate success
        }
    }
    // If we reach here, it means the book was not found
    cout << "Not Found";
    return -1; // Return -1 to indicate failure
}

int main() {

    ifstream file("tr_books.csv");
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Define a map to store the file contents
    map<string, vector<string>> Map;

    // Read the file line by line
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string bookName;
        vector<string> bookInfo;

        // Parse the line into key and values
        getline(ss, bookName, ',');
        string bookTrait;
        while (getline(ss, bookTrait, ',')) {
            bookInfo.push_back(bookTrait);
        }

        // Insert the key and values into the map
       Map[bookName] = bookInfo;
    }
    
    // Close the file
    file.close();
    string BookName;
    cout << "Enter book name to be searched: "<< endl;
    cin >> BookName;
    string book = "\"" + BookName + "\"";

    linearSearch(book, Map);

    return 0;
}

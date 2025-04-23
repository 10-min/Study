#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

class hrmlAnalyzer {  
    public:

    map<string, string> tagMap;
    stack<string> tag;

    int haveAttribute = 0;

    string hrmlRow;
    string attributeString;

    int currentIndex = 0;
    int tagNameEndIndex, tagAttributeEndIndex, tagValueIndex, tagValueEndIndex;

    void pushTagValue(string attribute, string value) {
        tagMap[attribute] = value;
    }


    void storeTag() {
        string tagName;

        int currentIndex = 1;
        int tagNameEndIndex = hrmlRow.find(' ', currentIndex);

        if (tagNameEndIndex != hrmlRow.npos) {
            haveAttribute = 1;
        }

        if (haveAttribute) {
            tagName = hrmlRow.substr(currentIndex, tagNameEndIndex - currentIndex);

            attributeString = hrmlRow.substr(tagNameEndIndex + 1, hrmlRow.length() - (tagNameEndIndex + 1));
        } else {
            tagName = hrmlRow.substr(currentIndex, hrmlRow.length()-1 - currentIndex);
        }

        if (tag.empty()) {
            tag.push(tagName);
        } else {
            tag.push(tag.top() + '.' + tagName);
        }
    }

    string getAttribute(string attributeString) {
        string attribute;

        int tagAttributeEndIndex = attributeString.find(' ');
        attribute = attributeString.substr(0, tagAttributeEndIndex);
       
        return attribute;
    }
    
    string getValue(string attributeString) {
        string value;

        tagValueIndex = attributeString.find('\"') + 1;
        tagValueEndIndex = attributeString.find('\"', tagValueIndex);
        value = attributeString.substr(tagValueIndex, tagValueEndIndex-tagValueIndex);

        return value;
    }

    void storeAttribute() {
        string attribute, value;
        currentIndex = 0;
        
        string temp = attributeString;
        while(haveAttribute) {
            attribute = getAttribute(temp);
            value = getValue(temp);
            
            pushTagValue(tag.top() + '~' + attribute, value);
            
            currentIndex = tagValueEndIndex + 1;
            if (temp.find(' ', currentIndex) == temp.npos) {
                haveAttribute = 0;
            } else {
                currentIndex++;
                temp = temp.substr(currentIndex, temp.length() - currentIndex);
            }

        }
    }


};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    vector<string> hrml(N);
    vector<string> query(Q);

    for (int i = 0; i < N; i++) {
        getline(cin, hrml[i]);
    }
    for  (int i = 0; i < Q; i++) {
        getline(cin, query[i]);
    }

    hrmlAnalyzer analyzer;
    
    for (int i = 0; i < N; i++) {
        int currentIndex = 1;
        analyzer.hrmlRow = hrml[i];
        if (analyzer.hrmlRow[1] == '/') {
            analyzer.tag.pop();
        } else {
            analyzer.storeTag();
            analyzer.storeAttribute();
        }
    }

    for (int i = 0; i < Q; i++) {
        string temp = query[i];

        if (analyzer.tagMap.find(temp) == analyzer.tagMap.end()) {
            cout << "Not Found!" << endl;
        } else {
            cout << analyzer.tagMap[temp] << endl;
        }
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper function to compare pairs by frequency (descending order)
bool compareFrequency(const pair<char, double>& a, const pair<char, double>& b){
    return a.second > b.second;
}

string decText(const string& text, const vector<char>& tableText){
    map<char, int> letterCounts;
    int totalLetters = 0;
    
    //Step 1
    // Initialize the map with all letters a-z
    for (char letter = 'a'; letter <= 'z'; ++letter){
        letterCounts[letter] = 0;
    }

    // Count the occurrences of each letter
    for (char letter : text) {
        if (isalpha(letter)) {
            letter = tolower(letter);
            letterCounts[letter]++;
            totalLetters++;
        }
    }

    // Calculate the relative frequency of each letter
    vector<pair<char, double>> frequencies;
    for (char letter = 'a'; letter <= 'z'; ++letter){
        double frequency = static_cast<double>(letterCounts[letter]) / totalLetters;
        frequencies.push_back({letter, frequency});
    }

    // Step 2
    // Sort the frequencies in descending order
    sort(frequencies.begin(), frequencies.end(), compareFrequency);



    // Save the sorted letters to an array
    char sortedLetters[26];
    for (int i = 0; i < 26; ++i){
        sortedLetters[i] = frequencies[i].first;
    }

    ///////////DEBUG///////////
    cout << "\nSorted letters based on frequency\n";
    for(char c : sortedLetters){
        cout << c << " ";
    }
    cout << endl;
    
    // Print the sorted letters and their frequencies
    cout << "\nSorted letters frequency\n";
    for (const auto& pair : frequencies){
        cout << pair.first << ": " << pair.second << " " <<"\n";
    }
    cout << endl;

    //Step 3
    // Create substitution map
    map<char, char> substitutionMap;

    for(int i = 0; i < 26; ++i){
        substitutionMap[sortedLetters[i]] = tableText[i];
    }

    ///////////DEBUG///////////
    cout << "\n[Before correction]Substitution Map\n";
    for(auto it = substitutionMap.cbegin(); it != substitutionMap.cend(); ++it){
        cout << it->first << " : " << it->second << " " << "\t";
    }
    cout << endl;
    cout << endl;

    //Step 4
    //Correct the map
    substitutionMap['l'] = 'b';
    substitutionMap['n'] = 'u';
    substitutionMap['j'] = 'o';
    substitutionMap['x'] = 'f';
    substitutionMap['q'] = 'k';
    substitutionMap['s'] = 'p';
    substitutionMap['t'] = 'y';
    substitutionMap['w'] = 'i';
    substitutionMap['k'] = 'n';
    substitutionMap['o'] = 'g';
    substitutionMap['b'] = 't';
    substitutionMap['a'] = 'x';
    substitutionMap['e'] = 'v';
    substitutionMap['g'] = 'z';
    substitutionMap['c'] = 'w';
    substitutionMap['f'] = 'q';
    substitutionMap['z'] = 'j';
    
    //////////DEBUG///////////
    cout << "\nSubstitution Map after correction\n";
    for(auto it = substitutionMap.cbegin(); it != substitutionMap.cend(); ++it){
        cout << it->first << " : " << it->second << " " << "\t";
    }
    cout << endl;
    cout << endl;

    // Decrypt the text
    string plaintText;
    for(char letter : text){
        if (isalpha(letter)){
            plaintText += substitutionMap[letter];
        } else{
            plaintText += letter;
        }
        
    }
    
    cout << "Plainttext:" << endl;
    return plaintText;
}


int main(){
    //string tText = "e t a o i n s h r d l c u m w f g y p b v k j x q z";
    string eText = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi "
    "bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx "
    "ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr "
    "yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk "
    "lmird jk xjubt trmui jx ibndt "
    "            "
    "wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi "
    "iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m "
    "vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd "
    "wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr "
    "jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii "
    "ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh "
    "mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb "
    "bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd "
    "wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr "
    "riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb ";

    //Sorted table array
    vector<char> tableText = {
        'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd',
        'l', 'c', 'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b',
        'v', 'k', 'j', 'x', 'q', 'z'
    };

    cout << "\nSorted table array\n";
    for (char c : tableText){
        cout << c << " ";
    }
    cout << endl;
    
    //decrypt the text
    cout << decText(eText, tableText) << endl;

    return 0;
}

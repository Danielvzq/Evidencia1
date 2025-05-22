/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "transmission_utils.h"
#include "transmission_impl.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string transmission1 = readFileContent("transmission1.txt");
    string transmission2 = readFileContent("transmission2.txt");
    vector<string> mcodes = {
        readFileContent("mcode1.txt"),
        readFileContent("mcode2.txt"),
        readFileContent("mcode3.txt")
    };

    cout << "Parte 1:" << endl;

    for (int i = 0; i < 3; i++) {
        auto result1 = containsPattern(transmission1, mcodes[i]);
        if (result1.first)
            cout << "true " << result1.second << endl;
        else
            cout << "false" << endl;
    }

    for (int i = 0; i < 3; i++) {
        auto result2 = containsPattern(transmission2, mcodes[i]);
        if (result2.first)
            cout << "true " << result2.second << endl;
        else
            cout << "false" << endl;
    }

    cout << "Parte 2:" << endl;

    auto palindrome1 = longestPalindrome(transmission1);
    auto palindrome2 = longestPalindrome(transmission2);

    string palindrome1_text = transmission1.substr(palindrome1.first - 1, palindrome1.second - palindrome1.first + 1);
    palindrome1_text.erase(remove(palindrome1_text.begin(), palindrome1_text.end(), '\n'), palindrome1_text.end());
    cout << palindrome1.first << " " << palindrome1.second << " " << palindrome1_text << endl;

    string palindrome2_text = transmission2.substr(palindrome2.first - 1, palindrome2.second - palindrome2.first + 1);
    palindrome2_text.erase(remove(palindrome2_text.begin(), palindrome2_text.end(), '\n'), palindrome2_text.end());
    cout << palindrome2.first << " " << palindrome2.second << " " << palindrome2_text << endl;

    cout << "Parte 3:" << endl;

    auto commonSubstring = longestCommonSubstring(transmission1, transmission2);
    string commonSubstring_text = transmission1.substr(commonSubstring.first - 1, commonSubstring.second - commonSubstring.first + 1);
    commonSubstring_text.erase(remove(commonSubstring_text.begin(), commonSubstring_text.end(), '\n'), commonSubstring_text.end());
    cout << commonSubstring.first << " " << commonSubstring.second << " " << commonSubstring_text << endl;

    return 0;
}
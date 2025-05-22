/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef TRANSMISSION_UTILS_H
#define TRANSMISSION_UTILS_H

#include <string>
#include <utility>
#include <vector>

using namespace std;

string readFileContent(const string &filename);
pair<bool, size_t> containsPattern(const string &text, const string &pattern);
pair<int, int> longestPalindrome(const string &text);
pair<int, int> longestCommonSubstring(const string &text1, const string &text2);

#endif

#include "bits/stdc++.h"
#include "Attack.h"
#include "iostream"

#define pair_char_bool pair<char, bool> //instead of write it every time
using namespace std;

Attack::Attack(string ciphe) {
    cipher = ciphe;
    one_chars = count_1_char();
    tow_chars = count_2_chars();
}

pair<int, char> *Attack::count_1_char() {
    auto *result = new pair<int, char>[26];
    for (int i = 0; i < 26; i++) {
        result[i].first = 0;
        result[i].second = 'A' + i;
    }
    for (char ch: cipher) {
        result[ch - 'A'].first++;
    }
    sort(result, result + 26, [](const auto &x, const auto &y) { return x.first > y.first; });
    return result;
}

pair<int, char *> *Attack::count_2_chars() {
    auto result = new pair<int, char *>[26 * 26];
    for (int i = 0; i < 26 * 26; ++i) {
        result[i].first = 0;
        result[i].second = new char[3];
        result[i].second[0] = i / 26 + 'A';
        result[i].second[1] = i % 26 + 'A';
        result[i].second[2] = '\0';

    }
    for (int i = 0; i < cipher.length() - 1; i++) {
        result[(cipher[i] - 'A') * 26 + (cipher[i + 1] - 'A')].first++;
    }
    sort(result, result + 26 * 26, [](const auto &x, const auto &y) { return x.first > y.first; });
    return result;
}

string Attack::get_key() {
    key['E' - 'A'] = one_chars[0].second;
    choosed['E' - 'A'] = 1;
    key[0] = one_chars[1].second;
    choosed[0] = 1;
    get_char_from_conflicts('H', vector<pair_char_bool >{
            pair_char_bool('E', true)});

    get_char_from_conflicts('T', vector<pair_char_bool >{
            pair_char_bool('H', true),
            pair_char_bool('A', false)});
    get_char_from_conflicts('R', vector<pair_char_bool >{
            pair_char_bool('E', false),
            pair_char_bool('E', true),
            pair_char_bool('A', false)});
    get_char_from_conflicts('N', vector<pair_char_bool >{
            pair_char_bool('A', false),
            pair_char_bool('T', true),
            pair_char_bool('E', true)});
    get_char_from_conflicts('O', vector<pair_char_bool >{
            pair_char_bool('N', true),
            pair_char_bool('T', false),
            pair_char_bool('H', false)});

    get_char_from_conflicts('I', vector<pair_char_bool >{
            pair_char_bool('N', true),
            pair_char_bool('T', false),
            pair_char_bool('T', true),
            pair_char_bool('H', false),
            pair_char_bool('A', false)});

    get_char_from_conflicts('S', vector<pair_char_bool >{
            pair_char_bool('E', false),
            pair_char_bool('E', true),
            pair_char_bool('T', true),
            pair_char_bool('I', false),
            pair_char_bool('A', false)});
    get_char_from_conflicts('L', vector<pair_char_bool >{
            pair_char_bool('E', true),
            pair_char_bool('E', false),
            pair_char_bool('A', false),
            pair_char_bool('I', true)});

    get_char_from_conflicts('C', vector<pair_char_bool >{
            pair_char_bool('E', false),
            pair_char_bool('O', true),
            pair_char_bool('A', false),
            pair_char_bool('A', true),
            pair_char_bool('N', false),
            pair_char_bool('I', false),
            pair_char_bool('H', true)});

    get_char_from_conflicts('U', vector<pair_char_bool >{
            pair_char_bool('O', false),
            pair_char_bool('R', true),
            pair_char_bool('S', true),
            pair_char_bool('T', true),});

    get_char_from_conflicts('D', vector<pair_char_bool >{
            pair_char_bool('N', false),
            pair_char_bool('E', false),
            pair_char_bool('E', true),
            pair_char_bool('I', true)});

    get_char_from_conflicts('W', vector<pair_char_bool >{
            pair_char_bool('N', false),
            pair_char_bool('E', false)});

    get_char_from_conflicts('P', vector<pair_char_bool >{
            pair_char_bool('E', true),
            pair_char_bool('E', false)});

    return key;
}

char Attack::get_char_from_tows(char target, char twin, bool first) {
    for (int i = 0; i < cipher.length() - 1; ++i) {
        if (tow_chars[i].second[first ? 1 : 0] == key[twin - 'A']) {
            {
                if (choosed[tow_chars[i].second[first ? 0 : 1] - 'A'] != 1) {
                    // key[target - 'A'] = tow_chars[i].second[first ? 0 : 1];
                    return tow_chars[i].second[first ? 0 : 1];
                } else {
                    continue;
                }
            }
        }
        if (!tow_chars[i].first) { return 0; }
    }
}

char Attack::get_char_from_conflicts(char ch, vector<pair_char_bool > twins) {
    auto result = new pair<int, char>[26];
    for (int i = 0; i < 26; i++) {
        result[i].first = 0;
        result[i].second = 'A' + i;
    }
    for (pair_char_bool twin: twins) {
        result[get_char_from_tows(ch, twin.first, twin.second) - 'A'].first++;
    }
    sort(result, result + 26, [](const auto &x, const auto &y) { return x.first > y.first; });
    choosed[result[0].second - 'A'] = 1;
    key[ch - 'A'] = result[0].second;
    return result[0].second;
}

string Attack::decrypt() {
    string key_ = get_key(), result, inverse_key = "--------------------------";
    for (int i = 0; i < 26; i++) {
        inverse_key[key_[i] - 'A'] = i + 'A';
    }
    for (char i: cipher) {
        result += inverse_key[i - 'A'];
    }
    return result;
}

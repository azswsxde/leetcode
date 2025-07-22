class Solution {
public:
    bool isVowel(size_t ascii) {
        switch(ascii) {
            case 65:
            case 69:
            case 73:
            case 79:
            case 85:
            case 97:
            case 101:
            case 105:
            case 111:
            case 117:
                return true;
            default:
                return false;
        }
    }
    bool isValid(string word) {
        size_t word_len = word.length();
        if (word_len < 3)
            return false;
        bool vowel = false, consonant = false;
        for (size_t i = 0; i < word_len; i++) {
            // digits
            if (word[i] >= 48 && word[i] <= 57)
                continue;
            // english letters
            if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)) {
                if (!vowel) {
                    if (isVowel(word[i])) {
                        vowel = true;
                        continue;
                    }
                }

                if (!consonant) {
                    if (isVowel(word[i]) == false) {
                        consonant = true;
                        continue;
                    }
                }
            }
            else {
                return false;
            }
        }
        return (vowel && consonant);
    }
};
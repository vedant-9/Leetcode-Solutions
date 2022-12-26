// https://leetcode.com/problems/sorting-the-sentence

class Solution:
    def sortSentence(self, s: str) -> str:
        # split the string and sort the words based upon the last letter
        word_list = sorted(s.split(), key = lambda word: word[-1], reverse = False)
        return " ".join([word[:-1] for word in word_list])  # join the words, after removing the last letter ie., digit

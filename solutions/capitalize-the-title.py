// https://leetcode.com/problems/capitalize-the-title

class Solution:
    def capitalizeTitle(self, title: str) -> str:
	    return " ".join([word.lower() if len(word) < 3 else word.title() for word in title.split()])
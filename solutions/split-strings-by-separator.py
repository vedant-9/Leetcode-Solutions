class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for word in words:
            for s in word.split(separator):
                if s != "":
                    ans.append(s)
        return ans

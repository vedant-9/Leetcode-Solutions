// https://leetcode.com/problems/find-duplicate-file-in-system

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        fileDict = dict()
        for path in paths:
            s = path.split()
            # print(s)
            dirName, files = s[0], s[1:]
            for x in files:
                fileName, fileContent = x.split("(")
                fileContent = fileContent[:-1]
                # print(fileName, fileContent)
                if fileContent not in fileDict:
                    fileDict[fileContent] = list()
                fileDict[fileContent].append(dirName + "/" + fileName)
                
        ans = []
        for keys in fileDict:
            l = fileDict[keys]
            if(len(l))>1:
                ans.append(l)
        return ans
        
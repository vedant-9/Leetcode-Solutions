class Solution {
public:
    int scoreOfParentheses(string s) {
        // 1st Approach - Break into balanced subproblems, recurse.
        // 2nd Approach - Stack holds the score of each open scope.
        // 3rd Approach - Only "()" scores; a "()" at depth d is worth 2^d.

        // ---- 2nd Approach: stack of scores ----
        // One stack slot per open "(", holding the score built inside it.
        stack<int> scores;
        scores.push(0);  // outermost scope, collects the final answer

        for (char c : s) {
            if (c == '(') {
                scores.push(0);  // entering a scope: start it at 0
            } else {
                // closing a scope: fold its score into the parent
                int inner = scores.top(); scores.pop();
                int outer = scores.top(); scores.pop();
                // inner == 0 means nothing was inside, so this is a bare
                // "()" worth 1; otherwise wrapping it in parens doubles it.
                scores.push(outer + max(2 * inner, 1));
            }
        }

        return scores.top();
    }

    // ---- 1st Approach: divide into balanced segments, recurse ----
    // A string is a sequence of top-level balanced pieces, e.g. "()(())"
    // is "()" then "(())". Score each piece and add them: a bare "()" is 1,
    // and "(X)" is 2 * score(X). `depth` returning to 0 marks a piece's end.
    //
    // int scoreOfParentheses(string s) {
    //     return score(s, 0, s.size());
    // }
    //
    // int score(const string& s, int i, int j) {
    //     int total = 0, depth = 0, start = i;
    //     for (int k = i; k < j; k++) {
    //         depth += (s[k] == '(') ? 1 : -1;
    //         if (depth == 0) {                   // s[start..k] is one piece
    //             if (k == start + 1) total += 1;             // bare "()"
    //             else total += 2 * score(s, start + 1, k);   // "(X)"
    //             start = k + 1;                  // next piece begins after k
    //         }
    //     }
    //     return total;
    // }

    // ---- 3rd Approach: count depth, O(1) space ----
    // Every doubling comes from nesting, so a "()" sitting under d layers of
    // parens is worth 2^d on its own (e.g. the "()" in "(())" is at depth 1,
    // worth 2^1 = 2). Sum 2^depth over just the bare "()" pairs and the
    // doublings take care of themselves. No stack needed, only the depth.
    //
    // int scoreOfParentheses(string s) {
    //     int total = 0, depth = 0;
    //     for (int i = 0; i < (int)s.size(); i++) {
    //         if (s[i] == '(') {
    //             depth++;
    //         } else {
    //             depth--;
    //             // a ")" right after a "(" closes a bare "()" at this depth
    //             if (s[i - 1] == '(') total += 1 << depth;
    //         }
    //     }
    //     return total;
    // }
};

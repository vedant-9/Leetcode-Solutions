/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let cnt = 0;
    return function() {
        return n+cnt++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

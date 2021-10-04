/* Problem 197. Rising Temperature
 * https://leetcode.com/submissions/detail/565375260/
 * 1. 문제:
 *   전 날에 비해 온도가 오른 날의 ID를 출력하여라.
 *
 * 2. 아이디어:
 *   self join
 * */
SELECT W1.ID
FROM WEATHER W1, WEATHER W2
WHERE W1.RECORDDATE = W2.RECORDDATE + 1
AND W1.TEMPERATURE > W2.TEMPERATURE;
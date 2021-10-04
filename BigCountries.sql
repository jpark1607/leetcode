/* Problem 595. Big Countries
 * https://leetcode.com/submissions/detail/565652686/
 * 1. 문제:
 *   면적이 300만보다 크거나 인구가 2500만보다 많은 국가의 인구와 면적을 출력하여라.
 *
 * 2. 아이디어:
 *   OR 조건(마땅히 쓸 게 없다)
 * */
SELECT NAME, POPULATION, AREA FROM WORLD
WHERE AREA > 3000000 OR POPULATION > 25000000;
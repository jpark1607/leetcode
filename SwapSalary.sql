/* Problem 627. Swap Salary
 * https://leetcode.com/submissions/detail/565656762/
 * 1. 문제:
 *   각 row의 성별을 바꾸어라.
 *
 * 2. 아이디어:
 *   decode 혹은 case when을 쓸 수 있다.
 *   2-1. SEX = DECODE(SEX, 'm', 'f', 'm')
 *   2-2. SEX = (CASE WHEN SEX = 'm' THEN 'f' ELSE 'm' END)
 * 3. 상세 코드:
 *   [A]
 *     [A-1]
 *   [B]
 * */
UPDATE SALARY
SET SEX = DECODE(SEX, 'm', 'f', 'm');